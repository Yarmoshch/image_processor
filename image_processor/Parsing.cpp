#include "Parsing.h"

Parser::Parser(int argc, char** argv) {
    argc_ = argc;

    for (int i = argc - 1; i > 0; --i) {
        argv_.push(argv[i]);
    }

    filters_map_["-blur"] = new Blur();
    filters_map_["-crop"] = new Crop();
    filters_map_["-edge"] = new EdgeDetection();
    filters_map_["-gs"] = new Grayscale();
    filters_map_["-neg"] = new Negative();
    filters_map_["-offc"] = new ColorOff();
    filters_map_["-sharp"] = new Sharpening();

    args_count_map_["-blur"] = 1;
    args_count_map_["-crop"] = 2;
    args_count_map_["-edge"] = 1;
    args_count_map_["-gs"] = 0;
    args_count_map_["-neg"] = 0;
    args_count_map_["-offc"] = 1;
    args_count_map_["-sharp"] = 0;
}

void Parser::Apply() {
    if (argc_ == 0) {
        Help();
    } else if (argc_ == 1) {
        throw std::runtime_error("There is no out file.");
    }

    Image image = BMP::Read(argv_.top());
    argv_.pop();

    char* output_file = argv_.top();
    argv_.pop();

    if (!argv_.empty()) {
        Parse(image);
    }

    BMP::Save(output_file, image);
}

void Parser::Parse(Image& image) {
    std::vector<std::string> parameters;
    char* filter_tag = argv_.top();
    argv_.pop();

    auto it = args_count_map_.find(filter_tag);
    if (it == args_count_map_.end()) {
        throw std::runtime_error("More args needed.");
    }

    int count = it->second;
    for (int i = 0; i < count; ++i) {
        parameters.push_back(argv_.top());
        argv_.pop();
    }

    filters_map_.find(filter_tag)->second->Apply(image, parameters);

    if (!argv_.empty()) {
        Parse(image);
    }
}

void Parser::Help() {
    std::cout << "-blur is  a filter that blurs an image, requiring 1 argument." << std::endl;
    std::cout << "-crop cuts your image to the specified size, requiring 2 arguments: width and height " << std::endl;
    std::cout << "-edge grayscales an image and applies a specific matrix to each pixel."
                 "It needs 1 argument from 0 to 1."
              << std::endl;
    std::cout << "-gs converts your image to grayscale with no arguments required." << std::endl;
    std::cout << "-neg converts your image to negative with no arguments required." << std::endl;
    std::cout << "-offc is a custom filter that disables one of the color channels, requiring 1 argument"
                 "'1' turns off red channel, '2' - green channel, '3' - blue channel"
              << std::endl;
    std::cout << "-sharp enhances the sharpness of your image with no arguments required." << std::endl;
}
Parser::~Parser() {
    for (auto& x : filters_map_) {
        delete (x.second);
    }
}

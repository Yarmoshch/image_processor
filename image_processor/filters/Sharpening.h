#pragma once
#include "../Image.h"
#include "../filter.h"

class Sharpening : public Filter {
public:
    Sharpening(){};
    ~Sharpening() override{};
    void Apply(Image& image, std::vector<std::string> parameters) override;
};
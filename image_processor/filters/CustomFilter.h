#pragma once
#include "../Image.h"
#include "../filter.h"

class ColorOff : public Filter {
public:
    ColorOff(){};
    ~ColorOff() override{};
    void Apply(Image& image, std::vector<std::string> parameters) override;
};

#pragma once
#include "../filter.h"
#include "../Image.h"

class Crop : public Filter {
public:
    Crop(){};
    ~Crop() override{};
    void Apply(Image& image, std::vector<std::string> parameters) override;
};
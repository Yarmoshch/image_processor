#pragma once
#include "../filter.h"
#include "../Image.h"

class Grayscale : public Filter {
public:
    Grayscale(){};
    ~Grayscale() override{};
    void Apply(Image& image, std::vector<std::string> parameters) override;
};
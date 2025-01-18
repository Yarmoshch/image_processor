#pragma once
#include "../Image.h"
#include "../filter.h"
#include "Grayscale.h"

class EdgeDetection : public Filter {
public:
    EdgeDetection(){};
    ~EdgeDetection() override{};
    void Apply(Image& image, std::vector<std::string> parameters) override;
};
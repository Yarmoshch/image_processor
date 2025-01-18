#pragma once
#include "../filter.h"
#include "../Image.h"

class Negative : public Filter {
public:
    Negative(){};
    ~Negative() override{};
    void Apply(Image& image, std::vector<std::string> parameters) override;
};
#pragma once
#include "vector"
#include "Image.h"
#include "string"

class Filter {
public:
    Filter(){};
    virtual ~Filter(){};
    virtual void Apply(Image& image, std::vector<std::string> parameters){};
};

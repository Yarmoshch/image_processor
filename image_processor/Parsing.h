#pragma once

#include "iostream"
#include "vector"
#include "stdexcept"
#include "map"
#include "stack"

#include "BMP.h"
#include "filter.h"
#include "filters/Blur.h"
#include "filters/Crop.h"
#include "filters/EdgeDetection.h"
#include "filters/Grayscale.h"
#include "filters/Negative.h"
#include "filters/Sharpening.h"
#include "filters/CustomFilter.h"

class Parser {
public:
    Parser(int argc, char** argv);

    void Apply();

    void Parse(Image& image);

    void Help();

    ~Parser();

private:
    int argc_;
    std::stack<char*> argv_;
    std::map<std::string, int> args_count_map_;
    std::map<std::string, Filter*> filters_map_;
};
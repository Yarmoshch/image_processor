#pragma once
#include <vector>
#include "RGB.h"

class Image {
private:
    int width_;
    int height_;
    int x_pixels_;
    int y_pixels_;
    std::vector<std::vector<RGB>> pixels_;

public:
    Image();
    Image(int width, int height);
    Image(int width, int height, std::vector<std::vector<RGB>> pixels);

    int GetXPixels() const;
    int GetYPixels() const;

    RGB GetRgb(int x, int y) const;
    void ChangePixel(RGB rgb, int x, int y);

    int Width() const;
    int Height() const;

    friend void SaveFile(const char* path, Image& image);

    void Read(const char* path);
};

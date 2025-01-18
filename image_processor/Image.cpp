#include "Image.h"

Image::Image() : width_(0), height_(0) {
}

Image::Image(int width, int height) : width_(width), height_(height), pixels_(height_, std::vector(width_, RGB())) {
}

Image::Image(int width, int height, std::vector<std::vector<RGB>> pixels)
    : width_(width), height_(height), pixels_(pixels) {
}

int Image::Width() const {
    return width_;
}

int Image::Height() const {
    return height_;
}

RGB Image::GetRgb(int x, int y) const {
    y = std::max(std::min(y, height_ - 1), 0);
    x = std::max(std::min(x, width_ - 1), 0);

    return pixels_[y][x];
}

void Image::ChangePixel(RGB rgb, int x, int y) {
    if (x < 0 || y < 0 || x > width_ - 1 || y > height_ - 1) {
        return;
    }

    pixels_[y][x] = rgb;
}

int Image::GetXPixels() const {
    return x_pixels_;
}

int Image::GetYPixels() const {
    return y_pixels_;
}
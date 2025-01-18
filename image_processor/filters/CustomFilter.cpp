#include "CustomFilter.h"

void ColorOff::Apply(Image& image, std::vector<std::string> parameters) {
    int lambda = std::stoi(parameters[0]);
    for (int x = 0; x < image.Width(); ++x) {
        for (int y = 0; y < image.Height(); ++y) {
            if (lambda % 3 == 1) {
                float r = 0;                      // NOLINT
                float g = image.GetRgb(x, y).g_;  // NOLINT
                float b = image.GetRgb(x, y).b_;  // NOLINT
                image.ChangePixel(RGB(r, g, b), x, y);
            }
            if (lambda % 3 == 2) {
                float r = image.GetRgb(x, y).r_;  // NOLINT
                float g = 0;                      // NOLINT
                float b = image.GetRgb(x, y).b_;  // NOLINT
                image.ChangePixel(RGB(r, g, b), x, y);
            }
            if (lambda % 3 == 0) {
                float r = image.GetRgb(x, y).r_;  // NOLINT
                float g = image.GetRgb(x, y).g_;  // NOLINT
                float b = 0;                      // NOLINT
                image.ChangePixel(RGB(r, g, b), x, y);
            }
        }
    }
}
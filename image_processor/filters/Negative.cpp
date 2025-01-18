#include "Negative.h"

void Negative::Apply(Image& image, std::vector<std::string> parameters) {
    for (int x = 0; x < image.Width(); ++x) {
        for (int y = 0; y < image.Height(); ++y) {
            float r = 1 - image.GetRgb(x, y).r_;  // NOLINT
            float g = 1 - image.GetRgb(x, y).g_;  // NOLINT
            float b = 1 - image.GetRgb(x, y).b_;  // NOLINT
            image.ChangePixel(RGB(r, g, b), x, y);
        }
    }
}

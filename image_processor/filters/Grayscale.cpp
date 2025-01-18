#include "Grayscale.h"

void Grayscale::Apply(Image& image, std::vector<std::string> parameters) {
    const float a = 0.299;
    const float n = 0.587;
    const float c = 0.114;
    for (int x = 0; x < image.Width(); ++x) {
        for (int y = 0; y < image.Height(); ++y) {
            float r = image.GetRgb(x, y).r_ * a + image.GetRgb(x, y).g_ * n + image.GetRgb(x, y).b_ * c;  // NOLINT
            float g = image.GetRgb(x, y).r_ * a + image.GetRgb(x, y).g_ * n + image.GetRgb(x, y).b_ * c;  // NOLINT
            float b = image.GetRgb(x, y).r_ * a + image.GetRgb(x, y).g_ * n + image.GetRgb(x, y).b_ * c;  // NOLINT

            image.ChangePixel(RGB(r, g, b), x, y);
        }
    }
}
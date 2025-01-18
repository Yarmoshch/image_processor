#include "Sharpening.h"

void Sharpening::Apply(Image &image, std::vector<std::string> parameters) {
    int width = image.Width();
    int height = image.Height();
    Image new_im(width, height);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            float r_pxl = (-1) * image.GetRgb(i, j + 1).r_ + (-1) * image.GetRgb(i - 1, j).r_ +
                          (-1) * image.GetRgb(i + 1, j).r_ + (-1) * image.GetRgb(i, j - 1).r_ +
                          5 * image.GetRgb(i, j).r_;  // NOLINT
            float g_pxl = (-1) * image.GetRgb(i, j + 1).g_ + (-1) * image.GetRgb(i - 1, j).g_ +
                          (-1) * image.GetRgb(i + 1, j).g_ + (-1) * image.GetRgb(i, j - 1).g_ +
                          5 * image.GetRgb(i, j).g_;  // NOLINT
            float b_pxl = (-1) * image.GetRgb(i, j + 1).b_ + (-1) * image.GetRgb(i - 1, j).b_ +
                          (-1) * image.GetRgb(i + 1, j).b_ + (-1) * image.GetRgb(i, j - 1).b_ +
                          5 * image.GetRgb(i, j).b_;  // NOLINT

            r_pxl = std::max(std::min(r_pxl, 1.0f), 0.0f);
            g_pxl = std::max(std::min(g_pxl, 1.0f), 0.0f);
            b_pxl = std::max(std::min(b_pxl, 1.0f), 0.0f);

            new_im.ChangePixel(RGB(r_pxl, g_pxl, b_pxl), i, j);
        }
    }
    image = new_im;
}
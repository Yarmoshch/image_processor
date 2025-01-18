#include "EdgeDetection.h"

void EdgeDetection::Apply(Image &image, std::vector<std::string> parameters) {
    float edge = 0;
    edge = std::stof(parameters[0]);
    Grayscale gs;
    gs.Apply(image, {});
    Image new_im(image.Width(), image.Height());

    for (int i = 0; i < image.Width(); ++i) {
        for (int j = 0; j < image.Height(); ++j) {
            float pxl = (-1.0f) * image.GetRgb(i, j + 1).r_ + (-1.0f) * image.GetRgb(i - 1, j).r_ +
                        (-1.0f) * image.GetRgb(i + 1, j).r_ + (-1.0f) * image.GetRgb(i, j - 1).r_ +
                        4.0f * image.GetRgb(i, j).r_;  // NOLINT

            pxl = (pxl > edge) ? 1.0f : 0.0f;
            new_im.ChangePixel(RGB(pxl, pxl, pxl), i, j);
        }
    }
    image = new_im;
}
#include "Blur.h"

void BlurDir(Image &image, float sigma, bool dir) {
    Image new_im(image.Width(), image.Height());
    float m = 1.0f / (sigma * std::sqrt(2 * M_PI));  // NOLINT
    float n = expf(-1.0f / (2 * powf(sigma, 2)));    // NOLINT
    for (int x = 0; x < image.Width(); ++x) {
        for (int y = 0; y < image.Height(); ++y) {
            float r = 0.0f;
            float g = 0.0f;
            float b = 0.0f;
            for (int z = static_cast<int>(-3 * sigma); z < static_cast<int>(3 * sigma); ++z) {
                float eq = m * powf(n, static_cast<float>(pow(z, 2)));
                RGB pxl;
                if (dir) {
                    pxl = image.GetRgb(x + z, y);
                } else {
                    pxl = image.GetRgb(x, y + z);
                }
                r += pxl.r_ * eq;
                g += pxl.g_ * eq;
                b += pxl.b_ * eq;
            }
            new_im.ChangePixel(RGB(r, g, b), x, y);
        }
    }
    image = new_im;
}

void Blur::Apply(Image &image, std::vector<std::string> parameters) {
    float sigma = 0;
    try {
        sigma = std::stof(parameters[0]);
    } catch (const std::exception &) {
        throw std::runtime_error("Incorrect sigma type.");
    }
    BlurDir(image, sigma, true);
    BlurDir(image, sigma, false);
}
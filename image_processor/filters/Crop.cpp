#include "Crop.h"

void Crop::Apply(Image &image, std::vector<std::string> parameters) {
    int width = std::min(std::stoi(parameters[0]), image.Width());
    int height = std::min(std::stoi(parameters[1]), image.Height());

    Image new_im(width, height);

    for (int i = 0; i < width; ++i) {
        for (int j = std::max(0, image.Height() - height); j < image.Height(); ++j) {
            RGB new_pxl = image.GetRgb(i, j);

            new_im.ChangePixel(new_pxl, i, j + height - image.Height());
        }
    }
    image = new_im;
}
#include "../filter.h"
#include "cmath"
#include "../Image.h"
#include "stdexcept"

class Blur : public Filter {
public:
    Blur(){};
    ~Blur() override{};
    void Apply(Image& image, std::vector<std::string> parameters) override;
};
#include <fstream>

#include "ppm_P3_filter.hpp"
#include "ppm_P3_generator.hpp"

int main() {
    std::ofstream generated_image("../images/image.ppm");
    generate_P3_ppm(generated_image);
    generated_image.close();

    std::ifstream image("../images/monument.ppm");
    std::ofstream newimage("../images/monument_new.ppm");
    filter_P3_ppm(image, newimage);
    image.close();
    newimage.close();

    return 0;
}

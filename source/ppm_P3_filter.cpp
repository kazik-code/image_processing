#include "ppm_P3_filter.hpp"

#include <fstream>
#include <sstream>
#include <string>

void copy_ppm_header(std::ifstream& old_image, std::ofstream& new_image) {
    std::string type, width, height, RGB;
    old_image >> type;
    old_image >> width;
    old_image >> height;
    old_image >> RGB;

    new_image << type << '\n';
    new_image << width << ' ' << height << '\n';
    new_image << RGB << '\n';
}

void filter_P3_ppm(std::ifstream& image, std::ofstream& newimage) {
    if (image.is_open()) {
        copy_ppm_header(image, newimage);

        std::string red, green, blue;
        int r, g, b;
        while(!image.eof()) {
            image >> red;
            image >> green;
            image >> blue;

            std::stringstream redstream(red);
            std::stringstream greenstream(green);
            std::stringstream bluestream(blue);

            redstream >> r;
            greenstream >> g;
            bluestream >> b;

            // std::clamp !
            /*
            if (b + 50 >= 255) {
                b = 255;
            } else {
                b += 50;
            }
            */
            b = 67;

            newimage << r << ' ' << g << ' ' << b << ' ';
        }
    }
}

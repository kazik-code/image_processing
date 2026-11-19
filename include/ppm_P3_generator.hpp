#pragma once

#include <fstream>

void P3_header_init(int width, int height, int colour_max, std::ofstream& image);
void generate_P3_ppm(std::ofstream& image, int image_width = 100, int image_height = 100, int colour_max = 255);

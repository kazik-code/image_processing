#pragma once

#include <fstream>

void copy_ppm_header(std::ifstream& old_image, std::ofstream& new_image);
void filter_P3_ppm(std::ifstream& image, std::ofstream& newimage);

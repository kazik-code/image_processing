#include <fstream>

void P3_header_init(int width, int height, int colour_max, std::ofstream& image) {
    image << "P3\n";
    image << width << ' ' << height << '\n';
    image << colour_max << '\n';
}

int main() {
    int image_height {100};
    int image_width {100};
    int colour_max {255};

    std::ofstream image("image.ppm");
    if (image.is_open()) {
        

        P3_header_init(image_width, image_height, colour_max, image);

        for (int y = 0; y < image_height; ++y) {
            for (int x = 0; x < image_width; ++x) {
                image <<x%256 << ' ' << x%256 << ' ' << x%256 << '\n';
            
            }
        }


    }

    image.close();
    return 0;
}
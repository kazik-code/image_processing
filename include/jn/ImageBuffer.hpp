#pragma once
#include <stdexcept>
#include <vector>
#include <fstream>
#include <string>
#include <cstdint>
#include <array>


class ImageBuffer {
private:
    void skipComments(std::istream& in) {
    in >> std::ws;
    while (in.peek() == '#') {
        std::string comment;
        std::getline(in, comment);
        in >> std::ws;
    }
}
protected:
    std::vector<uint8_t> m_buffer;
    unsigned int m_width {0};
    unsigned int m_height {0};
    unsigned int m_maxval {0};



public:
    void setWidth(unsigned int w) {
        if ( w <= 0 ) {
            throw std::invalid_argument("Width must be greater than zero");
        } else if ( w > 1920 ) { 
            throw std::invalid_argument("Maximum resolution is FullHD (1920x1080)");
        } else { m_width = w; }
    }

    void setHeight(unsigned int h) {
        if ( h <= 0 ) {
            throw std::invalid_argument("Height must be greater than zero");
        } else if ( h > 1080 ) { 
            throw std::invalid_argument("Maximum resolution is FullHD (1920x1080)");
        } else { m_height = h; }
    }

    void setMaxParam(unsigned int m) {
        if ( m <= 0 ) {
            throw std::invalid_argument("Maximum RGB parameter must be greater than zero");
        } else if ( m > 255 ) { 
            throw std::invalid_argument("Maximum RBG parameter must contain in one byte (255)");
        } else { m_maxval = m; }       
    }
    

    explicit ImageBuffer(std::ifstream &loaded_image) {
        std::string type;
        skipComments(loaded_image);
        if (!(loaded_image >> type) || type != "P6") {
            throw std::runtime_error("Unsupported or invalid PPM format (expected P6)");
        }

        std::array<unsigned int, 3> parameters;
        for (auto& param : parameters) {
            skipComments(loaded_image);
            if (!(loaded_image >> param)) {
                throw std::runtime_error("Error with PPM header read");
            }
        } loaded_image.get();

        auto [width, height, maxval] = parameters;
        setWidth(width); setHeight(height); setMaxParam(maxval);
    
  }

};
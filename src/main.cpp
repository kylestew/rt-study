#include <iostream>
#include <stdio.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    const int image_width = 256;
    const int image_height = 256;

    char data[image_width * image_height * 3];

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.25;

            int off = (j * image_width + i) * 3;
            data[off+0] = static_cast<char>(255.999 * r);
            data[off+1] = static_cast<char>(255.999 * g);
            data[off+2] = static_cast<char>(255.999 * b);
        }
    }

    return stbi_write_png("output.png", image_width, image_height, 3, &data, sizeof(char) * 3 * image_width) != 0;
}

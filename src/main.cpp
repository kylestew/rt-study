#include <iostream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "vec3.h"
#include "color.h"

int main() {
    const int image_width = 256;
    const int image_height = 256;

    char data[image_width * image_height * 3];

    for (int j = image_height - 1; j >= 0; --j) {
 
        std::cout << "\rScanlines remaining: " << j << ' ' << std::endl;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(double(i)/(image_width-1), double(j)/(image_height-1), 0.25);
            int off = (j * image_width + i) * 3;
            write_color(&data[off], pixel_color);
        }
    }

    return stbi_write_png("output.png", image_width, image_height, 3, &data, sizeof(char) * 3 * image_width) != 0;
}

#pragma once
#include "vec3.h"
#include <iostream>

void write_color(char *data, color pixel_color) {
    data[0] = static_cast<char>(255.99 * pixel_color.x());
    data[1] = static_cast<char>(255.99 * pixel_color.y());
    data[2] = static_cast<char>(255.99 * pixel_color.z());
}

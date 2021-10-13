#pragma once
#include <iostream>

#include "vec3.h"

void write_color(char* data, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // divide color by number of samples
    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    data[0] = static_cast<int>(256 * clamp(r, 0.0, 0.999));
    data[1] = static_cast<int>(256 * clamp(g, 0.0, 0.999));
    data[2] = static_cast<int>(256 * clamp(b, 0.0, 0.999));
}

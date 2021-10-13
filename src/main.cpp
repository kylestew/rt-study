#include <iostream>

#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "sphere.h"
#include "utility.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

color ray_color(const ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)) {
        return 0.5 * (rec.normal + color(1, 1, 1));
    }

    // create gradient background
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {
    // image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 100;

    // world
    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // camera
    camera cam;

    char data[image_width * image_height * 3];

    for (int j = image_height - 1; j >= 0; --j) {
        std::cout << "\rScanlines remaining: " << j << ' ' << std::endl;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width - 1);
                auto v = (j + random_double()) / (image_height - 1);
                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world);
            }
            int off = (j * image_width + i) * 3;
            write_color(&data[off], pixel_color, samples_per_pixel);
        }
    }

    stbi_flip_vertically_on_write(1);
    return stbi_write_png("output.png", image_width, image_height, 3, &data,
                          sizeof(char) * 3 * image_width) != 0;
}

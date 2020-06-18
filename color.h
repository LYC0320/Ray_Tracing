#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

void write_color(color pixel_color, double samples_per_pixel, uint8_t *pixels, int &index)
{
    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    double scale = 1.0 / samples_per_pixel;

    // gamma correction
    r = sqrt(r * scale);
    g = sqrt(g * scale);
    b = sqrt(b * scale);

    double min = 0.0;
    double max = 1.0;

    pixels[index++] = static_cast<int>(clamp(r, min, max) * 255.999);
    pixels[index++] = static_cast<int>(clamp(g, min, max) * 255.999);
    pixels[index++] = static_cast<int>(clamp(b, min, max) * 255.999);
    
}

#endif
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "std_image_write.h"
#include "common_header.h"

color ray_color(const ray &r, hittable_list &world, int max_depth)
{
    if (max_depth <= 0)
        return color(0.0, 0.0, 0.0);

    hit_record hr;

    if (world.isHit(r, 0, infinitty, hr))
    {
        point3 targetPoint = hr.hitPoint + hr.normal + random_in_unit_sphere();
        ray reflectRay = ray(hr.hitPoint, targetPoint - hr.hitPoint);

        vec3 n = hr.normal;
        //return 0.5 * (n + vec3(1.0, 1.0, 1.0));
        return 0.5 * ray_color(reflectRay, world, max_depth - 1);
    }
    vec3 unit_direction = unit_vector(r.direction());
    double w = 0.5 * (unit_direction.y() + 1.0);
    color topColor(0.5, 0.7, 1.0), bottomColor(1.0, 1.0, 1.0);
    
    return topColor * w + bottomColor * (1.0 - w);
}

int main()
{
    
    camera cam;
    const double aspect_ratio = 16.0 / 9.0;

    const int img_w = 384;
    const int img_h = static_cast<int>(img_w / aspect_ratio);
    const int samples_per_pixel = 100;

    uint8_t *pixels = new uint8_t[img_w * img_h * channel_num];


    int index = 0;

    // set scene

    hittable_list world;
    point3 center = point3(0.0, 0.0, -1.0);
    point3 center2 = point3(0.0, -100.5, -1.0);
    sphere ball = sphere(center, 0.5);
    sphere ball2 = sphere(center2, 100);

    world.add(make_shared<sphere>(ball));
    world.add(make_shared<sphere>(ball2));

    // set scene

    for (int j = img_h - 1; j >= 0; j--)
    {
        for (int i = 0; i < img_w; i++)
        {
            color pixel_color = color(0.0, 0.0, 0.0);
            for (int s = 0; s < samples_per_pixel; s++)
            {
                int max_depth = 50;

                double u = double(i + random_double()) / (img_w - 1);
                double v = double(j + random_double()) / (img_h - 1);

                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world, max_depth);

            }
            write_color(pixel_color, samples_per_pixel, pixels, index);
        }
    }

    stbi_write_bmp("image.bmp", img_w, img_h, channel_num, pixels);

    return 0;
}
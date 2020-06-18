#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"
#include "ray.h"

class camera
{
    public:
        camera()
        {
            const double aspect_ratio = 16.0 / 9.0;
            const double viewport_h = 2.0;
            const double viewport_w = viewport_h * aspect_ratio;
            const double focal_length = 1.0;

            eyePoint = point3(0.0, 0.0, 0.0);
            horizontal = vec3(viewport_w, 0.0, 0.0);
            vertical = vec3(0.0, viewport_h, 0.0);
            lower_left_corner = eyePoint - horizontal / 2.0 - vertical / 2.0 - vec3(0.0, 0.0, focal_length);
        }

        ray get_ray(double u, double v)
        {
            return ray(eyePoint, lower_left_corner + u * horizontal + v * vertical - eyePoint);
        }

    private:
        point3 eyePoint;
        vec3 horizontal;
        vec3 vertical;
        point3 lower_left_corner;
};

#endif
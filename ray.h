#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray
{
    public:
        ray() {}
        ray(const point3 &orig, const vec3 &dir) : orig(orig), dir(dir) {}

        point3 origin() const { return this->orig; }
        vec3 direction() const { return unit_vector(this->dir); }

        point3 at(double t) const { return this->orig + this->direction() * t; }

    public:
        point3 orig;
        vec3 dir;
};

#endif
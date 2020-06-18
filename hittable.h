#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record
{
    point3 hitPoint;
    vec3 normal;
    double t;
    bool front_face;

    // black circle
    inline void set_face_normal(const ray &r, vec3 &out_normal)
    {

        front_face = dot(r.direction(), out_normal) <= 0.0;

        normal = front_face ? out_normal : -out_normal;
        
    }
};

class hittable
{
    public: 
        // pure virtual
        virtual bool isHit(const ray &r, double t_min, double t_max, hit_record &hr) = 0;
};

#endif
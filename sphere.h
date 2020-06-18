#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "ray.h"


class sphere : public hittable
{
    public: 
        sphere() {}
        sphere(const point3 &center, const double &radius) : center(center), radius(radius) {}

        virtual bool isHit(const ray &r, double t_min, double t_max, hit_record &hr) override;

    public:
        point3 center;
        double radius;
};

bool sphere::isHit(const ray &r, double t_min, double t_max, hit_record &hr)
{
    vec3 oc = r.origin() - this->center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - this->radius * this->radius;

    double s = half_b * half_b - a * c;
    
    if (s >= 0.0)
    {
        double tmp_t = (-half_b - sqrt(s)) / a;
        
        if(tmp_t > t_min && tmp_t < t_max)
        {
            hr.t = tmp_t;
            hr.hitPoint = r.at(hr.t);
            vec3 out_normal = unit_vector(hr.hitPoint - this->center);
            hr.set_face_normal(r, out_normal);

            return true;
        }

        tmp_t = (-half_b + sqrt(s)) / a;

        if(tmp_t > t_min && tmp_t < t_max)
        {
            hr.t = tmp_t;
            hr.hitPoint = r.at(hr.t);
            vec3 out_normal = unit_vector(hr.hitPoint - this->center);
            hr.set_face_normal(r, out_normal);

            return true;
        }
        
    }

    return false;
}

#endif
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <vector>
#include <memory>

class hittable_list : hittable
{
    public:
        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }
        virtual bool isHit(const ray &r, double t_min, double t_max, hit_record &hr) override;
        void add(shared_ptr<hittable> object){ objects.push_back(object); }
        void clear(){ objects.clear(); }

    public:
        vector<shared_ptr<hittable>> objects;
};


bool hittable_list::isHit(const ray &r, double t_min, double t_max, hit_record &hr)
{
    hit_record tmp_hr;
    bool hit_anything = false;

    // depth test
    double closet_so_far = t_max;

    for(auto object : this->objects)
    {
        if(object->isHit(r, t_min, closet_so_far, tmp_hr))
        {
            hr = tmp_hr;
            hit_anything = true;
            closet_so_far = tmp_hr.t;
        }
    }

    return hit_anything;
}

#endif

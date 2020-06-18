#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H

#include <iostream>
#include <vector>
#include <limits>
#include <memory>
#include <random>

// usings

using namespace std;

// constants

double pi = 3.1415926535897932385;
double infinitty = numeric_limits<double>::infinity();
#define channel_num 3

// utility functions

inline double degree_to_radian(double degree)
{
    return degree * pi / 180.0;
}

inline double random_double()
{
    // return [0.0, 1.0)
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max)
{
    return min + random_double() * (max - min);
}

inline double clamp(double x, const double min, const double max)
{
    if (x < min)
        return min;
    
    if (x > max)
        return max;
    
    return x;
}

// common headers

#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "hittable_list.h"
#include "camera.h"
#include "color.h"


#endif
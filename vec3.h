#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>
using namespace std;

class vec3
{
    public:
        vec3() : e{0, 0, 0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
        double x() { return e[0]; }
        double y() { return e[1]; }
        double z() { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        vec3& operator+=(vec3 v)
        {
            this->e[0] += v.e[0];
            this->e[1] += v.e[1];
            this->e[2] += v.e[2];

            return *this;
        }

        vec3& operator*=(const double t)
        {
            this->e[0] *= t;
            this->e[1] *= t;
            this->e[2] *= t;

            return *this;
        }

        vec3& operator/=(const double t)
        {
            this->e[0] *= 1 / t;
            this->e[1] *= 1 / t;
            this->e[2] *= 1 / t;

            return *this;
        }

        double length() const
        {
            return sqrt(this->length_squared());
        }
        double length_squared() const
        {
            return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
        }

        // 沒 instance 也能 call
        inline static vec3 random_vector(double min, double max)
        {
            return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
        }
    
    public:
        double e[3];
};

inline vec3 operator+(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 operator*(const vec3 &v, const double &t)
{
    return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

inline vec3 operator*(const double &t, const vec3 &v)
{
    return v * t;
}

inline vec3 operator/(const vec3 &v, const double &t)
{
    return v * (1.0 / t);
}

inline ostream& operator<<(ostream &out, const vec3 &v)
{
    return out << v.e[0] << ", " << v.e[1] << ", " << v.e[2];
}

inline double dot(const vec3 &v1, const vec3 &v2)
{
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2)
{
    return vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
                v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
                v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline vec3 unit_vector(const vec3 &v)
{
    return v / v.length();
}

inline vec3 random_in_unit_sphere()
{
    while(true)
    {
        vec3 v = vec3::random_vector(-1.0, 1.0);
        if (v.length() > 1.0)
            continue;

        return v;
    }
}

using point3 = vec3;
using color = vec3;

#endif
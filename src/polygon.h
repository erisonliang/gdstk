/*
Copyright 2020-2020 Lucas Heitzmann Gabrielli.
This file is part of gdstk, distributed under the terms of the
Boost Software License - Version 1.0.  See the accompanying
LICENSE file or <http://www.boost.org/LICENSE_1_0.txt>
*/

#define _USE_MATH_DEFINES

#ifndef __POLYGON_H__
#define __POLYGON_H__

#include <cstdint>
#include <cstdio>

#include "array.h"
#include "property.h"
#include "vec.h"

namespace gdstk {

struct Polygon {
    int16_t layer;
    int16_t datatype;
    // point_array is expected to be oriented in counter-clockwise direction otherwise area() will
    // return a negative value and it might be considered a hole in clipperlib
    Array<Vec2> point_array;
    Property* properties;
    // Used by the python interface to store the associated PyObject* (if any).
    // No functions in gdstk namespace should touch this value!
    void* owner;

    void print(bool all) const;
    void clear();
    void copy_from(const Polygon& polygon);
    double area() const;
    void bounding_box(Vec2& min, Vec2& max) const;
    void translate(const Vec2 v);
    void scale(const Vec2 scale, const Vec2 center);
    void mirror(const Vec2 p0, const Vec2 p1);
    void rotate(double angle, const Vec2 center);
    void transform(double magnification, const Vec2 translation, bool x_reflection, double rotation,
                   const Vec2 origin);
    void fillet(const double* radii, double tol);
    Array<Polygon*> fracture(int64_t max_points, double precision) const;
    void to_gds(FILE* out, double scaling) const;
    void to_svg(FILE* out, double scaling) const;
};

Polygon rectangle(const Vec2 corner1, const Vec2 corner2, int16_t layer, int16_t datatype);
Polygon cross(const Vec2 center, double full_size, double arm_width, int16_t layer,
              int16_t datatype);
Polygon regular_polygon(const Vec2 center, double side_length, int64_t sides, double rotation,
                        int16_t layer, int16_t datatype);
Polygon ellipse(const Vec2 center, double radius_x, double radius_y, double inner_radius_x,
                double inner_radius_y, double initial_angle, double final_angle, double tolerance,
                int16_t layer, int16_t datatype);
Polygon racetrack(const Vec2 center, double straight_length, double radius, double inner_radius,
                  bool vertical, double tolerance, int16_t layer, int16_t datatype);
Array<Polygon*> text(const char* s, double size, const Vec2 position, bool vertical, int16_t layer,
                     int16_t datatype);

}  // namespace gdstk

#endif
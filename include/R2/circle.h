#pragma once
#include <ostream>
#include "point.h"
#include "shape.h"

#ifndef GEOM_EPSILON
#define GEOM_EPSILON 1e-10
#endif

namespace geom {

class CircleR2 : public ShapeR2 {
 public:
    CircleR2() = default;
    CircleR2(const PointR2& c, double r);
    CircleR2(const PointR2& a, const PointR2& b, const PointR2& c);
    CircleR2(const CircleR2& other) = default;
    ~CircleR2() = default;

 public:
    PointR2 center() const;
    double  radius() const;

    void set_center(const PointR2& p);
    void set_radius(double r);

 public:
    bool valid() const;

 public:
    CircleR2& operator=(const CircleR2& other);

 public:
    double perimeter() const override;
    double area()      const override;

 private:
    PointR2  _center;
    double _radius = 0.;
};

}  // namespace geom
std::ostream& operator<<(std::ostream& os, const geom::CircleR2& c);

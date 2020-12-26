#pragma once
#include <ostream>

#ifndef GEOM_EPSILON
#define GEOM_EPSILON 1e-10
#endif

namespace geom {

class VectorR2 {
 public:
    VectorR2() = default;
    VectorR2(double x, double y);
    VectorR2(const VectorR2& other) = default;
    ~VectorR2() = default;

 public:
    void set_x(double xx);
    void set_y(double yy);

    double x() const;
    double y() const;

 public:
    VectorR2  operator +  (const VectorR2& other) const;
    VectorR2  operator -  (const VectorR2& other) const;
    VectorR2  operator *  (double coef) const;

    VectorR2& operator =  (const VectorR2& other);
    VectorR2& operator -= (const VectorR2& other);
    VectorR2& operator += (const VectorR2& other);
    VectorR2& operator *= (double coef);

 public:
    // Scalar product
    double    operator *  (const VectorR2& other) const;
    // Angle from this vector to v
    double    angle(const VectorR2& v) const;
    // Normal to this vector
    VectorR2  normal() const;
    // Make length = 1
    VectorR2& normalize();

    double    length() const;

 private:
    double _x = 0., _y = 0.;
};

}  // namespace geom

std::ostream& operator<<(std::ostream& os, const geom::VectorR2& v);

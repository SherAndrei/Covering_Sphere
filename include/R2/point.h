#pragma once
#include <ostream>
#include "shape.h"
#include "vector.h"

#ifndef GEOM_EPSILON
#define GEOM_EPSILON 1e-10
#endif

namespace geom {

class PointR2 : public ShapeR2 {
 public:
    PointR2() = default;
    PointR2(double x, double y, bool z);
    PointR2(double x, double y);
    PointR2(const PointR2& other);
    ~PointR2() = default;

 public:
    void set_x(double xx);
    void set_y(double yy);
    // Set flag of PointR2 affination to a set
    void set_flag(bool e);

    bool   is_belongs() const;
    double x() const;
    double y() const;

 public:
    PointR2  operator +  (const PointR2& other) const;
    PointR2  operator -  (const PointR2& other) const;
    PointR2  operator *  (double coef) const;

    PointR2& operator =  (const PointR2& other);
    PointR2& operator -= (const PointR2& other);
    PointR2& operator += (const PointR2& other);
    PointR2& operator *= (double coef);

    PointR2  operator +  (const VectorR2& vec) const;
    PointR2  operator -  (const VectorR2& vec) const;
    PointR2& operator -= (const VectorR2& vec);
    PointR2& operator += (const VectorR2& vec);

 public:
    double perimeter() const override;
    double area()      const override;

 private:
    double _x = 0., _y = 0.;
    bool _flag = false;
};

}  // namespace geom

std::ostream& operator<<(std::ostream& os, const geom::PointR2& p);

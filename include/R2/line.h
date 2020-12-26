#pragma once
#include <ostream>

#include "point.h"
#include "vector.h"
#include "shape.h"

#ifndef GEOM_EPSILON
#define GEOM_EPSILON 1e-10
#endif

namespace geom {

class LineR2 : public ShapeR2 {
 public:
    LineR2() = default;
    LineR2(const PointR2& a, const PointR2& b);
    LineR2(const PointR2& a, const VectorR2& v);
    LineR2(const LineR2& other);
    ~LineR2() = default;

    void set_a(const PointR2& a);
    void set_v(const VectorR2& v);

    PointR2  a() const;
    VectorR2 v() const;
    // check if vector is null
    bool valid() const;
 public:
    

 public:
    double perimeter() const override;
    double area()      const override;

 private:
    PointR2  _a;
    VectorR2 _v;
};

bool is_parallel(const LineR2& a, const LineR2& b);

}  // namespace geom

std::ostream& operator<<(std::ostream& os, const geom::LineR2& l);

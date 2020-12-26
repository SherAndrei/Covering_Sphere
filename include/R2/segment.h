#pragma once
#include <fstream>

#include "point.h"
#include "shape.h"

#ifndef GEOM_EPSILON
#define GEOM_EPSILON 1e-10
#endif

namespace geom {

class SegmentR2 : public ShapeR2 {
 public:
    SegmentR2() = default;
    SegmentR2(const PointR2& a, const PointR2& b, bool flag);
    SegmentR2(const PointR2& a, const PointR2& b);
    SegmentR2(const SegmentR2& other) = default;
    ~SegmentR2() = default;

 public:
    void set_a(const PointR2& a);
    void set_b(const PointR2& b);
    // Set flag of SegmentR2 affination to a set
    void set_flag(bool e);

    PointR2 a() const;
    PointR2 b() const;
    bool is_contains() const;

 public:
    double length() const;
    double perimeter() const override;
    double area()      const override;

 private:
    PointR2 _a, _b;
    bool _flag = true;
};

}  // namespace geom

std::ostream& operator<<(std::ostream& os, const geom::SegmentR2& s);

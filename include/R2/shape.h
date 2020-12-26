#pragma once
#include <string>

namespace geom {

class ShapeR2 {
 public:
    ShapeR2() = default;
    virtual ~ShapeR2() = default;
    virtual double perimeter() const = 0;
    virtual double area()      const = 0;
};

}  // namespace geom

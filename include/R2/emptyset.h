#pragma once
#include "shape.h"

namespace geom
{

class EmptySetR2 : public ShapeR2 {
 public:
    double perimeter() const override;
    double area()      const override;
};

}  // namespace geom

#pragma once
#include <memory>
#include "emptyset.h"
#include "point.h"
#include "line.h"
#include "segment.h"
#include "circle.h"

namespace geom {

std::shared_ptr<ShapeR2> intersect(const LineR2& a,   const LineR2& b);
std::shared_ptr<ShapeR2> intersect(const CircleR2& c, const LineR2& a);
std::shared_ptr<ShapeR2> intersect(const CircleR2& a, const CircleR2& b);

}  // namespace geom

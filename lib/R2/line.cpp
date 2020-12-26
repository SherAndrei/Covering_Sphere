#include <cmath>
#include <ostream>
#include "R2/line.h"
#include "R2/point.h"
#include "R2/vector.h"

geom::LineR2::LineR2(const PointR2& a, const PointR2& b)
    : _a{a}, _v{b.x() - a.x(), b.y() - a.y()} {}
geom::LineR2::LineR2(const PointR2& a, const VectorR2& v)
    : _a{a}, _v{v} {}
geom::LineR2::LineR2(const LineR2& other)
    : _a{other._a}, _v{other._v} {}

void geom::LineR2::set_a(const PointR2& a) { _a = a; }
void geom::LineR2::set_v(const VectorR2& v) { _v = v; }

geom::PointR2  geom::LineR2::a() const { return _a; }
geom::VectorR2 geom::LineR2::v() const { return _v; }
bool geom::LineR2::valid() const {
    return (_v.x() >= GEOM_EPSILON && _v.y() >= GEOM_EPSILON);
}

double geom::LineR2::perimeter() const {
    return INFINITY;
}
double geom::LineR2::area()      const {
    return 0.;
}

std::ostream& operator<<(std::ostream& os, const geom::LineR2& l) {
    return os << l.a() << '\n' << l.v() << '\n';
}

bool geom::is_parallel(const LineR2& a, const LineR2& b) {
    return ((a.v().x() * b.v().y()) - (a.v().y() * b.v().x())) < GEOM_EPSILON;
}

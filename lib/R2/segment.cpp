#include <ostream>
#include <cmath>
#include "R2/point.h"
#include "R2/segment.h"

geom::SegmentR2::SegmentR2(const PointR2& a, const PointR2& b, bool flag)
    : _a(a), _b(b), _flag(flag) {}
geom::SegmentR2::SegmentR2(const PointR2& a, const PointR2& b)
    : _a(a), _b(b), _flag(true) {}

void geom::SegmentR2::set_a(const PointR2& a) { _a = a; }
void geom::SegmentR2::set_b(const PointR2& b) { _b = b; }
// Set flag of SegmentR2 affination to a set
void geom::SegmentR2::set_flag(bool e) { _flag = e; }

geom::PointR2 geom::SegmentR2::a() const { return _a; }
geom::PointR2 geom::SegmentR2::b() const { return _b; }
bool geom::SegmentR2::is_contains() const { return _flag; }

double geom::SegmentR2::length() const {
    return sqrt((_a.x() - _b.x())*(_a.x() - _b.x())
              + (_a.y() - _b.y())*(_a.y() - _b.y()));
}
double geom::SegmentR2::perimeter() const {
    return length();
}
double geom::SegmentR2::area()      const {
    return 0.;
}
std::ostream& operator<<(std::ostream& os, const geom::SegmentR2& s) {
    return os << s.a() << '\n' << s.b() << '\n';
}



#include <cmath>
#include <ostream>
#include "R2/circle.h"

#define PI M_PI

geom::CircleR2::CircleR2(const PointR2& c, double r)
    : _center{c}, _radius{r} {}

geom::CircleR2::CircleR2(const PointR2& a, const PointR2& b, const PointR2& c) {
    // Cartesian coordinates
    PointR2 A1 = a - a, B1 = b - a, C1 = c - a;
    double ctr1_x, ctr1_y;
    double D1 = 2 * (B1.x() * C1.y() - B1.y() * C1.x());
    ctr1_x = (C1.y() * (pow(B1.x(), 2.) + pow(B1.y(), 2.))
            - B1.y() * (pow(C1.x(), 2.) + pow(C1.y(), 2.))) / D1;
    ctr1_y = (B1.x() * (pow(C1.x(), 2.) + pow(C1.y(), 2.))
            - C1.x() * (pow(B1.x(), 2.) + pow(B1.y(), 2.))) / D1;
    _center = PointR2 { PointR2 {ctr1_x, ctr1_y} + a};
    _radius = sqrt(pow(ctr1_x, 2.) + pow(ctr1_y, 2.));
}
geom::PointR2  geom::CircleR2::center() const { return _center; }
double   geom::CircleR2::radius() const { return _radius; }

void geom::CircleR2::set_center(const PointR2& p) { _center = p; }
void geom::CircleR2::set_radius(const double   r) { _radius = r; }

bool geom::CircleR2::valid() const { return _radius > 0; }

geom::CircleR2& geom::CircleR2::operator=(const CircleR2& other) {
    this->_center = other._center;
    this->_radius = other._radius;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const geom::CircleR2& c) {
    const int POINTS_AMOUNT = 1000;

    double yy = (2 * PI) / POINTS_AMOUNT;

    for (int i = 1; i <= POINTS_AMOUNT; i++)
        os << geom::PointR2{c.center().x() + c.radius() * cos(yy * i),
                            c.center().y() + c.radius() * sin(yy * i)};

    return os << '\n';
}

double geom::CircleR2::perimeter() const {
    return 2 * PI * _radius;
}
double geom::CircleR2::area()      const {
    return PI * _radius * _radius;
}

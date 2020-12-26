#include "R2/vector.h"
#include <cmath>

geom::VectorR2::VectorR2(double x, double y)    : _x(x), _y(y) {}

void geom::VectorR2::set_x(double x) { _x = x; }
void geom::VectorR2::set_y(double y) { _y = y; }

double geom::VectorR2::x() const { return _x; }
double geom::VectorR2::y() const { return _y; }

geom::VectorR2  geom::VectorR2::operator +  (const VectorR2& other) const {
    return {this->_x + other._x, this->_y + other._y};
}
geom::VectorR2  geom::VectorR2::operator -  (const VectorR2& other) const {
    return {this->_x - other._x, this->_y - other._y};
}
geom::VectorR2  geom::VectorR2::operator *  (double coef) const {
    return {this->_x * coef, this->_y * coef};
}
// Scalar product
double    geom::VectorR2::operator *  (const VectorR2& other) const {
    return this->_x * other._x + this->_y * other._y;
}

geom::VectorR2& geom::VectorR2::operator =  (const VectorR2& other) {
    this->_x = other._x;
    this->_y = other._y;
    return *this;
}
geom::VectorR2& geom::VectorR2::operator -= (const VectorR2& other) {
    return *this = (*this - other);
}
geom::VectorR2& geom::VectorR2::operator += (const VectorR2& other) {
    return *this = (*this + other);
}
geom::VectorR2& geom::VectorR2::operator *= (double coef) {
    return *this = (*this * coef);
}

double geom::VectorR2::length() const {
    return sqrt(_x * _x + _y * _y);
}

geom::VectorR2&  geom::VectorR2::normalize() {
    double l = length();
    if (l >= GEOM_EPSILON) {
        _x /= l;
        _y /= l;
    }
    return *this;
}

geom::VectorR2  geom::VectorR2::normal() const {
    return {-_y, _x};
}

// Angle from this vector to v
double  geom::VectorR2::angle(const VectorR2& v) const {
    double xx = v * (*this);
    double yy = v * normal();
    return atan2(yy, xx);
}

std::ostream& operator<<(std::ostream& os, const geom::VectorR2& v) {
    return os << v.x() << '\n' << v.y() << '\n';
}

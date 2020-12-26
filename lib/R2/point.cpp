#include <ostream>
#include "R2/point.h"

geom::PointR2::PointR2(double x, double y, bool z) : _x(x), _y(y), _flag(z) {}
geom::PointR2::PointR2(double x, double y)         : _x(x), _y(y), _flag(false) {}
geom::PointR2::PointR2(const PointR2& other)
    : _x(other._x), _y(other._y), _flag(other._flag) {}

void geom::PointR2::set_x(double xx) { _x = xx; }
void geom::PointR2::set_y(double yy) { _y = yy; }

// Set flag of PointR2 affination to a set
void geom::PointR2::set_flag(bool e) { _flag = e; }

bool geom::PointR2::is_belongs() const  { return _flag; }
double geom::PointR2::x() const { return _x; }
double geom::PointR2::y() const { return _y; }

geom::PointR2 geom::PointR2::operator + (const PointR2& other) const {
    return {this->_x + other._x, this->_y + other._y};
}
geom::PointR2 geom::PointR2::operator - (const PointR2& other) const {
    return {this->_x - other._x, this->_y - other._y};
}
geom::PointR2 geom::PointR2::operator * (double coef) const {
    return {this->_x * coef, this->_y * coef};
}
geom::PointR2& geom::PointR2::operator = (const PointR2& other) {
    this->_x = other._x;
    this->_y = other._y;
    return *this;
}
geom::PointR2& geom::PointR2::operator += (const PointR2& other) {
    return *this = (*this + other);
}
geom::PointR2& geom::PointR2::operator -= (const PointR2& other) {
    return *this = (*this - other);
}
geom::PointR2& geom::PointR2::operator *= (double coef) {
    return *this = (*this * coef);
}

geom::PointR2  geom::PointR2::operator +  (const VectorR2& vec) const {
    return {this->_x + vec.x(), this->_y + vec.y()};
}
geom::PointR2  geom::PointR2::operator -  (const VectorR2& vec) const {
    return {this->_x - vec.x(), this->_y - vec.y()};
}
geom::PointR2& geom::PointR2::operator += (const VectorR2& vec) {
    return *this = (*this + vec);
}
geom::PointR2& geom::PointR2::operator -= (const VectorR2& vec) {
    return *this = (*this - vec);
}

double geom::PointR2::perimeter() const {
    return 0.;
}
double geom::PointR2::area()      const {
    return 0.;
}


std::ostream& operator<<(std::ostream& os, const geom::PointR2& p) {
    return os << p.x() << ' ' << p.y() << '\n';
}
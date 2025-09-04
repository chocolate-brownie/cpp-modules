#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) { return; }

Point::Point(const float fX, const float fY) : _x(fX), _y(fY) { return; }

Point::Point(const Point &other) : _x(other._x), _y(other._y) { return; };

Point &Point::operator=(const Point &other) {
  (void)other;
  return *this;
}

Point::~Point(void) { return; }

Fixed Point::getX(void) const { return this->_x; }

Fixed Point::getY(void) const { return this->_y; }

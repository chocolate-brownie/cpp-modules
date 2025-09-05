#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) { return; }

Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y)) { return; }

Point::Point(const Point &other) : _x(other._x), _y(other._y) { return; }

Point &Point::operator=(const Point &other) {
  (void)other;
  return *this;
}

Point::~Point(void) { return; }

Fixed Point::getX(void) const { return _x; }

Fixed Point::getY(void) const { return _y; }

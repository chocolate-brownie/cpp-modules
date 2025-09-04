#include "Fixed.hpp"
#include "Point.hpp"

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed ab_side = (b.getX() - a.getX()) * (point.getY() - a.getY()) -
                  (b.getY() - a.getY()) * (point.getX() - a.getX());

  Fixed bc_side = (c.getX() - b.getX()) * (point.getY() - b.getY()) -
                  (c.getY() - b.getY()) * (point.getX() - b.getX());

  Fixed ca_side = (a.getX() - c.getX()) * (point.getY() - c.getY()) -
                  (a.getY() - c.getY()) * (point.getX() - c.getX());

  bool all_positive =
      (ab_side > Fixed(0)) && (bc_side > Fixed(0)) && (ca_side > Fixed(0));
  bool all_negative =
      (ab_side < Fixed(0)) && (bc_side < Fixed(0)) && (ca_side < Fixed(0));

  return all_positive || all_negative;
}
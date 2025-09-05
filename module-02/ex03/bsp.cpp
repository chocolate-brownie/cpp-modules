/* The "side checking formula" is typically used in computational geometry to
determine which side of a line a point lies on. This is often done by evaluating
the sign of the cross product between vectors.

## Side Checking Formula

Given three points $$ A(x_a, y_a) $$, $$ B(x_b, y_b) $$, and $$ P(x_p, y_p) $$,
the formula to check the side of point $$P$$ relative to line $$AB$$ is:

side = (x_b - x_a)(y_p - y_a) - (y_b - y_a)(x_p - x_a)

    - If side > 0, point PP lies on one side of the line ABAB (commonly the
                left side).
    - If side < 0, point PP lies on the opposite side (commonly the right
                side).
    - If side = 0, point PP lies exactly on the line ABAB.

## Use

This formula is the cornerstone of algorithms such as checking if a point lies
inside a triangle (using the "bsp" function in your context) by verifying
whether the point is on the same side of all triangle edges.

It calculates the signed area of the parallelogram formed by vectors $$AB$$ and
$$AP$$, which indicates the direction of $$P$$ relative to $$AB$$.

This formula is essential for side checks in point-in-triangle tests and other
planar geometric computations.
 */

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
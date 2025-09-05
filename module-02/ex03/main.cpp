#include "Point.hpp"
#include <iostream>

int main(void) {
  Point a(0.0f, 0.0f);
  Point b(10.0f, 0.0f);
  Point c(5.0f, 10.0f);

  Point point_inside(5.0f, 5.0f);
  Point point_outside(15.0f, 5.0f);
  Point point_on_edge(5.0f, 0.0f);

  std::cout << "Is point (5,5) inside? "
            << (bsp(a, b, c, point_inside) ? "Yes" : "No") << std::endl;

  std::cout << "Is point (15,5) inside? "
            << (bsp(a, b, c, point_outside) ? "Yes" : "No") << std::endl;

  std::cout << "Is point (5,0) on edge inside? "
            << (bsp(a, b, c, point_on_edge) ? "Yes" : "No") << std::endl;

  return 0;
}
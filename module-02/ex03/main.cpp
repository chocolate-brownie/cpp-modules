#include "Point.hpp"
#include <iostream>

int main(void) {
  // Define a triangle with vertices A, B, C
  Point a(0.0f, 0.0f);
  Point b(10.0f, 0.0f);
  Point c(5.0f, 10.0f);

  // Define some points to test
  Point point_inside(5.0f, 5.0f);
  Point point_outside(15.0f, 5.0f);
  Point point_on_edge(5.0f, 0.0f);
  Point point_is_vertex(0.0f, 0.0f);

  std::cout << "Triangle vertices: A(0,0), B(10,0), C(5,10)" << std::endl;
  std::cout << "------------------------------------------" << std::endl;

  // Test point_inside
  std::cout << "Is point (5,5) inside? "
            << (bsp(a, b, c, point_inside) ? "Yes" : "No") << std::endl;

  // Test point_outside
  std::cout << "Is point (15,5) inside? "
            << (bsp(a, b, c, point_outside) ? "Yes" : "No") << std::endl;

  // Test point_on_edge
  std::cout << "Is point (5,0) on edge inside? "
            << (bsp(a, b, c, point_on_edge) ? "Yes" : "No") << std::endl;

  // Test point_is_vertex
  std::cout << "Is vertex A(0,0) inside? "
            << (bsp(a, b, c, point_is_vertex) ? "Yes" : "No") << std::endl;

  return 0;
}
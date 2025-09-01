#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixedPointNumberValue(0) {
  std::cout << "Default construtor called!" << std::endl;
  return;
}

Fixed::Fixed(const Fixed &other)
    : fixedPointNumberValue(other.fixedPointNumberValue) {
  return;
}
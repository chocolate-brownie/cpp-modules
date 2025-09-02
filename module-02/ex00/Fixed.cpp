#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixedPointNumberValue(0) {
  std::cout << "Default construtor called" << std::endl;
  return;
}

/* Fixed::Fixed(const Fixed &other)
    : fixedPointNumberValue(other.fixedPointNumberValue) {
  std::cout << "Copy constructor called" << std::endl;
} */

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operatore called" << std::endl;
  if (this != &other) {
    this->fixedPointNumberValue = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fixedPointNumberValue;
}

void Fixed::setRawBits(int const raw) { this->fixedPointNumberValue = raw; }
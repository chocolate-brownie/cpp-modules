#include "Fixed.hpp"
#include <cmath>
#include <iostream>

/* ---------------- Stuff from ex00 ------------- */
Fixed::Fixed() : fixedPointNumberValue(0) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->fixedPointNumberValue = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return this->fixedPointNumberValue; }

void Fixed::setRawBits(int const raw) { this->fixedPointNumberValue = raw; }

/* ---------------- Stuff from ex01 ------------- */
Fixed::Fixed(const int number)
    : fixedPointNumberValue(number << numberOfFractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
    : fixedPointNumberValue(roundf(number * (1 << numberOfFractionalBits))) {
  std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt(void) const {
  return fixedPointNumberValue >> numberOfFractionalBits;
}

float Fixed::toFloat(void) const {
  return (float)fixedPointNumberValue / (1 << numberOfFractionalBits);
}

/** The operator<< overload that you wrote defines the default way your Fixed
 * object presents itself to the world when printed. Your choice to use
 * toFloat() inside that function was an engineering decision that makes the
 * floating-point value the default representation. You always have the freedom
 * to be more specific and get a different representation by manually calling
 * another function, like a.toInt()*/
std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
  os << obj.toFloat();
  return os;
}
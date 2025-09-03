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

/* ---------------- Stuff from ex02 ------------- */
bool Fixed::operator<(const Fixed &other) {
  return this->fixedPointNumberValue < other.fixedPointNumberValue;
}

bool Fixed::operator>(const Fixed &other) {
  return this->fixedPointNumberValue > other.fixedPointNumberValue;
}

bool Fixed::operator==(const Fixed &other) {
  return this->fixedPointNumberValue == other.fixedPointNumberValue;
}

Fixed Fixed::operator+(const Fixed &other) {
  Fixed result;
  result.setRawBits(this->fixedPointNumberValue + other.fixedPointNumberValue);
  return result;
}

Fixed Fixed::operator-(const Fixed &other) {
  Fixed result;
  result.setRawBits(this->fixedPointNumberValue - other.fixedPointNumberValue);
  return result;
}

/* When you multiply two numbers that are both scaled by 256, the result ends up
 * being scaled by 256 * 256. You have to scale it back down by dividing by
 * 256.*/
Fixed Fixed::operator*(const Fixed &other) {
  Fixed result;
  long long temp =
      (long long)this->fixedPointNumberValue * other.fixedPointNumberValue;
  result.setRawBits(temp / (1 << numberOfFractionalBits));
  return result;
}

Fixed Fixed::operator/(const Fixed &other) {
  Fixed result;
  long long temp =
      (long long)this->fixedPointNumberValue * (1 << numberOfFractionalBits);
  result.setRawBits(temp / other.fixedPointNumberValue);
  return result;
}

Fixed &Fixed::operator++(void) {
  this->fixedPointNumberValue++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  this->fixedPointNumberValue++;
  return temp;
}

Fixed &Fixed::operator--(void) {
  this->fixedPointNumberValue--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  this->fixedPointNumberValue--;
  return temp;
}
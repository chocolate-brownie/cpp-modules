#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>

class Fixed {
private:
  int fixedPointNumberValue;
  static const int numberOfFractionalBits = 8;

public:
  Fixed();
  Fixed(const Fixed &other);
};

#endif
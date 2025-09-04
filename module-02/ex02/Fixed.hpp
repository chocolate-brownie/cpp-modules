#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>

class Fixed {
private:
  int fixedPointNumberValue;
  static const int numberOfFractionalBits = 8;

public:
  /* -------------------------- EX00 --------------------------------- */
  Fixed();                              // Default constructor
  Fixed(const Fixed &other);            // Copy constructor
  Fixed &operator=(const Fixed &other); // Copy assignment operator overload
  ~Fixed();                             // Destructor

  /**
  -- When each is called --

  Copy constructor: Called when a new object is created as a copy of an
  existing object (e.g., MyClass b = a; or MyClass b(a);). It allocates storage
  and initializes the new instance.

  Copy assignment operator: Called when an already existing object is assigned
  from another existing object (e.g., b = a; after both b and a have been
  constructed).

  -- Memory Management --

  Copy constructor: Allocates new memory (if dynamic allocation is involved),
  creating a fully new object with copied content.

  Copy assignment operator: Replaces the content of the existing object, which
  means it may need to release any old resources before copying new data in.
  */

  int getRawBits(void) const;
  void setRawBits(int const raw);

  /* -------------------------- EX01 --------------------------------- */
  Fixed(const int number);
  Fixed(const float number);

  float toFloat(void) const;
  int toInt(void) const;

  /* -------------------------- EX02 --------------------------------- */
  bool operator<(const Fixed &other) const;
  bool operator>(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;

  Fixed operator+(const Fixed &other);
  Fixed operator-(const Fixed &other);
  Fixed operator*(const Fixed &other);
  Fixed operator/(const Fixed &other);

  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);

  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
};

/*The reason is that the object on the left-hand side of the operator determines
how the function is called.

When you write std::cout << a;, the object on the left is std::cout, which is an
ostream object, not a Fixed object.

If operator<< were a member function of the Fixed class, the syntax would have
to be a << std::cout;, which is unnatural and doesn't work with the standard
library's streaming design.

Because we can't add new functions to the std::ostream class, the only way to
make the natural syntax std::cout << a; work is to declare operator<< as a
non-member function that takes the stream as its first argument and your Fixed
object as its second.*/
std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif
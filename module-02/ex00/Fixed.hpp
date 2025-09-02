#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
  int fixedPointNumberValue;
  static const int numberOfFractionalBits = 8;

public:
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
};

#endif
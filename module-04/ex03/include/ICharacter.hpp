#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

/* ----- Interface in C++ -----
- Typically implemented as an abstract class with only pure virtual functions
(no data members or implemented methods).
- Acts as a contract specifying what methods derived classes must implement.
- Contains only pure virtual functions (methods declared with = 0) and no data
members or implemented functions.
- Cannot be instantiated. */

#include <string>

class AMateria;

class ICharacter {
  public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif

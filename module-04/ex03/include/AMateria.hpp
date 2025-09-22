#ifndef AMATERIA_HPP
#define AMATERIA_HPP

/* ---- Abstract Class in C++ ----
- Is a class that has at least one pure virtual function, so it cannot be
instantiated directly.
- Can have implemented methods and member variables.
- Serves as a base class that provides some default behavior or common data
along with an interface.
- Allows partial implementation to be shared by derived classes. */

#include "ICharacter.hpp"
#include <string>

class AMateria {
  protected:
    std::string _type;

    /* Here I am making the choice to keep the copy and assignment op
    constructors protected to prevent object slicing. Even though object slicing
    can be resolve thorugh passing object by reference this design approach will
    stop the problem happening in the first place rather than solving it in a
    later stage */
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);

  public:
    AMateria(std::string const& type);
    virtual ~AMateria(); // 'virtual' beacuse its the base class

    std::string const& getType() const;

    virtual AMateria* clone() const = 0; // making the class abstract

    /* AMateria is just an abstract concept, not a real item. It doesn't have a
     * specific action of its own. The purpose of defining virtual void use(...)
     * in the base class is to create a contract. It guarantees that any
     * concrete class that inherits from AMateria (like Ice or Cure) will have a
     * use() function. The specific actions, like shooting an ice bolt, are then
     * defined in those derived classes. */
    virtual void use(ICharacter& target);
};

#endif

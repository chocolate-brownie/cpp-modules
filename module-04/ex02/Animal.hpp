#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
  protected:
    std::string type;

  public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    /* Making the method virtual allows the derived classes to access this
    function and modifies thus activating the polymorphic feature */
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif

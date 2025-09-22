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

    /* Declaring the base class destructor as virtual ensures correct destructor
    chaining when deleting derived objects via base pointers.*/
    virtual ~Animal();

    /* Making the method virtual allows the derived classes to access this
    function and modifies thus activating the polymorphic feature */
    virtual void makeSound() const;

    std::string getType() const;
};

#endif

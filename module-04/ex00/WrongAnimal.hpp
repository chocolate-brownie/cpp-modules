#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
  protected:
    std::string type;

  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();

    /* Making the method virtual allows the derived classes to access this
    function and modifies thus activating the polymorphic feature */
    void makeSound() const;

    std::string getType() const;
};

#endif

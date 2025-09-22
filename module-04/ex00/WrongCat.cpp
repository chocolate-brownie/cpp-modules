#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat DEFAULT Constructed called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat COPY Constructed called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat COPY ASSIGN OP called" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat DESTRUCTOR called" << std::endl;
}

/* ************************************************************************** */
/* */
/* Member functions */
/* */
/* ************************************************************************** */
void WrongCat::makeSound() const {
    std::cout << "Wrongcat Meows!" << std::endl;
}

#include "WrongCat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << Color::CYAN << "WrongCat DEFAULT Constructed called"
              << Color::RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << Color::CYAN << "WrongCat COPY Constructed called"
              << Color::RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << Color::CYAN << "WrongCat COPY ASSIGN OP called" << Color::RESET
              << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << Color::CYAN << "WrongCat DESTRUCTOR called" << Color::RESET
              << std::endl;
}

/* ************************************************************************** */
/* */
/* Member functions */
/* */
/* ************************************************************************** */
void WrongCat::makeSound() const {
    std::cout << "Wrongcat Meows!" << std::endl;
}

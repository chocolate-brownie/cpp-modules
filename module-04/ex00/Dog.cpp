#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Dog::Dog() {
    type = "Dog";
    std::cout << Color::CYAN << "Dog DEFAULT Constructed called" << Color::RESET << std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
    std::cout << Color::CYAN << "Dog COPY Constructed called" << Color::RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << Color::CYAN << "Dog COPY ASSIGN OP called" << Color::RESET << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << Color::CYAN << "Dog DESTRUCTOR called" << Color::RESET << std::endl;
}

/* ************************************************************************** */
/* */
/* Member functions */
/* */
/* ************************************************************************** */
void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}

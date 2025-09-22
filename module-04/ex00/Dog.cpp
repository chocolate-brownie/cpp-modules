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
    std::cout << "Dog DEFAULT Constructed called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog COPY Constructed called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog COPY ASSIGN OP called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() { std::cout << "Dog DESTRUCTOR called" << std::endl; }

/* ************************************************************************** */
/* */
/* Member functions */
/* */
/* ************************************************************************** */
void Dog::makeSound() const { std::cout << "Woof Woof!" << std::endl; }

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Cat::Cat() {
    type = "Cat";
    std::cout << "Cat DEFAULT Constructed called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat COPY Constructed called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat COPY ASSIGN OP called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() { std::cout << "Cat DESTRUCTOR called" << std::endl; }

/* ************************************************************************** */
/* */
/* Member functions */
/* */
/* ************************************************************************** */
void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

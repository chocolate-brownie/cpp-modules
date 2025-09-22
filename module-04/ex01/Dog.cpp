#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Dog::Dog() : brain(new Brain) {
    type = "Dog";
    std::cout << "Dog DEFAULT Constructed called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog COPY Constructed called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog COPY ASSIGN OP called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog DESTRUCTOR called" << std::endl;
    delete brain;
}

/* ************************************************************************** */
/* */
/* Member functions */
/* */
/* ************************************************************************** */
void Dog::makeSound() const { std::cout << "Woof Woof!" << std::endl; }

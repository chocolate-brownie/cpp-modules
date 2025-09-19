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
    std::cout << Color::CYAN << "Dog DEFAULT Constructed called" << Color::RESET
              << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << Color::CYAN << "Dog COPY Constructed called" << Color::RESET
              << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << Color::CYAN << "Dog COPY ASSIGN OP called" << Color::RESET
              << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << Color::CYAN << "Dog DESTRUCTOR called" << Color::RESET
              << std::endl;
    delete brain;
}

/* ************************************************************************** */
/* */
/* Member functions */
/* */
/* ************************************************************************** */
void Dog::makeSound() const { std::cout << "Woof Woof!" << std::endl; }

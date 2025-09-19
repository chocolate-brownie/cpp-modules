#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Cat::Cat() : brain(new Brain) {
    type = "Cat";
    std::cout << Color::CYAN << "Cat DEFAULT Constructed called" << Color::RESET
              << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << Color::CYAN << "Cat COPY Constructed called" << Color::RESET
              << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << Color::CYAN << "Cat COPY ASSIGN OP called" << Color::RESET
              << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << Color::CYAN << "Cat DESTRUCTOR called" << Color::RESET
              << std::endl;
    delete brain;
}

/* ************************************************************************** */
/* */
/* Member functions */
/* */
/* ************************************************************************** */
void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

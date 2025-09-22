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
    std::cout << "Cat DEFAULT Constructed called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat COPY Constructed called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat COPY ASSIGN OP called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        // *brain = *other.brain;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat DESTRUCTOR called, cleaning brain" << std::endl;
    delete brain;
}

/* ************************************************************************** */
/* */
/* Member functions */
/* */
/* ************************************************************************** */
void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

/* ************************************************************************** */
/* */
/* Some functions to check the Idea attribute */
/* */
/* ************************************************************************** */
void Cat::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) brain->ideas[index] = idea;
}

void Cat::printIdea(int index) const {
    if (index >= 0 && index < 100)
        std::cout << "Idea #" << index << ": " << brain->ideas[index]
                  << std::endl;
}

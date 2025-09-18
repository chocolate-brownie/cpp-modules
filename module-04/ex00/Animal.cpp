#include "Animal.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Animal::Animal() : type("Animal") {
    std::cout << Color::CYAN << "Animal DEFAULT Constructed called"
              << Color::RESET << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << Color::CYAN << "Animal COPY Constructed called" << Color::RESET
              << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << Color::CYAN << "Animal COPY ASSIGN OP called" << Color::RESET
              << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << Color::CYAN << "Animal Destructor called" << Color::RESET
              << std::endl;
}

/* ************************************************************************** */
/* */
/* Member methods */
/* */
/* ************************************************************************** */
void Animal::makeSound() const {
    std::cout << this->type << " is making sound!" << std::endl;
}

std::string Animal::getType() const { return this->type; }

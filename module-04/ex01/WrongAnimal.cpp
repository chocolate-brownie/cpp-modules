#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << Color::CYAN << "WrongAnimal DEFAULT Constructed called"
              << Color::RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << Color::CYAN << "WrongAnimal COPY Constructed called"
              << Color::RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << Color::CYAN << "WrongAnimal COPY ASSIGN OP called"
              << Color::RESET << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << Color::CYAN << "WrongAnimal Destructor called" << Color::RESET
              << std::endl;
}

/* ************************************************************************** */
/* */
/* Member methods */
/* */
/* ************************************************************************** */
void WrongAnimal::makeSound() const {
    std::cout << this->type << " is making sound!" << std::endl;
}

std::string WrongAnimal::getType() const { return this->type; }

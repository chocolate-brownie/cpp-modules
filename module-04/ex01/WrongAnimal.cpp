#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal DEFAULT Constructed called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal COPY Constructed called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal COPY ASSIGN OP called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor called" << std::endl;
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

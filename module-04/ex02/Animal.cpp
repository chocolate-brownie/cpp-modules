#include "Animal.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Animal::Animal() : type("Animal") {
    std::cout << "Animal DEFAULT Constructed called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal COPY Constructed called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal COPY ASSIGN OP called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() { std::cout << "Animal Destructor called" << std::endl; }

/* ************************************************************************** */
/* */
/* Member methods */
/* */
/* ************************************************************************** */
/*
void Animal::makeSound() const {
    std::cout << this->type << " is making sound!" << std::endl;
}
 */
std::string Animal::getType() const { return this->type; }

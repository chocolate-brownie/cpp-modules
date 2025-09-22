#include "../include/Ice.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Ice::Ice() : AMateria("ice") {
    std::cout << "Ice DEFAULT constructor called." << std::endl;
    return;
}
Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "Cure COPY constructor called." << std::endl;
    return;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "Cure COPY ASSIGNMENT OPERATOR called." << std::endl;
    if (this != &other) AMateria::operator=(other);
    return *this;
}

Ice::~Ice() {
    std::cout << "Cure destructor called." << std::endl;
    return;
}

/* ************************************************************************** */
/* */
/* Other member methods */
/* */
/* ************************************************************************** */
AMateria* Ice::clone() const { return new Ice(*this); }
void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}

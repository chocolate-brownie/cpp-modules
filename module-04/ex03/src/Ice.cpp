#include "../include/Ice.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Ice::Ice() : AMateria("ice") { return; }
Ice::Ice(const Ice& other) : AMateria(other) { return; }

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) AMateria::operator=(other);
    return *this;
}

Ice::~Ice() { return; }

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

#include "../include/Ice.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Ice::Ice() : AMateria("ice") {
    std::cout << Color::GREEN << "Ice DEFAULT constructor called."
              << Color::RESET << std::endl;
    return;
}
Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << Color::YELLOW << "Cure COPY constructor called."
              << Color::RESET << std::endl;
    return;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << Color::MAGENTA << "Cure COPY ASSIGNMENT OPERATOR called."
              << Color::RESET << std::endl;
    if (this != &other) AMateria::operator=(other);
    return *this;
}

Ice::~Ice() {
    std::cout << Color::RED << "Cure destructor called." << Color::RESET
              << std::endl;
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

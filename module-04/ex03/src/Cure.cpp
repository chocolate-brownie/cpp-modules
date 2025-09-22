#include "../include/Cure.hpp"
#include <iostream>
#include <ostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Cure::Cure() : AMateria("cure") {
    std::cout << "Cure DEFAULT constructor called." << std::endl;
    return;
}
Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "Cure COPY constructor called." << std::endl;
    return;
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "Cure COPY ASSIGNMENT OPERATOR called." << std::endl;
    if (this != &other) AMateria::operator=(other);
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destructor called." << std::endl;
    return;
}

/* ************************************************************************** */
/* */
/* Other member methods */
/* */
/* ************************************************************************** */
AMateria* Cure::clone() const { return new Cure(*this); }
void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

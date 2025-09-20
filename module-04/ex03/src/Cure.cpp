#include "../include/Cure.hpp"
#include <iostream>
#include <ostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Cure::Cure() : AMateria("cure") { return; }
Cure::Cure(const Cure& other) : AMateria(other) { return; }

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) AMateria::operator=(other);
    return *this;
}

Cure::~Cure() { return; }

/* ************************************************************************** */
/* */
/* Other member methods */
/* */
/* ************************************************************************** */
AMateria* Cure::clone() const { return new Cure(*this); }
void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

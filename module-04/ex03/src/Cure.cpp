#include "../include/Cure.hpp"
#include <iostream>
#include <ostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Cure::Cure() : AMateria("cure") {
    std::cout << Color::GREEN << "Cure DEFAULT constructor called."
              << Color::RESET << std::endl;
    return;
}
Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << Color::YELLOW << "Cure COPY constructor called."
              << Color::RESET << std::endl;
    return;
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << Color::MAGENTA << "Cure COPY ASSIGNMENT OPERATOR called."
              << Color::RESET << std::endl;
    if (this != &other) AMateria::operator=(other);
    return *this;
}

Cure::~Cure() {
    std::cout << Color::RED << "Cure destructor called." << Color::RESET
              << std::endl;
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

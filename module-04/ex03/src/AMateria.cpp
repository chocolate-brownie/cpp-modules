#include "../include/AMateria.hpp"
#include <iostream>
/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */

AMateria::AMateria(std::string const& type) : _type(type) {
    std::cout << "AMateria DEFAULT constructor called." << std::endl;
}
AMateria::AMateria(const AMateria& other) : _type(other.getType()) {
    std::cout << "AMateria COPY constructor called." << std::endl;
    return;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria COPY ASSIGNMENT OPERATOR called." << std::endl;
    if (this != &other) _type = (other.getType());
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called." << std::endl;
}

/* ************************************************************************** */
/* */
/* Other member methods */
/* */
/* ************************************************************************** */

void AMateria::use(ICharacter&) { return; }

std::string const& AMateria::getType() const { return _type; }

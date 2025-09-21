#include "../include/AMateria.hpp"
#include <iostream>
/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */

AMateria::AMateria(std::string const& type) : _type(type) {
    std::cout << Color::GREEN << "AMateria DEFAULT constructor called."
              << Color::RESET << std::endl;
}
AMateria::AMateria(const AMateria& other) : _type(other.getType()) {
    std::cout << Color::YELLOW << "AMateria COPY constructor called."
              << Color::RESET << std::endl;
    return;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << Color::MAGENTA << "AMateria COPY ASSIGNMENT OPERATOR called."
              << Color::RESET << std::endl;
    if (this != &other) _type = (other.getType());
    return *this;
}

AMateria::~AMateria() {
    std::cout << Color::RED << "AMateria destructor called." << Color::RESET
              << std::endl;
}

/* ************************************************************************** */
/* */
/* Other member methods */
/* */
/* ************************************************************************** */

void AMateria::use(ICharacter&) { return; }

std::string const& AMateria::getType() const { return _type; }

#include "../include/AMateria.hpp"
/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */

AMateria::AMateria(std::string const& type) : _type(type) { return; }
AMateria::AMateria(const AMateria& other) : _type(other.getType()) { return; }

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) _type = (other.getType());
    return *this;
}

AMateria::~AMateria() {}

/* ************************************************************************** */
/* */
/* Other member methods */
/* */
/* ************************************************************************** */

void AMateria::use(ICharacter&) { return; }

std::string const& AMateria::getType() const { return _type; }

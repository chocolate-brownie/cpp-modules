#include "../include/Character.hpp"

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Character::Character(const std::string charName) : _charName(charName) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = nullptr;
    return;
}

Character::Character(const Character& other) {}

Character& Character::operator=(const Character& other) { return *this; }

Character::~Character() {}

/* ************************************************************************** */
/* */
/* Other member methods */
/* */
/* ************************************************************************** */
std::string const& Character::getName() const { return _charName; }

void Character::equip(AMateria* m) {}

void Character::unequip(int idx) {}

void Character::use(int idx, ICharacter& target) {}

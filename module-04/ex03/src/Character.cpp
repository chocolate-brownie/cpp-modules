#include "../include/Character.hpp"
#include "../include/AMateria.hpp"
#include <iostream>
#include <ostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
Character::Character(const std::string charName) : _charName(charName) {
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
    return;
}

Character::Character(const Character& other) : _charName(other._charName) {
    for (int i = 0; i < 4; ++i) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _charName = other._charName;

        for (int i = 0; i < 4; ++i)
            delete _inventory[i];

        for (int i = 0; i < 4; ++i) {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i)
        delete _inventory[i];
}

/* ************************************************************************** */
/* */
/* Other member methods */
/* */
/* ************************************************************************** */
std::string const& Character::getName() const { return _charName; }

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i] == 0) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if ((idx >= 0 && idx <= 3) && _inventory[idx])
        _inventory[idx] = 0;
    else
        std::cout << "Error: Index is out of range" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    if ((idx >= 0 && idx <= 3) && _inventory[idx])
        _inventory[idx]->use(target);
    else
        std::cout << "Error: Index is out of range" << std::endl;
}

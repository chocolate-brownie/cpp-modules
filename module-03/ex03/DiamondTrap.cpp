#include "DiamondTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/* ************************************************************************** */
/* */
/* OCF functions*/
/* */
/* ************************************************************************** */
DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
    this->name = "Default";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;

    std::cout << Color::MAGENTA << Color::BOLD
              << "DiamondTrap DEFAULT constructor called for " << this->name
              << Color::RESET << std::endl;
    return;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    /* A child class's copy constructor must first call its parent's copy
     * constructor (to copy the inherited parts) and then manually copy its own
     * unique members.*/
    this->name = other.name;

    std::cout << Color::MAGENTA << Color::BOLD
              << "DiamondTrap COPY constructor called" << Color::RESET
              << std::endl;
    return;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->name = other.name;
    }

    std::cout << Color::MAGENTA << Color::BOLD
              << "DiamondTrap COPY ASSIGNMENT OPERATOR called" << Color::RESET
              << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << Color::MAGENTA << Color::BOLD
              << "DiamondTrap DESTRUCTOR is called for " << this->name
              << Color::RESET << std::endl;
    return;
}

/* ************************************************************************** */
/* */
/* constructor with the name*/
/* */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << Color::MAGENTA << Color::BOLD
              << "DiamondTrap NAME CONSTRUCTOR is called for " << this->name
              << Color::RESET << std::endl;
    return;
}

/* ************************************************************************** */
/* */
/* Other member functions */
/* */
/* ************************************************************************** */

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
    return;
}

void DiamondTrap::whoAmI() {
    std::cout << Color::CYAN << "My DiamondTrap name is: " << this->name
              << Color::RESET << std::endl;
    std::cout << Color::CYAN << "My ClapTrap name is: " << ClapTrap::name
              << Color::RESET << std::endl;
    return;
}

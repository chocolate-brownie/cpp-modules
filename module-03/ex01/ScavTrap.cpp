#include "ScavTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"
/* ************************************************************************** */
/* */
/* OCF functions */
/* */
/* ************************************************************************** */

ScavTrap::ScavTrap(void) : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << Color::BOLD << "ScavTrap DEFAULT constructor called"
              << Color::RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << Color::BOLD << "ScavTrap COPY constructor called"
              << Color::RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << Color::BOLD << "ScavTrap COPY ASSIGNMENT OPERATOR called"
              << Color::RESET << std::endl;
    /* If you didn't call ClapTrap::operator=, you would have to manually copy
     * every single member that ScavTrap inherits. Your code would look like
     * this:


    -- The manual, repetitive, and fragile way --

    ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
        if (this != &other) {
            // Manually copy all inherited members
            this->name = other.name;
            this->hitPoints = other.hitPoints;
            this->energyPoints = other.energyPoints;
            this->attackDamage = other.attackDamage;
        }
        return *this;
    } */

    if (this != &other) ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << Color::BOLD << "ScavTrap destructor called for " << this->name
              << Color::RESET << std::endl;
}

/* ************************************************************************** */
/* */
/* Name constructor */
/* */
/* ************************************************************************** */

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << Color::BOLD << "ScavTrap NAME constructor called for "
              << this->name << Color::RESET << std::endl;
}

/* ************************************************************************** */
/* */
/* Other member functions of the ScavTrap */
/* */
/* ************************************************************************** */

void ScavTrap::attack(const std::string& target) {
    if (this->hitPoints == 0 || this->energyPoints == 0) {
        std::cout << Color::RED << "ScavTrap " << this->name << " can't act!"
                  << Color::RESET << std::endl;
        return;
    }

    std::cout << std::endl
              << Color::GREEN << "ScavTrap " << this->name << " attacks "
              << target << ", causing " << this->attackDamage
              << " points of damage!" << Color::RESET << std::endl;
    this->energyPoints--;
    return;
}

void ScavTrap::guardGate() {
    std::cout << Color::BLUE << "ScavTrap is now in Gate keeper mode."
              << Color::RESET << std::endl;
    return;
}

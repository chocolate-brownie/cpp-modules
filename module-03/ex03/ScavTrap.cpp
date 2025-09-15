#include "ScavTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"
/* ************************************************************************** */
/* */
/* OCF functions and the name constructor */
/* */
/* ************************************************************************** */

ScavTrap::ScavTrap(void) : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << Color::BOLD << "ScavTrap DEFAULT constructor called"
              << Color::RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << Color::BOLD << "ScavTrap NAME constructor called for "
              << this->name << Color::RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << Color::BOLD << "ScavTrap COPY constructor called"
              << Color::RESET << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << Color::BOLD << "ScavTrap destructor called for " << this->name
              << Color::RESET << std::endl;
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

#include "FragTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"

/* ************************************************************************** */
/* */
/* OCF functions*/
/* */
/* ************************************************************************** */
FragTrap::FragTrap(void) : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << Color::BOLD << "FragTrap DEFAULT constructor called"
              << Color::RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << Color::BOLD << "FragTrap COPY constructor called"
              << Color::RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << Color::BOLD << "FragTrap COPY ASSIGNMENT OPERATOR called"
              << Color::RESET << std::endl;
    if (this != &other) ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << Color::BOLD << "FragTrap destructor called for " << this->name
              << Color::RESET << std::endl;
}

/* ************************************************************************** */
/* */
/* Name Constructor*/
/* */
/* ************************************************************************** */
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << Color::BOLD << "FragTrap NAME constructor called for "
              << this->name << Color::RESET << std::endl;
}

/* ************************************************************************** */
/* */
/* Member functions*/
/* */
/* ************************************************************************** */
void FragTrap::attack(const std::string& target) {
    if (this->hitPoints == 0 || this->energyPoints == 0) {
        std::cout << Color::RED << "FragTrap " << this->name << " can't act!"
                  << Color::RESET << std::endl;
        return;
    }

    std::cout << std::endl
              << Color::GREEN << "FragTrap " << this->name << " attacks "
              << target << ", causing " << this->attackDamage
              << " points of damage!" << Color::RESET << std::endl;
    this->energyPoints--;
    return;
}

void FragTrap::highFivesGuys(void) {
    std::cout << Color::BLUE << "High Five!!!" << Color::RESET << std::endl;
    return;
}

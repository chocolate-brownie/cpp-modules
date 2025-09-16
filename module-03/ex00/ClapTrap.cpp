#include "ClapTrap.hpp"

#include <cerrno>
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form Methods                                            */
/* */
/* ************************************************************************** */
ClapTrap::ClapTrap(void)
    : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << Color::BOLD << "Default constructor called" << Color::RESET
              << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name),
      hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage) {
    std::cout << Color::GREEN << "Copy constructor called" << Color::RESET
              << std::endl;
    return;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << Color::GREEN << "Copy assignment operator called"
              << Color::RESET << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << Color::GREEN << "Destructor called" << Color::RESET
              << std::endl;
}

/* ************************************************************************** */
/* */
/* Name, which is passed as a parameter to the constructor */
/* */
/* ************************************************************************** */
ClapTrap::ClapTrap(std::string objName)
    : name(objName), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << Color::BOLD << "Name constructor called" << Color::RESET
              << std::endl;
    return;
}

/* ************************************************************************** */
/* */
/* All the other member functions */
/* */
/* ************************************************************************** */
void ClapTrap::attack(const std::string& target) {
    std::cout << std::endl;
    if (this->hitPoints > 0 && this->energyPoints > 0) {
        std::cout << Color::BLUE << "ClapTrap " << this->name << " attacks "
                  << target << ", causing " << this->attackDamage
                  << " points of damage!" << Color::RESET << std::endl;

        energyPoints--;

        return;
    }
    std::cout << "ClapTrap " << this->name << " unable to attack " << target
              << ". due to lack of ENERGY POINTS or HIT POINTS." << std::endl;
    std::cout << "Energy Points: " << this->energyPoints << std::endl;
    std::cout << "Hit Points: " << this->hitPoints << std::endl;
    return;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << std::endl;

    if (hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " has already died"
                  << std::endl;
        return;
    }

    if (amount >= hitPoints) {
        hitPoints = 0;
        std::cout << Color::RED << "ClapTrap " << this->name << " took "
                  << amount << " damage and has died." << Color::RESET
                  << std::endl;
    } else {
        hitPoints -= amount;
        std::cout << Color::RED << "ClapTrap " << this->name << " is taking "
                  << amount << " damage... " << hitPoints << " HP remaining!"
                  << Color::RESET << std::endl;
    }
    return;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints == 0) {
        std::cout << Color::RED
                  << "Unable to repair due to lack of energy points."
                  << Color::RESET << std::endl;
        return;
    }
    if (hitPoints == 0) {
        std::cout << Color::RED << "Unable to repair because ClapTrap is dead."
                  << Color::RESET << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << Color::GREEN << "ClapTrap " << this->name << " repairs... "
              << this->hitPoints << " HP remaining" << Color::RESET
              << std::endl;
    return;
}

/* ************************************************************************** */
/* */
/* Getter functions for debugging purpose */
/* */
/* ************************************************************************** */
std::string ClapTrap::getName() const { return this->name; }
unsigned int ClapTrap::getHitPoints() const { return this->hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return this->energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return this->attackDamage; }

#include "Brain.hpp"
#include "Animal.hpp"

#include <iostream>

Brain::Brain() {
    std::cout << Color::YELLOW << "Brain DEFAULT constructor called"
              << Color::RESET << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << Color::YELLOW << "Brain COPY constructor called"
              << Color::RESET << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << Color::YELLOW << "Brain COPY ASSIGNMENT OPERATOR called"
              << Color::RESET << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << Color::YELLOW << "Brain DESTRUCTOR called" << Color::RESET
              << std::endl;
}

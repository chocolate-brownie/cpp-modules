#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain DEFAULT constructor called" << std::endl; }

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "Brain COPY constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain COPY ASSIGNMENT OPERATOR called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() { std::cout << "Brain DESTRUCTOR called" << std::endl; }

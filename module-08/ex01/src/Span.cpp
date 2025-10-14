#include "../include/Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) : maxCapacity(N) { vec.reserve(maxCapacity); }

Span::Span(const Span& other) : maxCapacity(other.maxCapacity), vec(other.vec) { return; }

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        maxCapacity = other.maxCapacity;
        vec = other.vec;
    }
    return *this;
}

Span::~Span() { return; };

/*-------------------------------------------------------------------------------------*/
const std::vector<unsigned int>::iterator Span::getMinIt() {
    if (vec.empty()) throw std::runtime_error("Vector is empty");
    minIt = std::min_element(vec.begin(), vec.end());
    return minIt;
}

const std::vector<unsigned int>::iterator Span::getMaxIt() {
    if (vec.empty()) throw std::runtime_error("Vector is empty");
    maxIt = std::max_element(vec.begin(), vec.end());
    return maxIt;
}

void Span::addNumber(unsigned int value) {
    if (vec.size() >= maxCapacity) throw ContainerIsFull();
    vec.push_back(value);
}

unsigned int Span::longestSpan() { return *getMaxIt() - *getMinIt(); }

unsigned int Span::shortestSpan() {
    if (vec.size() < 2) throw InvalidContainerSize();
    std::vector<unsigned int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    unsigned int shortest = *(sortedVec.begin() + 1) - *sortedVec.begin();

    for (std::vector<unsigned int>::iterator it = sortedVec.begin() + 2;
         it != sortedVec.end(); ++it) {
        unsigned int currentSpan = *it - *(it - 1);
        if (currentSpan < shortest) { shortest = currentSpan; }
    }
    return shortest;
}

/*-------------------------------------------------------------------------------------*/
const char* Span::ContainerIsFull::what() const throw() {
    return "cannot add more values, container is full!";
}

const char* Span::InvalidContainerSize::what() const throw() {
    return "invalid container size for this operation";
}

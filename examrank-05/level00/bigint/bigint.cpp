#include "bigint.hpp"

bigint::bigint() 
{ 
    container.push_back(0); 
}

bigint::bigint(const bigint& other): container(other.container) {}

bigint &bigint::operator=(const bigint &other)
{
    if (this != &other)
        container = other.container;
    return *this;        
}

bigint::bigint(unsigned int n)
{
    size_t i = 0;
    while (i < n)
    {
        container.push_back(n % 10);
        n /= 10;
        i++;
    }
}

std::ostream &operator<<(std::ostream &os, const bigint &n) 
{
    size_t i = n.container.size();
    while (i > 0) {
        std::cout << n.container[i];
    }
    return os;
}

    
bigint::~bigint() {}
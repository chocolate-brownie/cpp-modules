#include "bigint.hpp"
#include <locale>
#include <vector>

bigint::bigint()
{
    numbers.push_back(0);
}

bigint::bigint(unsigned int n)
{
    numbers.push_back(n);
}

bigint::bigint(const bigint& other) : numbers(other.numbers) {}

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
        numbers = other.numbers;
    return *this;
}

bigint::~bigint() {}

std::ostream& operator<<(std::ostream& os, const bigint& value)
{
    for (std::vector<unsigned int>::const_reverse_iterator it = value.numbers.rbegin();
         it != value.numbers.rend(); ++it)
    {
        os << *it;
    }
    return os;
}

/*---------------------------------------------------------------------------------------------- */
bigint  bigint::operator+(const bigint& other) const {
}

#include "bigint.hpp"

bigint::bigint()
{
    container.push_back(0);
}

bigint::bigint(const bigint& other) : container(other.container) {}

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
        container = other.container;
    return *this;
}

bigint::bigint(unsigned int n)
{
    size_t i = 0;
    while (n > 0)
    {
        container.push_back(n % 10);
        n /= 10;
        i++;
    }
}

bigint& bigint::operator+=(const bigint& other)
{
    unsigned int              carry = 0;
    std::vector<unsigned int> temp;
    size_t                    i = 0;

    while (i < container.size() || i < other.container.size() || carry > 0)
    {
        unsigned int num1 = (i < container.size()) ? container[i] : 0;
        unsigned int num2 = (i < other.container.size()) ? other.container[i] : 0;
        unsigned int sum  = num1 + num2 + carry;
        temp.push_back(sum % 10);
        carry = sum / 10;
        i++;
    }

    container = temp;
    return *this;
}

bigint bigint::operator+(const bigint& other) const
{
    return bigint(*this) += other;
}

bigint& bigint::operator++()
{
    return (*this) += 1;
}

bigint bigint::operator++(int)
{
    bigint temp = *this;
    ++(*this);
    return temp;
}

bigint& bigint::operator<<=(const bigint& other)
{
    unsigned int shift_amount = 0;

    for (size_t i = other.container.size(); i > 0; --i)
        shift_amount = shift_amount * 10 + other.container[i - 1];

    container.insert(container.begin(), shift_amount, 0);
    return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
    unsigned int shift_amount = 0;
    for (size_t i = other.container.size(); i > 0; --i)
        shift_amount = shift_amount * 10 + other.container[i - 1];

    container.erase(container.begin(), container.begin() + shift_amount);
    return *this;
}

bigint bigint::operator<<(const bigint& other) const
{
    return bigint(*this) <<= other;
}

bool bigint::operator==(const bigint& other) const
{
    if (container.size() != other.container.size())
        return false;

    for (size_t i = container.size(); i > 0; --i)
    {
        if (container[i - 1] != other.container[i - 1])
            return false;
    }

    return true;
}

bool bigint::operator!=(const bigint& other) const
{
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const
{
    if (container.size() != other.container.size())
        return container.size() < other.container.size();

    for (size_t i = container.size(); i > 0; --i)
    {
        if (container[i - 1] != other.container[i - 1])
            return container[i - 1] < other.container[i - 1];
    }

    return false;
}

bool bigint::operator<=(const bigint& other) const
{
    return (*this == other) || (*this < other);
}

bool bigint::operator>(const bigint& other) const
{
    return other < *this;
}

bool bigint::operator>=(const bigint& other) const
{
    return (*this == other) || (*this > other);
}

std::ostream& operator<<(std::ostream& os, const bigint& n)
{
    for (size_t i = n.container.size(); i > 0; --i)
        os << n.container[i - 1];
    return os;
}

bigint::~bigint() {}
#include "bigint.hpp"

bigint::bigint() {
    vec.push_back(0);
}

bigint::bigint(unsigned int n) {
    if (n == 0) {
        vec.push_back(0);
        return;
    }

    while (n > 0) {
        vec.push_back(static_cast<unsigned char>(n % 10));
        n /= 10;
    }
}


bigint::bigint(const bigint& other): vec(other.vec) {}

bigint& bigint::operator=(const bigint& other) {
    if (this != &other) 
        vec = other.vec;

    return *this;
}

bigint::~bigint() {}

bigint& bigint::operator+=(const bigint& other) {    
    size_t max_len = std::max(vec.size(), other.vec.size());
    int carry = 0;
    std::vector<unsigned char> result;

    for (size_t i = 0; i < max_len; ++i) {
        int num1 = (i < vec.size() ? vec[i] : 0);
        int num2 = (i < other.vec.size() ? other.vec[i] : 0);
        unsigned int sum = num1 + num2 + carry;

        result.push_back(sum % 10);
        carry = sum /= 10;
    }

    if (carry)
        result.push_back(carry);

    vec = result;
    return *this;
}

bigint bigint::operator+(const bigint& other) const {
    bigint temp = *this;
    temp += other;
    return temp;
}

bigint& bigint::operator++() {
    return (*this) += 1;
}

bigint bigint::operator++(int) {
    bigint temp = *this;
    ++(*this);
    return temp;
}

bigint& bigint::operator<<=(const bigint& other) {
    size_t shift_amount = 0;
    size_t multiplier = 1;
    for (size_t i = 0; i < other.vec.size(); ++i) {
        shift_amount += other.vec[i] * multiplier;
        multiplier *= 10;
    }

    vec.insert(vec.begin(), shift_amount, 0);
    return *this;
}

bigint& bigint::operator>>=(const bigint& other) {
    size_t shift_amount = 0;
    size_t multiplier = 1;
    for (size_t i = 0; i < other.vec.size(); ++i) {
        shift_amount += other.vec[i] * multiplier;
        multiplier *= 10;
    }

    if (shift_amount >= vec.size())
        vec.assign(1, 0);
    else 
        vec.erase(vec.begin(), vec.begin() + shift_amount);
    return *this;
}

bigint bigint::operator<<(const bigint& other) const {
    bigint temp = *this;
    temp <<= other;
    return temp;
}

bigint bigint::operator>>(const bigint& other) const {
    bigint temp = *this;
    temp >>= other;
    return temp;
}

bool bigint::operator<(const bigint& other) const {
    if (vec.size() != other.vec.size())
        return vec.size() < other.vec.size();

    for (size_t i = vec.size(); i > 0; --i) {
        if (vec[i - 1] != other.vec[i - 1])
            return vec[i - 1] < other.vec[i - 1];
    }

    return false;
}

bool bigint::operator==(const bigint& other) const {
    return vec == other.vec;
}

bool bigint::operator<=(const bigint& other) const {
    return (*this < other) || (*this == other);
}

bool bigint::operator!=(const bigint& other) const {
    return vec != other.vec;
}

bool bigint::operator>(const bigint& other) const {
    return other < *this;
}

bool bigint::operator>=(const bigint& other) const {
    return (*this > other) || (*this == other);
}

std::ostream& operator<<(std::ostream& os, const bigint& obj) {
    std::vector<unsigned char>::const_reverse_iterator it = obj.vec.rbegin();
    for (; it != obj.vec.rend(); ++it)
        os << static_cast<unsigned char>(*it + '0');
    return os;
}

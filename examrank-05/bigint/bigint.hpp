#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <ostream>
#include <vector>

class bigint {
private:
    std::vector<unsigned int> numbers;

public:
    std::vector<unsigned int> getNumbers();

    // addition
    bigint  operator+(const bigint& other) const;
    // bigint& operator+=(const bigint& other);

    bigint();
    bigint(unsigned int n);
    bigint(const bigint& other);
    bigint& operator=(const bigint& other);
    ~bigint();

    friend std::ostream& operator<<(std::ostream& os, const bigint& value);
};

std::ostream& operator<<(std::ostream& os, const bigint& value);
#endif

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <vector>
#include <iostream>

class bigint {
    private:
        std::vector<unsigned char> vec;

    public:
        bigint();
        bigint(unsigned int n);
        bigint(const bigint& other);
        bigint& operator=(const bigint& other);
        ~bigint();

        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);
        bigint& operator++();
        bigint operator++(int);

        bigint& operator<<=(const bigint& other);
        bigint& operator>>=(const bigint& other);
        bigint operator<<(const bigint& other) const;
        bigint operator>>(const bigint& other) const;

        bool operator<(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;

        friend std::ostream& operator<<(std::ostream& os, const bigint& obj);
};

#endif

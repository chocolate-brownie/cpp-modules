#ifndef bigint_hpp
#define bigint_hpp

#include <iostream>
#include <vector>

class bigint {
private:
    std::vector<unsigned int> container;

public:
    bigint();
    bigint(const bigint& other);
    bigint &operator=(const bigint& other);

    bigint(unsigned int n);

    friend std::ostream &operator<<(std::ostream &output, const bigint &obj);

    ~bigint();
};

#endif
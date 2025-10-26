#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>  // IWYU pragma: keep

class PmergeMe {
private:
public:
    void processAndSort(int argc, char** argv);

    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
};

#endif

#ifndef PMERGEMEDEQUE_HPP
#define PMERGEMEDEQUE_HPP

#include <deque>
#include <iostream>  // IWYU pragma: keep
#include <utility>
#include <vector>     // IWYU pragma: keep
#include <cstdlib>    // IWYU pragma: keep
#include <climits>    // IWYU pragma: keep
#include <cerrno>     // IWYU pragma: keep
#include <cctype>     // IWYU pragma: keep
#include <algorithm>  // IWYU pragma: keep
#include <cstddef>    // IWYU pragma: keep

class PmergeMeDeque {
private:
    std::deque<std::pair<unsigned int, unsigned int> > pairs;
    std::deque<unsigned int>                           finalChain;

    bool         hasStraggler;
    unsigned int straggler;

    void insertPendingElems();
    void pairAndCompare(int argc, char** argv);
    void recursivelySortMainChain();
    void recursivelySortMainChain(std::deque<std::pair<unsigned int, unsigned int> >& pairs,
                                  size_t left, size_t right, int depth);

public:
    PmergeMeDeque();
    ~PmergeMeDeque();
    PmergeMeDeque(const PmergeMeDeque& other);
    PmergeMeDeque& operator=(const PmergeMeDeque& other);

    template <typename Container>
    void printContainer(const Container& container) const
    {
        typename Container::const_iterator it  = container.begin();
        typename Container::const_iterator end = container.end();

        for (; it != end; ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    void processAndSort(int argc, char** argv);
    void printFinalResult() const;
};

#endif

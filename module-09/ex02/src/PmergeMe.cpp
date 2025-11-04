#include "../include/PmergeMe.hpp"
#include <utility>
#include <vector>

/* I would go through the args(size) and push them into a vector as pairs.
 * At the end it should looks like this:[ (5, 3), (9, 7), (4, 2) ] the first
 * position would be in the main chain and the 2nd one would be in pending
 * chain */
void PmergeMe::makePairs(int argc, char** argv)
{
    /* Finding the correct size of the thing, checking whether we will remain
     * with a straggler */
    int size     = argc - 1;
    hasStraggler = (size % 2 != 0);
    if (hasStraggler)
    {
        straggler = ft_strtoul(argv[argc - 1]);
        size -= 1;
    }

    pairs.reserve(size / 2);  // not necessary but whatever
    for (int i = 1; i <= size; i += 2)
    {
        unsigned int first  = ft_strtoul(argv[i]);
        unsigned int second = ft_strtoul(argv[i + 1]);

        if (first < second)
            std::swap(first, second);

        pairs.push_back(std::make_pair(first, second));
    }

#ifdef DEBUG
    std::cout << "Initial Pairs (Larger, Smaller):" << std::endl;
    for (size_t i = 0; i < pairs.size(); ++i)
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    std::cout << std::endl;
    if (hasStraggler)
        std::cout << "Straggler: " << straggler << std::endl;
#endif
}

void PmergeMe::processAndSort(int argc, char** argv)
{
    isValidUnsignedInt(argc, argv);
    makePairs(argc, argv);
    execFordJohnson(pairs);
}

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

/*
PmergeMe::PmergeMe(const PmergeMe& other) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    return *this;
}
*/

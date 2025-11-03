#include "../include/PmergeMe.hpp"
#include <utility>
#include <vector>

void PmergeMe::makePairs(char** argv, int size)
{

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
    // Go through the entire arguments and validate them before the compare and push
    isValidUnsignedInt(argc, argv);

    /* Finding the correct size of the thing, checking whether we will remain with a straggler */
    int size     = argc - 1;
    hasStraggler = (size % 2 != 0);
    if (hasStraggler)
    {
        straggler = ft_strtoul(argv[argc - 1]);
        size -= 1;
    }

    /* I would go through the args(size) and push them into a vector as pairs. At the end it should
     * looks like this:[ (5, 3), (9, 7), (4, 2) ] the first position would be in the main chain and
     * the 2nd one would be in pending chain */
    makePairs(argv, size);

    /* Recursively sort the pairs based on their LARGER element (This sets up the main chain order)
     * so if we take this example...
     *
     * Initial Pairs (Larger, Smaller):
     * (167, 12) (152, 89) (90, 71)
     * Straggler: 198
     *
     * the sorted should loook like this
     * (90, 71) (152, 89) (167, 12) */
    size_t half = pairs.size() / 2;

    std::vector<std::pair<unsigned int, unsigned int> >::iterator ptrMiddle = pairs.begin() + half;

    std::vector<std::pair<unsigned int, unsigned int> > first(pairs.begin(), ptrMiddle);
    std::vector<std::pair<unsigned int, unsigned int> > second(ptrMiddle, pairs.end());
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

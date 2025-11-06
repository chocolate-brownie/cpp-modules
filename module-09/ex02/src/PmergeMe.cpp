#include "../include/PmergeMe.hpp"
#include <cstddef>
#include <utility>
#include <vector>

void PmergeMe::pushElemsToChains()
{
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        main.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }

    std::cout << "\n\nMain chain:\t";
    printContainer(main);
    std::cout << "Pending chain:\t";
    printContainer(pending);

    return;
}

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

    std::cout << "Initial Pairs (Larger, Smaller):" << std::endl;
    for (size_t i = 0; i < pairs.size(); ++i)
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";

    std::cout << std::endl;

    if (hasStraggler)
        std::cout << "Straggler: " << straggler << std::endl;

    std::cout << std::endl;
}

void PmergeMe::processAndSort(int argc, char** argv)
{
    /* would go thorugh the entire thing and parse it to make sure its valid input */
    isValidUnsignedInt(argc, argv);

    /* then I would make an std::pair container by comparing each elems and whats next to it swap
     * them in the ascending order so I can have a semi sorted container with members sorted who are
     * next to each other */
    makePairs(argc, argv);

    /* I would take this std::pair and use the merge-sort algorithm to sort them in the ascending
     * order by comparing the pair.first elem in each pair */
    recursiveSortPair();
    std::cout << "\n[DEBUG] Sorted Pairs: merge-sort algo executed" << std::endl;
    for (size_t i = 0; i < pairs.size(); ++i)
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";

    /* Then I will push the pairs.first to a main chain and the pairs.second to the pending chain */
    pushElemsToChains();

    /* Then I have to take everyting from the pending chain put everything inside one main chain and
     * print them out  */
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

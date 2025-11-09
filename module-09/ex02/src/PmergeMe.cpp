#include "../include/PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

/* You dont really have to create two extra vectors called main chain and pending chain to do
 * the insertion, you can just have one chain called finalChain and push everything from the
 * pairs[i].first (which is essentially the main chain) pairs[i].second which is the pending
 * chain. You can do a comparePairs() function and use lower_bound() directly to do the
 * insertion
 */
void PmergeMe::insertPendingElems()
{
    std::cout << "\n[OPERATION]: Pushing pairs[i].first to the mainChain" << std::endl;
    for (size_t i = 0; i < pairs.size(); ++i)
        finalChain.push_back(pairs[i].first);

    std::cout << "[OPERATION]: Pushign pairs[i].second to the mainChain" << std::endl;
    if (!pairs.empty())
        finalChain.insert(finalChain.begin(), pairs[0].second);
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        unsigned int valueToInsert = pairs[i].second;

        std::vector<unsigned int>::iterator pos =
            std::lower_bound(finalChain.begin(), finalChain.end(), valueToInsert);
        finalChain.insert(pos, valueToInsert);
    }

    if (hasStraggler)
    {
        std::cout << "[OPERATION]: Adding straggler to the mainChain" << std::endl;
        std::vector<unsigned int>::iterator pos =
            std::lower_bound(finalChain.begin(), finalChain.end(), straggler);
        finalChain.insert(pos, straggler);
    }
    return;
}

/* I would go through the args(size) and push them into a vector as pairs.
 * At the end it should looks like this:[ (5, 3), (9, 7), (4, 2) ] the first
 * position would be in the main chain and the 2nd one would be in pending
 * chain */
void PmergeMe::pairAndCompare(int argc, char** argv)
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
    pairAndCompare(argc, argv);

    /* I would take this std::pair and use the merge-sort algorithm to sort them in the ascending
     * order by comparing the pair.first elem in each pair */
    recursivelySortMainChain();

    insertPendingElems();
    std::cout << "\n\n" << std::endl;
    printContainer(finalChain);
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

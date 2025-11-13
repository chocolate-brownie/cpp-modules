#include "../include/PmergeMeDeque.hpp"
#include "../include/PmergeMeUtils.hpp"
#include <algorithm>
#include <cstddef>
#include <deque>

void PmergeMeDeque::printFinalResult() const
{
    for (std::deque<unsigned int>::const_iterator it = finalChain.begin(); it != finalChain.end();
         ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMeDeque::insertPendingElems()
{
    std::cout << "\n[OPERATION]: Pushing pairs[i].first to the mainChain" << std::endl;
    for (size_t i = 0; i < pairs.size(); ++i)
        finalChain.push_back(pairs[i].first);

    if (!pairs.empty())
    {
        std::cout << "[OPERATION]: Pushing pairs[i].second to the mainChain" << std::endl;
        finalChain.insert(finalChain.begin(), pairs[0].second);
    }

    std::cout << "\n[OPERATION]: Creating the Jacobsthal Index Sequence" << std::endl;
    std::deque<unsigned int> jacobSeq =
        buildJacobInsertionSeq<std::deque<unsigned int> >(pairs.size());
    printContainer(jacobSeq);

    for (size_t seqIdx = 1; seqIdx < jacobSeq.size(); ++seqIdx)
    {
        size_t       i             = jacobSeq[seqIdx];
        unsigned int valueToInsert = pairs[i].second;

        std::deque<unsigned int>::iterator pos =
            lower_bound(finalChain.begin(), finalChain.end(), valueToInsert);
        finalChain.insert(pos, valueToInsert);
    }

    if (hasStraggler)
    {
        std::cout << "[OPERATION]: Adding straggler to the mainChain" << std::endl;
        std::deque<unsigned int>::iterator pos =
            std::lower_bound(finalChain.begin(), finalChain.end(), straggler);
        finalChain.insert(pos, straggler);
    }
}

/*
void PmergeMeDeque::insertPendingElems()
{
    std::cout << "\n[OPERATION]: Pushing pairs[i].first to the mainChain" << std::endl;
    for (size_t i = 0; i < pairs.size(); ++i)
        finalChain.push_back(pairs[i].first);

    std::cout << "[OPERATION]: Pushing pairs[i].second to the mainChain" << std::endl;
    if (!pairs.empty())
        finalChain.insert(finalChain.begin(), pairs[0].second);

    for (size_t i = 1; i < pairs.size(); ++i)
    {
        unsigned int valueToInsert = pairs[i].second;

        // lower_bound works with deque iterators
        std::deque<unsigned int>::iterator pos =
            std::lower_bound(finalChain.begin(), finalChain.end(), valueToInsert);
        finalChain.insert(pos, valueToInsert);
    }

    if (hasStraggler)
    {
        std::cout << "[OPERATION]: Adding straggler to the mainChain" << std::endl;
        std::deque<unsigned int>::iterator pos =
            std::lower_bound(finalChain.begin(), finalChain.end(), straggler);
        finalChain.insert(pos, straggler);
    }
}
*/

void PmergeMeDeque::pairAndCompare(int argc, char** argv)
{
    int size     = argc - 1;
    hasStraggler = (size % 2 != 0);
    if (hasStraggler)
    {
        straggler = ft_strtoul(argv[argc - 1]);
        size -= 1;
    }

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

void PmergeMeDeque::processAndSort(int argc, char** argv)
{
    isValidUnsignedInt(argc, argv);
    pairAndCompare(argc, argv);
    recursivelySortMainChain();
    insertPendingElems();
}

PmergeMeDeque::PmergeMeDeque() {}
PmergeMeDeque::~PmergeMeDeque() {}

/*
PmergeMe::PmergeMe(const PmergeMe& other) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    return *this;
}
*/

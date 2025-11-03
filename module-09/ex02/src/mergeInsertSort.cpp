#include "../include/PmergeMe.hpp"
/* Split the list into two halves (a left half and a right half).
 * Call your sort function recursively on the left half.
 * Call your sort function recursively on the right half.
 * Merge the two sorted halves back together.*/
 void PmergeMe::mergeInsertSortPairs(std::vector<std::pair<unsigned int, unsigned int> >& pairs, size_t left, size_t right) {

 }

void PmergeMe::mergeInsertSortPairs(std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{
    if (pairs.size() > 1)
        mergeInsertSortPairs(pairs);
}

#include "../include/PmergeMe.hpp"
#include <cstddef>
#include <utility>
#include <vector>

static void mergePairs(std::vector<std::pair<unsigned int, unsigned int> >& pairs, size_t left,
                       size_t mid, size_t right)
{
    return;
}

/* Recursively sort the pairs based on their LARGER element (This sets up
 * the main chain order) so if we take this example...
 *
 * Initial Pairs (Larger, Smaller):
 * (167, 12) (152, 89) (90, 71) (12, 32)
 * Straggler: 198
 *
 *
 * To do this I have to ...
 *
 * 1. Split the list into two halves (a left half and a right half).
 *      first half --> (167, 12) (152, 89)
 *      second half --> (90, 71) (12, 32)
 *
 * 2. Call your sort function recursively on the left half.
 *      first: has to be like (152, 89) (167, 12) comparing the first mem of the pair
 *
 * 3. Call your sort function recursively on the right half.
 *      second: has to be like (12, 32) (90, 71) comparing the first mem of the pair

 * 4. Merge the two sorted halves back together.
 *      the sorted should loook like this after merging
 *         (12, 32) (90, 71) (152, 89) (167, 12)
 * */
void PmergeMe::recursiveSortPair(std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{

    if (pairs.size() > 1)
        recursiveSortPair(pairs, 0, pairs.size() - 1);
}

void PmergeMe::recursiveSortPair(std::vector<std::pair<unsigned int, unsigned int> >& pairs,
                                 size_t left, size_t right)
{
    /* @note So this method is the easiest to understand but lack in performance due to new memory
     * allocation and copying all the pairs at every single step of the recursion.
     *
     * size_t half = pairs.size() / 2;
     *
     * std::vector<std::pair<unsigned int, unsigned int> >::iterator ptrMiddle = pairs.begin() +
     * half; std::vector<std::pair<unsigned int, unsigned int> > first(pairs.begin(), ptrMiddle);
     * std::vector<std::pair<unsigned int, unsigned int> > second(ptrMiddle, pairs.end());
     *
     * Indexing is the preferred way when writing the ford-johnson
     */

    if (left >= right)
        return;
    size_t mid = left + (right - left) / 2;  // finding the middle index
    recursiveSortPair(pairs, left, mid);
    recursiveSortPair(pairs, mid + 1, right);
    mergePairs(pairs, left, mid, right);
}

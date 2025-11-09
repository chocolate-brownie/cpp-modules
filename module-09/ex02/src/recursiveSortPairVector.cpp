#include "../include/PmergeMe.hpp"
#include <cstddef>
#include <utility>
#include <vector>

static void merge(std::vector<std::pair<unsigned int, unsigned int> >& pairs, size_t left,
                  size_t mid, size_t right)
{
    size_t totalElem = (right - left) + 1;
    size_t i         = left;
    size_t j         = mid + 1;
    size_t k         = 0;

    std::vector<std::pair<unsigned int, unsigned int> > temp(totalElem);

    while (i <= mid && j <= right)
    {
        if (pairs[i].first < pairs[j].first)
            temp[k++] = pairs[i++];
        else
            temp[k++] = pairs[j++];
    }

    while (i <= mid)
        temp[k++] = pairs[i++];

    while (j <= right)
        temp[k++] = pairs[j++];

    for (i = 0; i < totalElem; ++i)
        pairs[left + i] = temp[i];
}

// static void mergePairs(std::vector<std::pair<unsigned int, unsigned int> >& pairs, size_t left,
//                        size_t mid, size_t right)
// {
//     return;
// }

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
void PmergeMe::recursivelySortMainChain()
{
    if (pairs.size() > 1)
    {
        std::cout << "[DEBUG] Starting recursiveSortPair();" << std::endl;
        std::cout << "runnign first call ";
        std::cout << "left:[" << 0 << "] ";
        std::cout << "right:[" << pairs.size() - 1 << "]" << std::endl << std::endl;
        recursivelySortMainChain(pairs, 0, pairs.size() - 1, 0);
        std::cout << "[DEBUG] Ending recursiveSortPair();" << std::endl;
        std::cout << "--------------------------------------------------------" << std::endl;
        for (size_t i = 0; i < pairs.size(); ++i)
            std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    }

    return;
}

void PmergeMe::recursivelySortMainChain(std::vector<std::pair<unsigned int, unsigned int> >& pairs,
                                        size_t left, size_t right, int depth)
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

    std::string indent(depth * 4, ' ');

    std::cout << indent << "left:\t" << left << "\t";
    std::cout << "left:\t" << left << "\t";
    std::cout << "pairs[" << left << "].first = " << pairs[left].first << "\t";
    std::cout << "pairs[" << left << "].second = " << pairs[left].second << std::endl;

    std::cout << indent << "right:\t" << right << "\t";
    std::cout << "right:\t" << right << "\t";
    std::cout << "pairs[" << right << "].first = " << pairs[right].first << "\t";
    std::cout << "pairs[" << right << "].second = " << pairs[right].second << std::endl;

    if (left >= right)
    {
        std::cout << indent << "\n"
                  << indent << "left: " << left << " >= right: " << right << "\n"
                  << indent << "[BASE CASE] Returning.. Depth: " << depth << "\n"
                  << std::endl;

        return;
    }

    std::cout << indent << std::endl;
    std::cout << indent << "--------------------------------------------------------" << std::endl;
    size_t mid = left + (right - left) / 2;  // finding the middle index
    std::cout << indent << "mid:\t" << mid << "\t";
    std::cout << indent << "pairs[" << mid << "].first = " << pairs[mid].first << "\t";
    std::cout << indent << "pairs[" << mid << "].second = " << pairs[mid].second << std::endl;
    std::cout << indent << "--------------------------------------------------------" << std::endl;
    std::cout << indent << std::endl;

    // Call itself for the left half, INCREASING depth
    std::cout << indent << "[CALLING LEFT] recursiveSortPair(pairs, " << left << ", " << mid
              << ")\n"
              << std::endl;
    recursivelySortMainChain(pairs, left, mid, depth + 1);

    // Call itself for the right half, INCREASING depth
    std::cout << indent << "[CALLING RIGHT] recursiveSortPair(pairs, " << mid + 1 << ", " << right
              << ")\n"
              << std::endl;
    recursivelySortMainChain(pairs, mid + 1, right, depth + 1);

    // Merge: This is where your merge call will go.
    std::cout << indent << "[MERGING] mergePairs(pairs, " << left << ", " << mid << ", " << right
              << ")\n"
              << std::endl;
    merge(pairs, left, mid, right);

    std::cout << indent << "[RETURN] Finished call for sort(" << left << ", " << right << ")\n"
              << std::endl;
    return;
}

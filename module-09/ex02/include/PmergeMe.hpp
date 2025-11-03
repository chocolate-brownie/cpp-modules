
#ifndef PMERGEME_HPP
#define PMERGEME_HPP
/*
The Ford-Johnson algorithm (merge-insertion sort) is a sorting method designed
to minimize the number of element comparisons in the worst case. Here is how it
works “under the hood,” step by step:

### Step-by-step Internal Process

1. **Pair and Compare:**
   - Divide the input list into pairs of elements.
   - Compare each pair; place the larger element of each pair into a “main
chain” (a temporary sorted list) and the smaller element into a “pending” list
for later insertion.[1][2]

2. **Recursively Sort the Main Chain:**
   - The main chain (containing the larger elements from each pair) is
recursively sorted using the Ford-Johnson algorithm itself.

3. **Insert Pending Elements:**
   - The remaining "pending" smaller elements, plus any unpaired last element
(“straggler”), are inserted into their correct positions within the sorted main
chain.
   - The order of insertion is carefully selected, often using Jacobsthal
numbers, to minimize the number of comparisons required for finding the right
spot for each item.[2][1]

4. **Optimal Insertion:**
   - For each insertion, use binary search within the already sorted main chain
to find the correct position for each pending element.
   - Insertions are ordered so as to maximize the distance between the sections
of chain being searched, further reducing comparisons.

5. **Result:**
   - Once all pending elements are inserted, the chain is fully sorted.

### Visualization Example

- Suppose you have `[6, 15, 8, 16, 2, 11, 0, 17, ...]`.
- You pair and compare: `[11]`, `[12]`, `[13]`, `[14]`, etc.
    - Main chain: `[15, 16, 11, 17, ...]`
    - Pending list: `[6, 8, 2, 0, ...]`
- Recursively sort `[15, 16, 11, 17, ...]` the same way.
- Insert each pending element into the sorted chain using binary search,
following the Jacobsthal order for efficiency.[2]

### Why is it efficient?

- **Reduced comparison count:** By pairing and postponing insertions, the
algorithm performs fewer overall comparisons than traditional comparison
sorts.[1]
- **Recursion and mathematical ordering:** The clever use of number sequences
like Jacobsthal ensures that the insertions use as few comparisons as possible.

### Code-wise

- You need two containers: one for the main chain, one for the pending list.
- You use recursion to sort the chain and binary search for optimal insertions.
- Advanced implementations precisely follow the insertion order for minimal
comparisons.

***

For practical details and example code, see algorithm walkthroughs and method
breakdowns at references like , or official algorithm descriptions on Wikipedia
and algorithmic guides.[1][2]
*/
#include <iostream>  // IWYU pragma: keep
#include <utility>
#include <vector>   // IWYU pragma: keep
#include <cstdlib>  // IWYU pragma: keep
#include <climits>  // IWYU pragma: keep
#include <cerrno>   // IWYU pragma: keep
#include <cctype>   // IWYU pragma: keep

class PmergeMe {
private:
    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    std::vector<unsigned int>                           main;
    std::vector<unsigned int>                           pending;

    bool         hasStraggler;
    unsigned int straggler;

    bool isValidUnsignedInt(int argc, char** argv);
    void makePairs(char** argv, int size);

    void mergeInsertSortPairs(std::vector<std::pair<unsigned int, unsigned int> >& pairs,
                              size_t left, size_t right);

    // overload for a simple call
    void mergeInsertSortPairs(std::vector<std::pair<unsigned int, unsigned int> >& pairs);

    unsigned int ft_strtoul(const char* s);

public:
    void processAndSort(int argc, char** argv);

    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
};

#endif

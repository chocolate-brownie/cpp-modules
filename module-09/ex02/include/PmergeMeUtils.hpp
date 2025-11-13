#ifndef PMERGEMEUTILS_HPP
#define PMERGEMEUTILS_HPP

#include <iostream>   // IWYU pragma: keep
#include <vector>     // IWYU pragma: keep
#include <cstdlib>    // IWYU pragma: keep
#include <climits>    // IWYU pragma: keep
#include <cerrno>     // IWYU pragma: keep
#include <cctype>     // IWYU pragma: keep
#include <algorithm>  // IWYU pragma: keep
#include <cstddef>    // IWYU pragma: keep

bool         isValidUnsignedInt(int argc, char** argv);
unsigned int ft_strtoul(const char* s);

/* J0=0,J1=1,Jn=Jn−1+2Jn−2 for n≥sizeOfThePenList */
template <typename Container>
Container buildJacobInsertionSeq(std::size_t sizeOfThePenList)
{
    Container seq;
    if (sizeOfThePenList == 0)
        return seq;

    std::vector<size_t> j;
    j.push_back(0);
    j.push_back(1);

    // Generate the Jacob numbers e.g., [0, 1, 1, 3, 5, 11...]
    while (true)
    {
        size_t jnmin1   = j.back();
        size_t jnmin2   = j[j.size() - 2];
        size_t nextJnum = jnmin1 + (2 * jnmin2);

        if (nextJnum > sizeOfThePenList)
            break;

        j.push_back(nextJnum);
    }

    /* Use those numbers to build the falt insertion seq
    Loop through the jacob numbers (starting from J(3)=3). For each number, loop backwards from it
    down to the last number you added. */
    size_t lastIndexAdded = 0;
    seq.push_back(0);

    for (size_t i = 3; i < j.size(); ++i)
    {
        size_t jacobNum  = j[i];
        size_t jacobIndx = jacobNum - 1;

        for (size_t k = jacobIndx; k > lastIndexAdded; --k)
            seq.push_back(k);

        lastIndexAdded = jacobNum;
    }

    // Add the leftvoers (eg: if size is 6, this add p6(idx 5))
    for (size_t k = sizeOfThePenList - 1; k > lastIndexAdded; --k)
        seq.push_back(k);

    return seq;
}

#endif

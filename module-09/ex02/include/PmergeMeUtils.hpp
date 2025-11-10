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

/* J0=0,J1=1,Jn=Jn−1+2Jn−2 for n≥2 */
template <typename Container>
Container buildJacobInsertionSeq(std::size_t sizeOfThePenList)
{
    Container           seq;
    std::vector<size_t> jacob = {0, 1};

    for (size_t i = 1; i <= sizeOfThePenList; ++i)
    {
        jacob[i] = jacob[i - 1] + 2 * (jacob[i - 2]);
    }

    return seq;
}

#endif

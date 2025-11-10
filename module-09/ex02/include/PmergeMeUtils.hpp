#ifndef PMERGEMEUTILS_HPP
#define PMERGEMEUTILS_HPP

#include <iostream>  // IWYU pragma: keep
#include <vector>     // IWYU pragma: keep
#include <cstdlib>    // IWYU pragma: keep
#include <climits>    // IWYU pragma: keep
#include <cerrno>     // IWYU pragma: keep
#include <cctype>     // IWYU pragma: keep
#include <algorithm>  // IWYU pragma: keep
#include <cstddef>    // IWYU pragma: keep

bool isValidUnsignedInt(int argc, char** argv);
unsigned int ft_strtoul(const char* s);

template <typename Container>
Container buildJacobInsertionSeq(std::size_t n)
{
    Container seq;
    // ... logic to fill 'seq' with the Jacobsthal indices ...
    return seq;
}

#endif

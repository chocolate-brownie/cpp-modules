#include "../include/PmergeMe.hpp"
#include <stdexcept>

bool PmergeMe::isValidUnsignedInt(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        char* s = argv[i];
        while (std::isspace(static_cast<unsigned char>(*s)))
            ++s;

        if (*s == '-')
            throw std::runtime_error("[Invalid Argument]: negetive values are not allowed");

        if (*s == '+')
            ++s;

        if (*s == '\0')
            throw std::runtime_error("[Invalid Argument]: null arguments");

        if (!std::isdigit(static_cast<unsigned char>(*s)))
            throw std::runtime_error("[Invalid Argument]: not a digit");

        errno = 0;
        char*         endptr;
        unsigned long ul = std::strtoul(s, &endptr, 10);

        while (std::isspace(static_cast<unsigned char>(*endptr)))
            ++endptr;

        if (*endptr != '\0')
            throw std::runtime_error("[Invalid Argument]: invalid characters in an argument");

        if (errno == ERANGE || ul > UINT_MAX)
            throw std::runtime_error("[Invalid Argument]: value overflow");
    }
    return true;
}

void PmergeMe::processAndSort(int argc, char** argv)
{
    // Go through the entire arguments and validate them before the compare and push
    if (!isValidUnsignedInt(argc, argv))
        return;

    /* Go through the argument, Items in the list are first grouped into pairs and compared; the
     * larger item of each pair is collected into a “main chain” (sorted list).
     [12, 32, 43, 2, 21, 39]
     main chain -> [32, 43, 39]
     */

    for (int i = 1; i + 1 < argc; i += 2)
    {
    }


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

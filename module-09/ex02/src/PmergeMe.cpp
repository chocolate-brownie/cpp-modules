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
            return false;

        if (errno == ERANGE || ul > UINT_MAX)
            throw std::runtime_error("[Invalid Argument]: value overflow");
    }
    return true;
}

void PmergeMe::processAndSort(int argc, char** argv)
{
    // Go through the entire arguments and validate them
    if (!isValidUnsignedInt(argc, argv))
        return;

    for (int i = 1; i < argc; i += 1)
    {

        std::cout << argv[i] << std::endl;
        // a = static_cast<unsigned int>(std::strtoul(argv[i], NULL, 10));
        // b = static_cast<unsigned int>(std::strtoul(argv[i + 1], NULL, 10));
        // compareAndPush();
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

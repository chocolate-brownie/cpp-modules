#include "../include/PmergeMeUtils.hpp"

bool isValidUnsignedInt(int argc, char** argv)
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

unsigned int ft_strtoul(const char* s)
{
    unsigned long temp  = strtoul(s, NULL, 10);
    unsigned int  value = static_cast<unsigned int>(temp);
    return value;
}

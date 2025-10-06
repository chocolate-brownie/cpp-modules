#include "../include/ScalarConverter.hpp"
#include <iomanip>
#include <iostream>

/*------------------------ intToOthers Conversion --------------------------*/
bool ScalarConverter::isIntLiteral(const std::string& s, int& parsedInt) {
    bool neg = false;
    size_t i = 0;
    long long temp = 0;

    if (s[i] == '-') {
        neg = true;
        ++i;
    } else if (s[i] == '+') {
        ++i;
    }

    if (i >= s.length()) return false;

    for (; i < s.length(); ++i) {
        if (!isdigit(s[i])) return false;
        temp = temp * 10 + (s[i] - '0');

        if (neg && -temp < INT_MIN) { return false; }
        if (!neg && temp > INT_MAX) { return false; }
    }

    parsedInt = neg ? -temp : temp;
    return true;
}

void ScalarConverter::intToOthers(int nbr) {
    if (isprint(static_cast<unsigned char>(nbr))) {
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    std::cout << "int: " << nbr << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(nbr) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

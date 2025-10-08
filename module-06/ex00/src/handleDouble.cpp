#include "../include/ScalarConverter.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

bool ScalarConverter::isDoublePseudoLiterals(const std::string& s,
                                             double& parsedDouble) {
    std::string pseudoLiterals[3] = {"nan", "+inf", "-inf"};
    for (int i = 0; i < 3; ++i) {
        if (s.compare(pseudoLiterals[i]) == 0) {
            switch (i) {
            case 0:
                parsedDouble = std::numeric_limits<double>::quiet_NaN();
                return true;
            case 1:
                parsedDouble = std::numeric_limits<double>::infinity();
                return true;
            case 2:
                parsedDouble = -std::numeric_limits<double>::infinity();
                return true;
            }
        }
    }
    return false;
}

void ScalarConverter::pseudoDoubleToOthers(double nbr) {
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(nbr) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

bool ScalarConverter::isDoubleLiterals(const std::string& s,
                                       double& parsedDouble) {
    char* endptr = NULL;
    parsedDouble = strtod(s.c_str(), &endptr);

    if (endptr == s.c_str()) { return false; }
    if (*endptr != '\0') { return false; }

    return true;
}

void ScalarConverter::doubleToOthers(double nbr) {
    if (isprint(static_cast<unsigned char>(nbr))) {
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    if (nbr >= std::numeric_limits<int>::min() &&
        nbr <= std::numeric_limits<int>::max()) {
        std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(nbr) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

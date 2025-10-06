#include "../include/ScalarConverter.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

bool ScalarConverter::isFloatPseudoLiterals(const std::string& s,
                                            float& parsedFloat) {
    std::string pseudoLiterals[3] = {"nanf", "+inff", "-inff"};
    for (int i = 0; i < 3; ++i) {
        if (s.compare(pseudoLiterals[i]) == 0) {
            switch (i) {
            case 0:
                parsedFloat = std::numeric_limits<float>::quiet_NaN();
                return true;
            case 1:
                parsedFloat = std::numeric_limits<float>::infinity();
                return true;
            case 2:
                parsedFloat = -std::numeric_limits<float>::infinity();
                return true;
            }
        }
    }
    return false;
}

void ScalarConverter::pseudoFloatToOthers(float nbr) {
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(nbr) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

bool ScalarConverter::isFloatLiterals(const std::string& s,
                                      float& parsedFloat) {
    (void)s;
    (void)parsedFloat;
    return true;
}

void ScalarConverter::floatToOthers(float nbr) {
    (void)nbr;
    return;
}

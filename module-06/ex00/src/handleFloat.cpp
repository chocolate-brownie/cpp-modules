#include "../include/ScalarConverter.hpp"
#include <cstdlib>
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
    /* --- Bug Fix 1: Reject strings containing "nan" or "inf" ---
    This prevents "+nanf" from being partially parsed as a valid number. */
    if (s.find("nan") != std::string::npos ||
        s.find("inf") != std::string::npos) {
        return false;
    }

    char* endptr = NULL;
    parsedFloat = strtof(s.c_str(), &endptr);

    if (endptr == s.c_str()) { return false; }

    /* --- Bug Fix 2: Ensure a digit follows a decimal point ---
    This invalidates inputs like "42.f" */
    size_t pos = s.find('.');
    if (pos != std::string::npos) { // If a decimal point exists...
        // ...check if the character right after it is a digit.
        if (!isdigit(s[pos + 1])) { return false; }
    }

    if (*endptr != 'f' && *endptr != 'F') { return false; }
    if (*(endptr + 1) != '\0') { return false; }

    return true;
}

void ScalarConverter::floatToOthers(float nbr) {
    if (isprint(static_cast<unsigned char>(nbr))) {
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    // Perform the comparison in double-precision to avoid the warning
    if (static_cast<double>(nbr) >= std::numeric_limits<int>::min() &&
        static_cast<double>(nbr) <= std::numeric_limits<int>::max()) {
        std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(nbr) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

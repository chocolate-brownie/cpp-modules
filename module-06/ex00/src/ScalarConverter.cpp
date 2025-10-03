#include "../include/ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cstdlib>
#include <execution>
#include <iomanip>
#include <iostream>
#include <string>
/*
* Character literals are always within single quotes, e.g., '*'.

* Float literals end in 'f' or 'F' (e.g., "42.0f") and may also use "nanf" or
"inff" for pseudo values (nanf and inff are not available in c++98).

* Double literals include a decimal point but no 'f' suffix (e.g., "42.0",
"nan", "inf").

* Integer literals have only digits, with no dot, no suffix, and no wrapper
quotes (e.g., "0", "42").

* Pseudo-literals are special floating-point representations (e.g., "nan",
"inf", "nanf", "inff").

-> Type detection
-> Conversion
-> Error handling
*/

/*------------------------ charToOthers Conversion ---------------------------*/
bool ScalarConverter::isCharLiteral(const std::string& s) {
    return s.length() == 3 && s[0] == '\'' && s[s.length() - 1] == '\'' &&
           std::isprint(static_cast<unsigned char>(s[1]));
}

void ScalarConverter::charToOthers(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

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
    std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    std::cout << "int: " << nbr << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(nbr) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

/*------------------------ floatToOthers Conversion
 * --------------------------*/
// int ScalarConverter::isFloatPseudoLiterals(const std::string& s) {
//     std::string pseudoLiterals[3] = {"nanf", "+inff", "-inff"};
//     for (int i = 0; i < 3; ++i) {
//         if (s.compare(pseudoLiterals[i]) == 0) {
//             switch (i) {
//             case 0:
//                 return PSEUDOLIT_POS;
//             case 1:
//                 return PSEUDOLIT_POS;
//             case 2:
//                 return PSEUDOLIT_NEG;
//             }
//         }
//     }
//     return 0;
// }

// static int isDoublePseudoLiterals(const std::string& s) {
//     std::string pseudoLiterals[3] = {"nan", "+inf", "-inf"};
//     for (int i = 0; i < 3; ++i) {
//         if (s.compare(pseudoLiterals[i]) == 0) {
//             switch (i) {
//             case 0:
//                 return PSEUDOLITPOS;
//             case 1:
//                 return PSEUDOLITPOS;
//             case 2:
//                 return PSEUDOLITNEG;
//             }
//         }
//     }
//     return 0;
// }

/* ------------------- Type Conversion methods ---------------------------*/

/*------------------------ Main Converter Method
 * ---------------------------*/
void ScalarConverter::convert(const std::string& str) {
    if (str.empty()) throw ScalarConverter::ParamCannotBeEmpty();

    int parsedInt = 0;

    if (isCharLiteral(str)) {
        charToOthers(str[1]);
    } else if (isIntLiteral(str, parsedInt)) {
        intToOthers(parsedInt);
        // } else if (isFloatLiterals(str)) {
        //     floatToOthers(str);
        // } else if (isDoubleLiterals(str)) {
        //     doubleToOthers(str);
    } else {
        throw ScalarConverter::CharNonDisplayable();
    }
    return;
}

/*------------------------ Exception throws ---------------------------*/
const char* ScalarConverter::ParamCannotBeEmpty::what() const throw() {
    return "\"str\" parameter cannot be empty!";
}

const char* ScalarConverter::CharNonDisplayable::what() const throw() {
    return "char: Non displayable";
}

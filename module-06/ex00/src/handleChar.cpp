#include "../include/ScalarConverter.hpp"
#include <iomanip>
#include <iostream>

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

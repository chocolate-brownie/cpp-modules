#include "../include/ScalarConverter.hpp"
#include <execution>
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

/*------------------------ Main Converter Method ---------------------*/
void ScalarConverter::convert(const std::string& str) {
    if (str.empty()) throw ScalarConverter::ParamCannotBeEmpty();

    int parsedInt = 0;
    float parsedFloat = 0;

    if (isCharLiteral(str)) {
        charToOthers(str[1]);
    } else if (isIntLiteral(str, parsedInt)) {
        intToOthers(parsedInt);
    } else if (isFloatPseudoLiterals(str, parsedFloat)) {
        pseudoFloatToOthers(parsedFloat);
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

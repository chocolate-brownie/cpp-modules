#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <string>

void runTest(const std::string& literal) {
    std::cout << "--- Testing input: [" << literal << "] ---" << std::endl;
    try {
        ScalarConverter::convert(literal);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // --- Subject Examples ---
    runTest("0");
    runTest("nan");
    runTest("42.0f");

    // --- Char Tests ---
    runTest("'c'");
    runTest("'*'");
    runTest("'a'");

    // --- Int Tests ---
    runTest("42");
    runTest("-42");
    runTest("2147483647");  // INT_MAX
    runTest("-2147483648"); // INT_MIN

    // --- Float Tests ---
    runTest("3.14f");
    runTest("-3.14f");
    runTest("1234.56f");
    runTest(".5f");
    runTest("0.0f");

    // --- Double Tests ---
    runTest("3.14");
    runTest("-3.14");
    runTest("1234.56");
    runTest(".5");
    runTest("0.0");

    // --- Pseudo-literal Tests ---
    runTest("nanf");
    runTest("+inff");
    runTest("-inff");
    runTest("+inf");
    runTest("-inf");

    // --- Overflow and Impossible Conversion Tests ---
    runTest("2147483648.0");   // Should be impossible for int
    runTest("-2147483649.0f"); // Should be impossible for int
    runTest("1e40");           // A large double, impossible for int/float

    // --- Non-displayable Tests ---
    runTest("9");   // ASCII for tab (non-displayable)
    runTest("127"); // ASCII for DEL (non-displayable)

    // --- Invalid Input Tests ---
    runTest("hello");
    runTest("42.0ff");
    runTest("42.f");
    runTest("1.2.3");
    runTest("+-42");
    runTest("nananan");
    runTest("+nanf"); // Not required by subject, should be invalid

    return 0;
}

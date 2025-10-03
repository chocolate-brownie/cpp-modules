#include "../include/ScalarConverter.hpp"
#include <exception>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./scalarConverter <char/int/float/double>"
                  << std::endl;
        return 1;
    }

    try {
        ScalarConverter::convert(argv[1]);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

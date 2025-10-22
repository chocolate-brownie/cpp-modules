#include <exception>

#include "../include/ReversePolishNotation.hpp"

int main(int argc, char* argv[]) {
    try {
        ReversePolishNotation obj;
        std::string arg(argv[1]);
        obj.rnp(arg);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

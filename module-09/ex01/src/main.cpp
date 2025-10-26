#include <exception>

#include "../include/ReversePolishNotation.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Invalid argument count" << std::endl;
        return 1;
    }
    try
    {
        ReversePolishNotation obj;
        std::string           arg(argv[1]);
        obj.rnp(arg);
    } catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}

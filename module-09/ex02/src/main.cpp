#include <exception>

#include "../include/PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: Invalid argument count" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;
        sorter.processAndSort(argc, argv);
    } catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

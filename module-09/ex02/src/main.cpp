#include <bits/types/struct_timeval.h>
#include <exception>
#include <sys/time.h>  // For gettimeofday()

#include "../include/PmergeMe.hpp"
#include "../include/PmergeMeDeque.hpp"

/*
grep -rni --include='*.log' '(std::deq)'
grep -rni --include='*.cpp' '(std::deq)'

https://numbergenerator.org/randomnumbergenerator/combinations-generator
*/

double getTimeInMicroSeconds(struct timeval* start, struct timeval* end)
{
    long seconds      = end->tv_sec - start->tv_sec;
    long microseconds = end->tv_usec - start->tv_usec;

    return (seconds * 1000000) + microseconds;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: Invalid argument count" << std::endl;
        return 1;
    }

    double timeTakenVec, timeTakenDeque;

    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i)
        std::cout << argv[i] << " ";
    std::cout << "\n\n\n" << std::endl;

    try
    {
        std::cout << "Sorting using std::vec" << std::endl;
        struct timeval start, end;
        gettimeofday(&start, NULL);

        PmergeMe sorter;
        sorter.processAndSort(argc, argv);

        gettimeofday(&end, NULL);

        timeTakenVec = getTimeInMicroSeconds(&start, &end);
        sorter.printFinalResult();

    } catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    try
    {
        std::cout << "\n\n\n\n\n\nSorting using std::deque" << std::endl;
        struct timeval start, end;
        gettimeofday(&start, NULL);

        PmergeMeDeque dequeSorter;
        dequeSorter.processAndSort(argc, argv);

        gettimeofday(&end, NULL);

        timeTakenDeque = getTimeInMicroSeconds(&start, &end);
        dequeSorter.printFinalResult();

    } catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nTime to process a range of " << (argc - 1)
              << " elements with std::vector : " << timeTakenVec << "us" << std::endl;
    std::cout << "Time to process a range of " << (argc - 1)
              << " elements with std::deque : " << timeTakenDeque << "us" << std::endl;

    return 0;
}

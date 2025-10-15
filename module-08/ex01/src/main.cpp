#include "../include/Span.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

#define TITLE(msg) std::cout << "\n--- " << msg << " ---" << std::endl

int main() {
    /*-------------------------------------------------------------------------------- */
    TITLE("Test 1: Subject's examples");
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;
    /*-------------------------------------------------------------------------------- */
    TITLE("Test 2: Exception on full container");
    try {
        std::cout << "Attempting to add one more number..." << std::endl;
        sp.addNumber(100);
    } catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }
    /*-------------------------------------------------------------------------------- */
    TITLE("Test 3: Exception on too few numbers for shortestSpan() & longestSpan()");
    Span single(10);
    single.addNumber(42);

    try {
        std::cout << "shortestSpan() on a container with 1 number..." << std::endl;
        single.shortestSpan();
    } catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }

    try {
        std::cout << "longestSpan() on a container with 1 number..." << std::endl;
        single.longestSpan();
    } catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }
    /*-------------------------------------------------------------------------------- */
    TITLE("Test 4: Large-Scale test(15,000 numbers)");
    try {
        Span largeSpan(15000);
        std::vector<unsigned int> randomNumbers;

        srand(time(0));

        for (int i = 0; i < 15000; ++i) randomNumbers.push_back(rand());

        largeSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
        std::cout << "Successfully added 15,000 random numbers." << std::endl;
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }
    /*-------------------------------------------------------------------------------- */
    TITLE("Test 5: Copy constructor and assignment op");
    Span original(4);
    original.addNumber(10);
    original.addNumber(20);

    Span copy(original);
    Span assigned = original;

    original.addNumber(30); // modify the original

    std::cout << "Original's shortest span: " << original.shortestSpan() << std::endl;
    std::cout << "Copy's shortest span (should be unchanged): " << copy.shortestSpan()
              << std::endl;
    std::cout << "Assigned's shortest span (should be unchanged): "
              << assigned.shortestSpan() << std::endl;

    return 0;
}

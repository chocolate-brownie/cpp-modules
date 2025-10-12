#include "../include/iter.hpp"
#include <iostream>
#include <string>

template <typename T> void addOne(T& element) { element++; }
template <typename T> void printElement(const T& element) {
    std::cout << element << " ";
}

int main(void) {
    // --- Test 1: Modifiable integer array ---
    std::cout << "--- Test with modifiable int array ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Original: ";
    iter(intArray, 5, printElement<int>); // Explicitly using <int> for clarity
    std::cout << std::endl;

    iter(intArray, 5, addOne<int>); // Modify the array
    std::cout << "After addOne: ";
    iter(intArray, 5, printElement<int>);
    std::cout << "\n" << std::endl;

    // --- Test 2: Constant string array ---
    std::cout << "--- Test with constant string array ---" << std::endl;
    const std::string nameArray[] = {"cat", "dog", "bird", "fish"};
    std::cout << "Printing const array: ";
    iter(nameArray, 4, printElement<std::string>);

    /* The following line would cause a compile error when it sees the third
    argument addOne is a function that requires a non-const reference
    (std::string&), which is correct! */
    // iter(nameArray, 4, addOne<std::string>);

    std::cout << "\n" << std::endl;

    // --- Test 3: Modifiable char array ---
    std::cout << "--- Test with modifiable char array ---" << std::endl;
    char charArray[] = {'a', 'b', 'c', 'd'};
    std::cout << "Original: ";
    iter(charArray, 4, printElement<char>);
    std::cout << std::endl;

    iter(charArray, 4, addOne<char>); // Increment characters ('a' -> 'b', etc.)
    std::cout << "After addOne: ";
    iter(charArray, 4, printElement<char>);
    std::cout << "\n" << std::endl;

    return 0;
}

#include "../include/Array.hpp"
#include <iostream>

#define TITLE(msg) std::cout << "\n--- " << msg << " ---" << std::endl

int main() {
    TITLE("Test 1: Sized constructor and writing/reading elements");
    Array<int> numbers(5);
    std::cout << "Created an array of size: " << numbers.size() << std::endl;
    for (unsigned int i = 0; i < numbers.size(); ++i) { numbers[i] = i * 10; }
    std::cout << "Array elements: ";
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    TITLE("Test 2: Copy constructor");
    Array<int> copy = numbers; // Calls copy constructor
    std::cout << "Original's size: " << numbers.size() << std::endl;
    std::cout << "Copy's size: " << copy.size() << std::endl;
    // Modify the original to prove the copy is a deep copy
    numbers[0] = 999;
    std::cout << "Original's first element after modification: " << numbers[0]
              << std::endl;
    std::cout << "Copy's first element (should be unchanged): " << copy[0]
              << std::endl;

    TITLE("Test 3: Assignment operator");
    Array<int> assigned(2);
    assigned[0] = 1;
    assigned[1] = 2;
    std::cout << "Before assignment, 'assigned' size: " << assigned.size()
              << std::endl;
    assigned = copy;
    std::cout << "After assignment, 'assigned' size: " << assigned.size()
              << std::endl;
    std::cout << "Assigned's first element: " << assigned[0] << std::endl;

    TITLE("Test 4: Default constructor and const correctness");
    const Array<int> empty_const_array;
    std::cout << "Size of default-constructed const array: "
              << empty_const_array.size() << std::endl;
    const Array<int> const_numbers = numbers;
    std::cout << "Reading from const array's first element: "
              << const_numbers[0] << std::endl;
    // The following line would cause a compile error, as expected:
    // const_numbers[0] = 123;

    TITLE("Test 5: Out-of-bounds exception handling");
    try {
        std::cout << "Attempting to access a valid index (numbers[2])... ";
        std::cout << "Value: " << numbers[2] << std::endl;
        std::cout << "SUCCESS: No exception thrown." << std::endl;

        std::cout << "Attempting to access an invalid index (numbers[10])... ";
        numbers[10] = 123; // This should throw
        std::cout << "FAILURE: No exception was thrown."
                  << std::endl; // This line should not be reached
    } catch (const std::exception& e) {
        std::cout << "SUCCESS: Caught an exception! (" << e.what() << ")"
                  << std::endl;
    }

    // Test with another type
    TITLE("Test 6: Array of strings");
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "C++";
    words[2] = "Templates!";
    for (unsigned int i = 0; i < words.size(); ++i) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\nAll tests completed." << std::endl;
    return 0;
}

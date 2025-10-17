#include <iostream>
#include <list>
#include <vector>

#include "../include/MutantStack.hpp"
#define TITLE(msg) std::cout << "\n--- " << msg << " ---" << std::endl

void subjectMainTest() {
    TITLE("Subject's main tests");
    MutantStack<int> mstack;
    mstack.push(5);  // Add an element to the top.
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();  // Remove the top element.
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;  // [5, *3, 737, 0]
    --it;  // [*5, 3, 737, 0]

    std::cout << "Iterating through MutantStack: " << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Copying to a standard std::stack..." << std::endl;
    /* this line is a test to demonstrate that your MutantStack is fully compatible with
     * the original std::stack and can be used to initialize a standard stack, proving
     * your inheritance was set up correctly. if not it show errors */
    std::stack<int> s(mstack);
    std::cout << "Standard stack size: " << s.size() << std::endl;
}

/* The point of the test is to prove that the MutantStack behaves exactly like a standard,
iterable STL container.

It performs the same sequence of operations (push_back, pop_back, iterating through the
elements) on a std::list that the subject_main_test performs on the MutantStack. */
void listComparisonTest() {
    TITLE("Comparison with std::list");
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << "Back: " << list.back() << std::endl;
    list.pop_back();
    std::cout << "Size: " << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    std::cout << "Iterating through std::list:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}

void extendedIteratorTests() {
    TITLE("Extended Iterator Tests");
    MutantStack<char> char_stack;
    char_stack.push('a');
    char_stack.push('b');
    char_stack.push('c');
    char_stack.push('d');

    std::cout << "Forward iteration (iterator): ";
    for (MutantStack<char>::iterator it = char_stack.begin(); it != char_stack.end();
         ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse iteration (reverse_iterator): ";
    for (MutantStack<char>::reverse_iterator rit = char_stack.rbegin();
         rit != char_stack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Test const_iterator
    const MutantStack<char> const_stack(char_stack);
    std::cout << "Forward iteration on const stack (const_iterator): ";
    for (MutantStack<char>::const_iterator cit = const_stack.begin();
         cit != const_stack.end(); ++cit) {
        std::cout << *cit << " ";
        // *cit = 'z'; // This line would cause a compile error, which is correct!
    }
    std::cout << std::endl;
}

void vectorBackEnd() {
    TITLE("Test with std::vector as Underlying Container");
    // Explicitly create a MutantStack that uses a vector
    MutantStack<int, std::vector<int> > vector_stack;
    vector_stack.push(1);
    vector_stack.push(2);
    vector_stack.push(3);

    std::cout << "Iterating through a vector-based MutantStack:" << std::endl;
    for (MutantStack<int, std::vector<int> >::iterator it = vector_stack.begin();
         it != vector_stack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    subjectMainTest();
    listComparisonTest();
    extendedIteratorTests();
    vectorBackEnd();
}

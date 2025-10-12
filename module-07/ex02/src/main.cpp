#include "../include/Array.hpp"
#include <iostream>

int main() {
    Array<int> a;
    Array<int> b(a);

    Array<int> c;
    c = b;

    Array<int> d;
    std::cout << "Array test completed." << std::endl;
    return 0;
}

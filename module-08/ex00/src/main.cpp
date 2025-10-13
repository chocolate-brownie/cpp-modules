#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found: " << *it << std::endl;
    } catch (ValueNotFound& e) { std::cout << e.what() << std::endl; }

    try {
        std::vector<int>::iterator it = easyfind(vec, 300);
        std::cout << "Found: " << *it << std::endl;
    } catch (ValueNotFound& e) { std::cout << e.what() << std::endl; }
    return 0;
}

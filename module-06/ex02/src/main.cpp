#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/Base.hpp"
#include "../include/C.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

/* dynamic_cast is a C++ operator used for safely converting pointers and
 * references within an inheritance hierarchy, relying on Runtime Type
 * Identification (RTTI)

 When to use:
 * When you have a base class pointer/reference and need to check if it actually
 points to a derived type before using derived-specific functionality.

 Limitations:
 * Requires RTTI to be enabled (default in most compilers).
 * Only works with polymorphic types.

 Use Case        |  Result if Valid  |  Result if Invalid
 ----------------+-------------------+-------------------
 Pointer cast    |  Derived pointer  |  nullptr
 Reference cast  |  Derived ref      |  Throwsbad_cast

 */
Base* generate(void) {
    std::vector<Base*> vec = {new A(), new B(), new C()};
    int idx = std::rand() % vec.size();
    return vec[idx];
}

void identify(Base* p) {
    if (A* a = dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (B* b = dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (C* c = dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {}

int main(void) {
    Base* randomObj = generate();
    std::cout << "Identifying with pointer" << std::endl;
    identify(randomObj);
}

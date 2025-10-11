#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/Base.hpp"
#include "../include/C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

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
    int choice = std::rand() % 3;
    switch (choice) {
    case 0:
        return new A();
    case 1:
        return new B();
    default:
        return new C();
    }
}

/* if you can cast p to an A*, B* or *C print the message otherwise give me
 a nullptr */
void identify(Base* p) {
    if (A* a = dynamic_cast<A*>(p)) {
        (void)a;
        std::cout << "A" << std::endl;
    } else if (B* b = dynamic_cast<B*>(p)) {
        (void)b;
        std::cout << "B" << std::endl;
    } else if (C* c = dynamic_cast<C*>(p)) {
        (void)c;
        std::cout << "C" << std::endl;
    }
}

/* "Is this Base object actually an A object?" The way it answers "no" has to be
 different for pointers and references. Because a null reference is
 impossible, dynamic_cast needs a different way to signal a failure. The
 language designers chose to use the C++ exception system. If the cast fails, it
 throws a std::bad_cast exception. */
void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (const std::exception& e) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch (const std::exception& e) { std::cout << "C" << std::endl; }
    }
}

int main(void) {
    std::srand(std::time(0));

    Base* randomObj = generate();
    std::cout << "Identifying with pointer: ";
    identify(randomObj);

    std::cout << "Identifying with reference: ";
    identify(*randomObj);

    delete randomObj;
    return 0;
}

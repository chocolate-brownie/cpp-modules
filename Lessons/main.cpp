#include <iostream>

using namespace::std;

class Animal {
    public:
    virtual void sound() {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
    public:
    void sound() override {
        cout << "Dog barks\n";
    }
};

int main() {

    Animal* ptrA;
    Dog d;

    ptrA = &d;

    ptrA->sound(); // should print dogs barks



}

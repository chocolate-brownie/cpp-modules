#include <cstring>
#include <iostream>

using namespace std;

class Base {
  public:
    char* name;

    Base(const char* n) : name(new char[strlen(n) + 1]) { strcpy(name, n); }
    Base(const Base& other, bool deepCopy) {
        if (deepCopy == true) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = other.name;
        }
    }
    virtual ~Base() { delete[] name; }

    virtual Base* cloneShallow() const { return new Base(*this, false); }
    virtual Base* cloneDeep() const { return new Base(*this, true); }
    virtual void print() { cout << "Base: " << name << endl; }
};

class Derived : public Base {
  public:
    int* values;
    int size;

    Derived(const char* n, int sz) : Base(n), size(sz) {
        values = new int[size];
        for (int i = 0; i < size; i++)
            values[i] = i;
    }
    Derived(const Derived& other, bool deepCopy) : Base(other, deepCopy) {
        size = other.size;
        if (deepCopy) {
            values = new int[size];
            for (int i = 0; i < size; i++)
                values[i] = other.values[i];
        } else {
            values = other.values;
        }
    }
    ~Derived() { delete[] values; }

    Base* cloneShallow() const { return new Derived(*this, false); }
    Base* cloneDeep() const { return new Derived(*this, true); }
    void print() {
        cout << "Derived: " << name << " valuess: ";
        for (int i = 0; i < size; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Derived d1("DerivedObj", 3);
    cout << "Original object:" << endl;
    d1.print();

    Base* shallowCopy = d1.cloneShallow();
    Base* deepCopy = d1.cloneDeep();

    cout << "\nAfter shallow copy and modifying original's valuess:" << endl;
    d1.values[0] = 100; // Changes affect shallow copy too
    shallowCopy->print();

    cout << "\nAfter deep copy and modifying original's valuess:" << endl;
    d1.values[1] = 200; // Changes do NOT affect deep copy
    deepCopy->print();

    delete shallowCopy;
    delete deepCopy;
    return 0;
}

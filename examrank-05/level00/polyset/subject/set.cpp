#include "set.hpp"

set::set(searchable_bag& bag): _bag(bag) {}

bool set::has(int value) const {
    return _bag.has(value);
}

void set::insert(int value) {
    if (!this->has(value))
        _bag.insert(value);
}

void set::insert(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        this->insert(array[i]);
    }
}

void set::print() const {
    _bag.print();
}

void set::clear() {
    _bag.clear();
}

const searchable_bag& set::get_bag() const {
    return (this->_bag);
}

set::~set() {}
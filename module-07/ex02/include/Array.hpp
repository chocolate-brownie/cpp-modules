#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T> class Array {
  private:
    T* _array;
    unsigned int _size;

  public:
    Array() : _array(NULL), _size(0) {}
    Array(unsigned int size) : _array(NULL), _size(size) {}

    Array(const Array& other) : _array(NULL), _size(other._size) {
        if (_size > 0) {
            T* tmp = new T[other._size];
            try {
                for (unsigned int i = 0; i < _size; ++i)
                    tmp[i] = other._array[i];
            } catch (...) {
                delete[] tmp;
                throw;
            }
            _array = tmp;
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            T* tmp = NULL;
            if (other._size > 0) {
                tmp = new T[other._size];
                try {
                    for (unsigned int i = 0; i < other._size; ++i)
                        tmp[i] = other._array[i];
                } catch (...) {
                    delete[] tmp;
                    throw;
                }
            }
            delete[] _array;
            _array = tmp;
            _size = other._size;
        }
        return *this;
    }

    ~Array() { delete[] _array; }
};

#endif

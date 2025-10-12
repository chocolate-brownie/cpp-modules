#ifndef ITER_HPP
#define ITER_HPP

// Version 1: For modifiable arrays
template <typename T> void iter(T* array, int length, void (*func)(T&)) {
    for (int i = 0; i < length; ++i) func(array[i]);
}

// Version 1: For unmodifiable arrays
template <typename T>
void iter(const T* array, int length, void (*func)(const T&)) {
    for (int i = 0; i < length; ++i) func(array[i]);
}

#endif

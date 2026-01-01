#ifndef vect2_hpp
#define vect2_hpp

#include <iostream>

class vect2 {
private:
    int x;
    int y;

public:
    vect2(int x = 0, int y = 0);
    vect2(const vect2& other);
    vect2& operator=(const vect2& other);
    ~vect2();

    vect2 operator+(const vect2& other) const;
    vect2 operator-(const vect2& other) const;
    vect2 operator*(int scaler) const;

    vect2 operator-() const;

    vect2& operator+=(const vect2& other);
    vect2& operator-=(const vect2& other);
    vect2& operator*=(int scaler);

    int& operator[](int index);
    const int& operator[](int index) const;

    vect2& operator++();
    vect2 operator++(int);

    vect2& operator--();
    vect2 operator--(int);

    bool operator==(const vect2& other) const;
    bool operator!=(const vect2& other) const;

    friend vect2 operator*(int scaler, const vect2& v);
    friend std::ostream& operator<<(std::ostream& os, const vect2& v);
};

#endif
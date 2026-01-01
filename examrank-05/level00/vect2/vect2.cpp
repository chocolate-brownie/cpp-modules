#include "vect2.hpp"

vect2::vect2(int x, int y): x(x), y(y) {}

vect2::vect2(const vect2& other): x(other.x), y(other.y) {}

vect2& vect2::operator=(const vect2& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

vect2::~vect2() {}

vect2 vect2::operator+(const vect2& other) const {
    vect2 temp = *this;
    temp += other;
    return temp;
}

vect2 vect2::operator-(const vect2& other) const {
    vect2 temp = *this;
    temp -= other;
    return temp;
}

vect2 vect2::operator*(int scaler) const {
    vect2 temp = *this;
    temp *= scaler;
    return temp;
}

vect2 vect2::operator-() const {
    return vect2(-x, -y);
}

vect2& vect2::operator+=(const vect2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

vect2& vect2::operator-=(const vect2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}
    
vect2& vect2::operator*=(int scaler) {
    x *= scaler;
    y *= scaler;
    return *this;
}

int& vect2::operator[](int index) {
    if (index == 0)
        return x;
    return y;
}
const int& vect2::operator[](int index) const {
    if (index == 0)
        return x;
    return y;
}

vect2& vect2::operator++() {
    x++;
    y++;
    return *this;
}

vect2 vect2::operator++(int) {
    vect2 temp = *this;
    ++(*this);
    return temp;
}

vect2& vect2::operator--() {
    x--;
    y--;
    return *this;
}

vect2 vect2::operator--(int) {
    vect2 temp = *this;
    --(*this);
    return temp;
}

bool vect2::operator==(const vect2& other) const {
    return (x == other.x && y == other.y);
}

bool vect2::operator!=(const vect2& other) const {
    return !(x == other.x && y == other.y);
}

vect2 operator*(int scaler, const vect2& v) {
    return vect2(v.x * scaler, v.y * scaler);
}

std::ostream& operator<<(std::ostream& os, const vect2& v) {
    os << "{"<< v.x << ", " << v.y << "}";
    return os;
}
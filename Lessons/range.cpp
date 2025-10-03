#include <cctype>
#include <iostream>
#include <limits>

void checkAndCast(float value) {
    if (value < std::numeric_limits<char>::min() ||
        value > std::numeric_limits<char>::max()) {
        std::cout << "Value " << value << " is outside the char range"
                  << std::endl;
        return;
    }

    char c = static_cast<char>(value);
    std::cout << "value is within range and cast to char: " << c << std::endl;
}

int main() {
    float val1 = 100.5f;
    float val2 = 200.5f;

    checkAndCast(val1);
    checkAndCast(val2);
}

#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <cstdlib>
#include <iostream>  // IWYU pragma: keep
#include <limits>    // IWYU pragma: keep
#include <sstream>   // IWYU pragma: keep
#include <stack>
#include <stdexcept>  // IWYU pragma: keep
#include <string>     // IWYU pragma: keep

class ReversePolishNotation {
private:
    std::stack<int> st;

    void performRnp(const std::string& op);
    bool isOperator(const std::string& token) const;
    bool isValidNumString(const std::string& token, int& num) const;

public:
    ReversePolishNotation();
    ~ReversePolishNotation();
    ReversePolishNotation(const ReversePolishNotation& other);
    ReversePolishNotation& operator=(const ReversePolishNotation& other);

    void rnp(std::string& s);
};

#endif

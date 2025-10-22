#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>  // IWYU pragma: keep
#include <string>    // IWYU pragma: keep

class ReversePolishNotation {
   private:

   public:
    ReversePolishNotation();
    ~ReversePolishNotation();
    ReversePolishNotation(const ReversePolishNotation& other);
    ReversePolishNotation& operator=(const ReversePolishNotation& other);

    void rnp(std::string& s);

};

#endif

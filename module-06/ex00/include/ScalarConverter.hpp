#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <string>

#define PSEUDOLIT_POS 1
#define PSEUDOLIT_NEG 2
/*
* static_cast: You are performing a sensible, compile-time-checked conversion.

* dynamic_cast: You are navigating a class hierarchy and need a runtime safety
 check.

* reinterpret_cast: You are doing something low-level and potentially dangerous
 with the raw bits of your data.

* const_cast: You are specifically changing the const-ness of a variable.  */

class ScalarConverter {
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    static bool isCharLiteral(const std::string& s);
    static void charToOthers(char c);

    static bool isIntLiteral(const std::string& s, int& parsedInt);
    static void intToOthers(int nbr);

    // static int isFloatPseudoLiterals(const std::string& s);
    // static int isFloatLiterals(const std::string& s);
    // static void floatToOthers(const std::string& fNbr);

    // static int isDoublePseudoLiterals(const std::string& s);
    // static int isDoubleLiterals(const std::string& s);
    // static void doubleToOthers(const std::string& dNbr);

  public:
    static void convert(const std::string& str);

    class ParamCannotBeEmpty : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class CharNonDisplayable : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

#endif

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <climits>
#include <cstdlib>
#include <exception>
#include <string>
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

    static bool isFloatPseudoLiterals(const std::string& s, float& parsedFloat);
    static void pseudoFloatToOthers(float nbr);
    static bool isFloatLiterals(const std::string& s, float& parsedFloat);
    static void floatToOthers(float nbr);

    static bool isDoublePseudoLiterals(const std::string& s,
                                       double& parsedDouble);
    static void pseudoDoubleToOthers(double nbr);
    static bool isDoubleLiterals(const std::string& s, double& parsedDouble);
    static void doubleToOthers(double nbr);

  public:
    static void convert(const std::string& str);

    class ParamCannotBeEmpty : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class InvalidLiteralException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

#endif

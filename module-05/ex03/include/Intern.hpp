#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
  public:
    AForm* makeForm(std::string const& formName, std::string const& target);
    class FormNameNotRecognized : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
};

#endif

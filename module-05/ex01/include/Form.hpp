#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form {
  private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExec;

  public:
    Form();
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    Form(std::string name, int gradeToSign, int gradeToExec);

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
    void signForm(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif

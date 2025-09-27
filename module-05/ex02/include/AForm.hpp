#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class AForm {
  private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExec;
    const std::string _target;

  public:
    /*----- Member methods -----*/
    virtual void execute(Bureaucrat const& executor) const = 0;
    void beSigned(const Bureaucrat& bureaucrat);
    AForm(std::string name, int gradeToSign, int gradeToExec,
          std::string target);

    /*----- Getters -----*/
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    std::string getTarget() const;

    /*----- OCF -----*/
    AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    /*----- Exceptions -----*/
    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif

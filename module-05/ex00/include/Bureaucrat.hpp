#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class Bureaucrat {
  private:
    const std::string _name;
    unsigned int _grade;

  public:
    Bureaucrat(const std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName();
    unsigned int getGrade();

    class GradeTooHighException : public std::exception {};
    class GradeTooLowException : public std::exception {};

    void incrementGrade();
    void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/Colors.hpp"
#include <exception>

/* -------------------- Orthodox Canonical Class Form ------------------ */
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    DEBUG_LOG("Bureaucrat Default constructor called");
    return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
    DEBUG_LOG("Bureaucrat Copy constructor called for " + _name);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        DEBUG_LOG("Bureaucrat Assignment operator called for " + _name);
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    DEBUG_LOG("Bureaucrat destructor called for " + _name);
}

/* -------------------- Constructor with Parameter ------------------ */
Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name), _grade(grade) {
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
    DEBUG_LOG("Parameter constructor called");
    return;
}

/* -------------------- Exception throws ------------------ */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high (must be >= 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low (must be <= 150)";
}

/* -------------------- Other member functions ------------------ */
void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << BOLD_WHITE << this->getName() << " signed "
                  << form.getName() << RESET << std::endl;
    } catch (const AForm::FormAlreadySignedException& e) {
        std::cout << BOLD_BLUE << this->getName() << " no need to sign again "
                  << form.getName() << " because " << e.what() << RESET
                  << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << this->getName() << " couldn't sign "
                  << form.getName() << " because " << e.what() << RESET
                  << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) const {
    try {
        form.execute(*this);
        std::cout << BOLD_GREEN << this->getName() << " executed "
                  << form.getName() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << this->getName() << " couldn't execute "
                  << form.getName() << " because " << e.what() << RESET
                  << std::endl;
    }
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1) throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150) throw GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}

/* -------------------- Getters & Setters ------------------ */
std::string Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

#include "../include/Bureaucrat.hpp"

/* -------------------- Orthodox Canonical Class Form ------------------ */
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    DEBUG_LOG("Default constructor called");
    return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
    DEBUG_LOG("Copy constructor called for " + _name);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        DEBUG_LOG("Assignment operator called for " + _name);
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() { DEBUG_LOG("Destructor called for " + _name); }

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

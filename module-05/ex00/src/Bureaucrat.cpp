#include "../include/Bureaucrat.hpp"
#include <iostream>

/* -------------------- Orthodox Canonical Class Form ------------------ */
Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
    std::cout << "Copy constructor called for " << _name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        std::cout << "Assignment operator called for " << _name << std::endl;
    }
    _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called for " << _name << std::endl;
}

/* -------------------- Constructor with Parameter ------------------ */
Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
    : _name(name), _grade(grade) {
    std::cout << "Parameter constructor called" << std::endl;
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
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

/* -------------------- Getters & Setters ------------------ */
std::string Bureaucrat::getName() const { return _name; }
unsigned int Bureaucrat::getGrade() const { return _grade; }

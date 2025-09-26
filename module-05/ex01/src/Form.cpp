#include "../include/Form.hpp"
/* -------------------- Member functions ------------------ */
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) throw GradeTooLowException();
    _isSigned = true;
}

/* --------- Operator Overload & Getters ------------------ */
std::ostream& operator<<(std::ostream& os, const Form& obj) {
    os << "Form " << obj.getName() << ", Signed: " << obj.getIsSigned()
       << ", Grade to Sign: " << obj.getGradeToSign()
       << ", Grade to Execute: " << obj.getGradeToExecute();
    return os;
}

std::string Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExec; }

/* -------------------- Exception throws ------------------ */
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high (must be >= 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low (must be <= 150)";
}

/* -------------------- Param constructor ------------------ */
Form::Form(std::string name, int gradeToSign, int gradeToExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1) {
        throw Form::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExec > 150) {
        throw Form::GradeTooLowException();
    }
}

/* -------------------- OCF functions ------------------ */
Form::Form()
    : _name("default"), _isSigned(false), _gradeToSign(0), _gradeToExec(0) {
    DEBUG_LOG("Form default constructor called");
    return;
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
    DEBUG_LOG("Form copy constructor called");
    return;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) { _isSigned = other._isSigned; }
    DEBUG_LOG("Form operator assignment called");
    return *this;
}

Form::~Form() {
    DEBUG_LOG("Form destructor called");
    return;
}

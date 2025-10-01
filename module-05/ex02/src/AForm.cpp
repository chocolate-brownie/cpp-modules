#include "../include/AForm.hpp"
/* -------------------- Member functions ------------------ */
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (_isSigned) { throw FormAlreadySignedException(); }
    if (bureaucrat.getGrade() > _gradeToSign) throw GradeTooLowException();
    _isSigned = true;
}

/* --------- Operator Overload & Getters ------------------ */
std::ostream& operator<<(std::ostream& os, const AForm& obj) {
    os << "AForm " << obj.getName() << ", Signed: " << obj.getIsSigned()
       << ", Grade to Sign: " << obj.getGradeToSign()
       << ", Grade to Execute: " << obj.getGradeToExecute();
    return os;
}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExec; }
std::string AForm::getTarget() const { return _target; }

/* -------------------- Exception throws ------------------ */
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high (must be >= 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low (must be <= 150)";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

const char* AForm::FormAlreadySignedException::what() const throw() {
    return "the form is already signed";
}

/* -------------------- Param constructor ------------------ */
AForm::AForm(std::string name, int gradeToSign, int gradeToExec,
             std::string target)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec), _target(target) {
    DEBUG_LOG("AForm param constructor called");
    if (gradeToSign < 1 || gradeToExec < 1) {
        throw AForm::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExec > 150) {
        throw AForm::GradeTooLowException();
    }
}

/* -------------------- OCF functions ------------------ */
AForm::AForm()
    : _name(""), _isSigned(false), _gradeToSign(0), _gradeToExec(0),
      _target("") {
    DEBUG_LOG("AForm default constructor called");
    return;
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec),
      _target(other._target) {
    DEBUG_LOG("AForm copy constructor called");
    return;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) { _isSigned = other._isSigned; }
    DEBUG_LOG("AForm operator assignment called");
    return *this;
}

AForm::~AForm() {
    DEBUG_LOG("AForm destructor called");
    return;
}

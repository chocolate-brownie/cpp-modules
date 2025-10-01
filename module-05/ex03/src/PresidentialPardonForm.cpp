#include "../include/PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (!this->getIsSigned()) { throw AForm::FormNotSignedException(); }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm::AForm("Presidential Pardon Form", 25, 5, target) {
    DEBUG_LOG("PresidentialPardonForm param constructor called");
}

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm() {
    DEBUG_LOG("PresidentialPardonForm default constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm::AForm(other) {
    DEBUG_LOG("PresidentialPardonForm copy constructor called");
}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) { AForm::operator=(other); }
    DEBUG_LOG("PresidentialPardonForm copy assignment operator called");
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    DEBUG_LOG("PresidentialPardonForm destructor called");
}

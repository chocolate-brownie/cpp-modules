#include "../include/RobotomyRequestForm.hpp"

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (!this->getIsSigned()) { throw AForm::FormNotSignedException(); }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << "🔩 drrrrrrrrrrrr!!" << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << getTarget() << " has been robotomized successfully."
                  << std::endl;
    } else {
        std::cout << getTarget() << " 's robotomization failed" << std::endl;
    }
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request Form:", 72, 45, target) {
    DEBUG_LOG("RobotomyRequestForm param constructor called");
}

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm() {
    DEBUG_LOG("RobotomyRequestForm default constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm::AForm(other) {
    DEBUG_LOG("RobotomyRequestForm copy constructor called");
}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) { AForm::operator=(other); }
    DEBUG_LOG("RobotomyRequestForm copy assignment operator called");
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    DEBUG_LOG("RobotomyRequestForm destructor called");
    return;
}

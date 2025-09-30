#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!this->getIsSigned()) { throw AForm::FormNotSignedException(); }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::string filename = this->getTarget() + "_shrubbery";

    std::ofstream outFile(filename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename
                  << " for writing." << std::endl;
        return;
    }

    outFile << "      /\\      " << std::endl;
    outFile << "     /\\*\\     " << std::endl;
    outFile << "    /\\O\\*\\    " << std::endl;
    outFile << "   /\\*\\O\\*\\   " << std::endl;
    outFile << "  /\\O\\*\\O\\*\\  " << std::endl;
    outFile << " /\\*\\O\\*\\O\\*\\ " << std::endl;
    outFile << "      ||      " << std::endl;
    outFile << "      ||      " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", 145, 137, target) {
    DEBUG_LOG("ShrubberyCreationForm param constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm() {
    DEBUG_LOG("ShrubberyCreationForm default constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {
    DEBUG_LOG("ShrubberyCreationForm copy constructor called");
}
ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) { AForm::operator=(other); }
    DEBUG_LOG("ShrubberyCreationForm assignment operator constructor called");
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    DEBUG_LOG("ShrubberyCreationForm destructor called");
}

#include "../include/Intern.hpp"
#include "../include/Colors.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

AForm* Intern::makeForm(std::string const& formName,
                        std::string const& target) {
    std::string formType[3] = {"shruberry creation", "robotomy request",
                               "presidential pardon"};

    AForm* newForm = NULL;
    for (int i = 0; i < 3; ++i) {
        if (formName == formType[i]) {
            switch (i) {
            case 0:
                newForm = new ShrubberyCreationForm(target);
                break;
            case 1:
                newForm = new RobotomyRequestForm(target);
                break;
            case 2:
                newForm = new PresidentialPardonForm(target);
                break;
            }
            std::cout << MAGENTA << "Intern creates " << formName << RESET
                      << std::endl;
            return newForm;
        }
    }
    throw Intern::FormNameNotRecognized();
}

const char* Intern::FormNameNotRecognized::what() const throw() {
    return "form name is not recognized!";
}

Intern::Intern() { DEBUG_LOG("Intern default constructor called"); }

Intern::Intern(const Intern& other) {
    (void)other;
    DEBUG_LOG("Intern copy constructor called");
}

Intern& Intern::operator=(const Intern& other) {
    DEBUG_LOG("Intern copy assignment operator called");
    (void)other;
    return *this;
}

Intern::~Intern() { DEBUG_LOG("Intern destructor called"); }

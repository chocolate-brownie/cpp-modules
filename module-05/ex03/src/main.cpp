#include "../include/AForm.hpp"
#include "../include/Colors.hpp"
#include "../include/Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

int main() {
    std::srand(std::time(0));

    AForm* shrubForm = NULL;
    AForm* robReqForm = NULL;
    AForm* newUnsignedDoc = NULL;
    AForm* form = NULL;
    Intern someRandomeIntern;

    try {
        std::cout << "\n\n[EXECUTE WITHOUT SIGNING]" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        shrubForm = someRandomeIntern.makeForm("shruberry creation", "garden");
        robReqForm = someRandomeIntern.makeForm("robotomy request", "prime");
        newUnsignedDoc =
            someRandomeIntern.makeForm("robotomy request", "prime");
        form = someRandomeIntern.makeForm("presidential pardon", "douglas");

    } catch (std::exception& e) {
        std::cerr << "Error creating form: " << e.what() << std::endl;
    }

    if (!shrubForm || !robReqForm || !newUnsignedDoc || !form) return 1;

    std::cout << shrubForm << std::endl;
    std::cout << robReqForm << std::endl;
    std::cout << newUnsignedDoc << std::endl;
    std::cout << form << std::endl;

    Bureaucrat highGrade("Alice(highGrade)", 12);
    Bureaucrat midGrade("Charlie(midGrade)", 67);
    Bureaucrat lowGrade("Shelock(lowGrade)", 144);
    Bureaucrat zaphodBeeblebrox("Zaphod Beeblebrox", 4);

    std::cout << "\n\n[EXECUTE WITHOUT SIGNING]" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    highGrade.executeForm(*shrubForm);
    highGrade.signForm(*shrubForm);
    highGrade.executeForm(*shrubForm);

    std::cout << "\n\n[SIGN BUT EXEC WITH LOW GRADE]" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    highGrade.signForm(*robReqForm);    // can sign
    midGrade.executeForm(*robReqForm);  // but cannot execute
    highGrade.executeForm(*robReqForm); // midGrade already signed!

    std::cout << "\n\n[SIGNING NEW DOCUMENT]" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << YELLOW << highGrade.getName() << " trying to execute the "
              << newUnsignedDoc->getName() << "." << RESET << std::endl;
    highGrade.executeForm(*newUnsignedDoc);

    std::cout << RED << lowGrade.getName() << " trying to sign the "
              << newUnsignedDoc->getName() << "." << RESET << std::endl;
    lowGrade.signForm(*newUnsignedDoc);

    std::cout << YELLOW << midGrade.getName() << " trying to sign the "
              << newUnsignedDoc->getName() << "." << RESET << std::endl;
    midGrade.signForm(*newUnsignedDoc);
    midGrade.executeForm(*newUnsignedDoc);
    highGrade.executeForm(*newUnsignedDoc);

    std::cout << "\n\n[PRESIDENTIAL PARDON]" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    lowGrade.signForm(*form);
    lowGrade.executeForm(*form);
    midGrade.signForm(*form);
    midGrade.executeForm(*form);
    highGrade.signForm(*form);
    highGrade.executeForm(*form);
    zaphodBeeblebrox.signForm(*form);
    zaphodBeeblebrox.executeForm(*form);

    delete shrubForm;
    delete robReqForm;
    delete newUnsignedDoc;
    delete form;

    return 0;
}

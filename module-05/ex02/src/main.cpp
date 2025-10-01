#include "../include/AForm.hpp"
#include "../include/Colors.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(std::time(0));

    ShrubberyCreationForm shrubForm("garden");          // Sign: 145, Exec: 137
    RobotomyRequestForm robReqForm("Optimus Prime");    // Sign: 72, Exec 45
    RobotomyRequestForm newUnsignedDoc("Unsigned doc"); // Sign 72, Exec 45
    PresidentialPardonForm form("The Hitchhiker");      // Sign: 25, Exec: 4

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
    highGrade.executeForm(shrubForm);
    highGrade.signForm(shrubForm);
    highGrade.executeForm(shrubForm);

    std::cout << "\n\n[SIGN BUT EXEC WITH LOW GRADE]" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    highGrade.signForm(robReqForm);    // can sign
    midGrade.executeForm(robReqForm);  // but cannot execute
    highGrade.executeForm(robReqForm); // midGrade already signed!

    std::cout << "\n\n[SIGNING NEW DOCUMENT]" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << YELLOW << highGrade.getName() << " trying to execute the "
              << newUnsignedDoc.getName() << "." << RESET << std::endl;
    highGrade.executeForm(newUnsignedDoc);

    std::cout << RED << lowGrade.getName() << " trying to sign the "
              << newUnsignedDoc.getName() << "." << RESET << std::endl;
    lowGrade.signForm(newUnsignedDoc);

    std::cout << YELLOW << midGrade.getName() << " trying to sign the "
              << newUnsignedDoc.getName() << "." << RESET << std::endl;
    midGrade.signForm(newUnsignedDoc);
    midGrade.executeForm(newUnsignedDoc);
    highGrade.executeForm(newUnsignedDoc);

    std::cout << "\n\n[PRESIDENTIAL PARDON]" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    lowGrade.signForm(form);
    lowGrade.executeForm(form);
    midGrade.signForm(form);
    midGrade.executeForm(form);
    highGrade.signForm(form);
    highGrade.executeForm(form);
    zaphodBeeblebrox.signForm(form);
    zaphodBeeblebrox.executeForm(form);

    return 0;
}

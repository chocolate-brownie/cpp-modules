#include "../include/AForm.hpp"
#include "../include/Colors.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(std::time(0));

    ShrubberyCreationForm shrubForm("Graden"); // Sign: 145, Exec: 137
    std::cout << shrubForm << std::endl;

    RobotomyRequestForm robReqForm("Optimus Prime"); // Sign: 72, Exec 45
    std::cout << robReqForm << std::endl;

    Bureaucrat highGrade("Alice(highGrade)", 1);
    Bureaucrat midGrade("Charlie(midGrade)", 67);
    Bureaucrat lowGrade("Shelock(lowGrade)", 144);

    std::cout << BOLD_WHITE << "----------------------" << RESET << std::endl;
    std::cout << GREEN << "-- Execute without signing --" << RESET << std::endl;
    highGrade.executeForm(shrubForm);
    highGrade.signForm(shrubForm);
    highGrade.executeForm(shrubForm);
    std::cout << BOLD_WHITE << "----------------------" << RESET << std::endl;

    std::cout << GREEN << "Sign but execute with low grade" << RESET
              << std::endl;
    midGrade.signForm(robReqForm);    // can sign
    midGrade.executeForm(robReqForm); // but cannot execute
    highGrade.executeForm(robReqForm);
    highGrade.signForm(robReqForm);
    highGrade.executeForm(robReqForm);

    return 0;
}

#include "../include/AForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(std::time(0));

    ShrubberyCreationForm shrubForm("Graden");
    std::cout << shrubForm << std::endl;

    RobotomyRequestForm robReqForm("Optimus Prime");
    std::cout << robReqForm << std::endl;
    
    

    return 0;
}

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/Colors.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
    Bureaucrat highGrade("Alice", 1); // Can do anything
    Bureaucrat midGrade("Bob", 140);  // Can sign Shrubbery, but can't execute
    Bureaucrat lowGrade("Charlie", 150); // Can't do much

    ShrubberyCreationForm shrubForm("garden"); // Sign 145, Exec 137
    std::cout << CYAN << shrubForm << RESET << std::endl;

    // --- SCENARIO 1: EXECUTE WITHOUT SIGNING ---
    std::cout << BOLD_YELLOW << "\n--- SCENARIO 1: EXECUTE WITHOUT SIGNING ---"
              << RESET << std::endl;
    highGrade.executeForm(shrubForm); // Should fail: not signed

    // --- SCENARIO 2: SIGN, BUT EXECUTE WITH LOW GRADE ---
    std::cout << BOLD_YELLOW
              << "\n--- SCENARIO 2: SIGN, BUT EXECUTE WITH LOW GRADE ---"
              << RESET << std::endl;
    midGrade.signForm(shrubForm);    // Bob (140) can sign (req 145)
    lowGrade.executeForm(shrubForm); // Charlie (150) cannot execute (req 137)

    // --- SCENARIO 3: SUCCESSFUL SIGN AND EXECUTION ---
    std::cout << BOLD_YELLOW
              << "\n--- SCENARIO 3: SUCCESSFUL SIGN AND EXECUTION ---" << RESET
              << std::endl;
    highGrade.executeForm(
        shrubForm); // Alice (1) can execute the form Bob signed

    std::cout
        << "\nCheck for a file named 'garden_shrubbery' in your directory!"
        << std::endl;

    return 0;
}

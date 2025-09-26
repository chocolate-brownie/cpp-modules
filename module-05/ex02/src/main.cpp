#include "../include/Bureaucrat.hpp"
#include "../include/Colors.hpp"
#include "../include/Form.hpp"

int main(void) {

    // --- SCENARIO: Successful Signing ---
    std::cout << BOLD_YELLOW << "--------------------------------------"
              << RESET << std::endl;
    std::cout << BOLD_YELLOW << "----- SCENARIO 1: Successful Signing ---"
              << RESET << std::endl;
    std::cout << BOLD_YELLOW << "--------------------------------------\n"
              << RESET << std::endl;
    try {
        Bureaucrat theoRoosevelt("Theodore Roosevelt", 50);
        std::cout << MAGENTA << theoRoosevelt << RESET << std::endl;
        Form reformAct("Civil Service Reform Act(1883)", 75, 100);

        std::cout << CYAN << "[Before signing]\n"
                  << RESET << reformAct << std::endl;
        theoRoosevelt.signForm(reformAct);
        std::cout << GREEN << "[After signing]\n"
                  << RESET << reformAct << std::endl;

    } catch (const std::exception& e) {
        std::cerr << BOLD_RED << "An unexpected exception occurred: " << RESET
                  << e.what() << std::endl;
    }

    // --- SCENARIO: Boundary Test (Exact Grade) ---
    std::cout << BOLD_YELLOW << "\n-----------------------------------------"
              << RESET << std::endl;
    std::cout << BOLD_YELLOW << "-- SCENARIO 2: Boundary Test (Exact Grade)"
              << RESET << std::endl;
    std::cout << BOLD_YELLOW << "-----------------------------------------\n"
              << RESET << std::endl;
    try {
        Bureaucrat preciseBureaucrat("James Forrestal", 75);
        std::cout << MAGENTA << preciseBureaucrat << RESET << std::endl;
        Form taxForm("Naval Expansion(WW2)", 75, 100);

        std::cout << CYAN << "[Before signing]\n"
                  << RESET << taxForm << std::endl;
        preciseBureaucrat.signForm(taxForm);
        std::cout << GREEN << "[After signing]\n"
                  << RESET << taxForm << std::endl;

    } catch (const std::exception& e) {
        std::cerr << BOLD_RED << "An unexpected exception occurred: " << RESET
                  << e.what() << std::endl;
    }

    // --- SCENARIO: Signing an Already Signed Form ---
    std::cout << BOLD_YELLOW
              << "\n----------------------------------------------" << RESET
              << std::endl;
    std::cout << BOLD_YELLOW << "--- SCENARIO 3: Signing an Already Signed Form"
              << RESET << std::endl;
    std::cout << BOLD_YELLOW
              << "----------------------------------------------\n"
              << RESET << std::endl;
    try {
        Bureaucrat thomasTaylor("Thomas Taylor", 1);
        std::cout << MAGENTA << thomasTaylor << RESET << std::endl;
        Form civilExam("Civil Service Exam", 10, 5);

        std::cout << CYAN << "[Initial State]\n"
                  << RESET << civilExam << std::endl;
        thomasTaylor.signForm(civilExam);
        std::cout << GREEN << "[After thomasTaylor signs]\n"
                  << RESET << civilExam << std::endl;

        std::cout << CYAN << "\n...Now the Thomas tries to sign it again...\n"
                  << RESET;
        thomasTaylor.signForm(civilExam);
        std::cout << GREEN << "[After second attempt]\n"
                  << RESET << civilExam << std::endl;

    } catch (const std::exception& e) {
        std::cerr << BOLD_RED << "An unexpected exception occurred: " << RESET
                  << e.what() << std::endl;
    }

    // --- SCENARIO 3: Signing an Already Signed Form ---
    std::cout << BOLD_RED << "\n----------------------------------------------"
              << RESET << std::endl;
    std::cout << BOLD_RED << "--- SCENARIO 3: Signing an Already Signed Form"
              << RESET << std::endl;
    std::cout << BOLD_RED << "----------------------------------------------\n"
              << RESET << std::endl;

    try {
        Bureaucrat intern("Intern", 150);
        Form topSecret("Top Secret Form", 1, 1);
        std::cout << intern.getName() << " is attempting to sign "
                  << topSecret.getName() << std::endl;
        intern.signForm(
            topSecret); // This will call form.beSigned() which will throw
    } catch (const std::exception& e) {
        /* This catch is inside the signForm method, so we won't see it
           here. The signForm method itself will print the error message. This
           block is just to show the setup that causes the exception. */
    }

    return 0;
}

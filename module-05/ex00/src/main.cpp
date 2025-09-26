#include "../include/Bureaucrat.hpp"

int main(void) {

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "$$decrementGrade() with a valid ranking$$" << std::endl;
    try {
        Bureaucrat wilburCohen("Wilbur Cohen", 34);
        wilburCohen.decrementGrade();
        std::cout << wilburCohen << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "$$decrementGrade() with a invalid ranking$$" << std::endl;
    try {
        Bureaucrat charlesDawes("Charles Dawes", 1299);
        charlesDawes.decrementGrade();
        std::cout << charlesDawes << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "$$incrementGrade() with a valid ranking$$" << std::endl;
    try {
        Bureaucrat allenDulles("Allen Dulles", 6);

        while (allenDulles.getGrade() > 1) {
            allenDulles.incrementGrade();
            std::cout << allenDulles << std::endl;
        }

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "$$incrementGrade() with a invalid ranking$$" << std::endl;
    try {
        Bureaucrat lawrenceEeagle("Lawrence Eagleburger", 123879);

        while (lawrenceEeagle.getGrade() > 1) {
            lawrenceEeagle.incrementGrade();
            std::cout << lawrenceEeagle << std::endl;
        }

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "$$Testing copying$$" << std::endl;
    try {
        Bureaucrat anthonyFauci("Anthony Fauci(4)", 4);
        std::cout << anthonyFauci << std::endl;
        std::cout << "................................" << std::endl;

        Bureaucrat leslieGroves("Leslie Groves(122)", 122);
        std::cout << leslieGroves << std::endl;
        std::cout << "................................" << std::endl;

        leslieGroves = anthonyFauci;
        std::cout << leslieGroves << std::endl;
        std::cout << "................................" << std::endl;

        Bureaucrat haroldIckes(anthonyFauci);
        std::cout << haroldIckes << std::endl;
        std::cout << "................................" << std::endl;

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

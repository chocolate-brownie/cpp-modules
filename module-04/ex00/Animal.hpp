#ifndef ANIMAL_HPP
#define ANIMAL_HPP

namespace Color {
const char RESET[] = "\033[0m";
const char RED[] = "\033[31m";
const char GREEN[] = "\033[32m";
const char BLUE[] = "\033[34m";
const char BOLD[] = "\033[1m";
const char YELLOW[] = "\033[33m";
const char MAGENTA[] = "\033[35m";
const char CYAN[] = "\033[36m";
const char WHITE[] = "\033[37m";
}

#include <string>

class Animal {
    protected:
    std::string type;

    public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    /* Making the method virtual allows the derived classes to access this
    function and modifies thus activating the polymorphic feature */
    virtual void makeSound() const;

    std::string getType() const;
};

#endif

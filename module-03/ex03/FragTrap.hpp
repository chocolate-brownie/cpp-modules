#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
   public:
    FragTrap(void);
    FragTrap(const FragTrap& other);
    ~FragTrap();

    FragTrap(std::string name);

    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif

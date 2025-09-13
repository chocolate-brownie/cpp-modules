#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

namespace Color {
const char RESET[] = "\033[0m";
const char RED[] = "\033[31m";
const char GREEN[] = "\033[32m";
const char BLUE[] = "\033[34m";
const char BOLD[] = "\033[1m";
}  // namespace Color

#include <string>

class ClapTrap {
   protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

   public:
    ClapTrap(void);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap(void);

    ClapTrap(std::string objName);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
};

#endif

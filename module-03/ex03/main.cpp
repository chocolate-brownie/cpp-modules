#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

static void printInformation(const ClapTrap& member) {
    std::cout << std::endl;
    std::cout << "Name: " << member.getName() << std::endl
              << "Hit Points: " << member.getHitPoints() << std::endl
              << "Energy Points: " << member.getEnergyPoints() << std::endl
              << "Attack Damage: " << member.getAttackDamage() << std::endl
              << std::endl;
}

int main() {
    // Checking OCF functions

    ClapTrap member1;
    std::cout << std::endl;
    std::cout << "-------- Use of DEFAULT constructor --------" << std::endl;
    std::cout << Color::GREEN << "Member 1 Info" << Color::RESET << std::endl;
    printInformation(member1);

    std::cout << std::endl;
    std::cout << "-------- Use of NAME constructor --------" << std::endl;
    ClapTrap member2("ClapperTrapper");
    std::cout << Color::GREEN << "Member 2 Info" << Color::RESET << std::endl;
    printInformation(member2);

    std::cout << "-------- Use of COPY constructor --------" << std::endl;
    ClapTrap member3("Christoph");
    std::cout << Color::GREEN << "Member 3 Info" << Color::RESET << std::endl;
    printInformation(member3);
    std::cout << std::endl;

    ClapTrap member4(member3);

    std::cout << Color::GREEN << "Member 4 Info" << Color::RESET << std::endl;
    printInformation(member4);

    std::cout << std::endl;
    std::cout << "-------- Use of COPY ASSIGNMENT OPERATOR --------"
              << std::endl;
    ClapTrap obj1("Clappy");
    std::cout << Color::GREEN << "Obj1 Info" << Color::RESET << std::endl;
    printInformation(obj1);

    ClapTrap obj2("CoppyCat");
    std::cout << "Obj2's name before calling copy assignment operator: "
              << obj2.getName() << std::endl;
    std::cout
        << Color::BLUE
        << "Calling copy assignment operator, copies obj1's data into obj2"
        << std::endl;

    obj2 = obj1;

    std::cout << Color::GREEN << "Obj2 Info" << Color::RESET << std::endl;
    printInformation(obj2);

    std::cout << "\n-------- TESTING MEMBER FUNCTIONS --------" << std::endl;
    member2.takeDamage(5);
    printInformation(member2);
    member2.beRepaired(3);
    printInformation(member2);
    member2.takeDamage(10);
    printInformation(member2);
    member2.beRepaired(5);
    printInformation(member2);

    std::cout << "\n\n-------- TESTING SCAVTRAP --------" << std::endl;
    ScavTrap scav("Scavvy");

    scav.attack("a training dummy");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();
    scav.takeDamage(100);
    printInformation(scav);
    scav.attack("another dummy");  // Should fail

    std::cout << "\n\n-------- TESTING FRAGTRAP --------" << std::endl;
    FragTrap frag("Fraggy");

    frag.attack("a rusty car");
    frag.takeDamage(50);
    frag.beRepaired(25);
    frag.highFivesGuys();
    frag.takeDamage(100);
    printInformation(frag);
    frag.attack("another rusty car");  // Should fail
}

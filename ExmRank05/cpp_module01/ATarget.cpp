#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

ATarget::ATarget(const std::string& type): _type(type) {return;}
ATarget::~ATarget() {return;}

std::string& ATarget::getType() const; {
    return _type;
}

void ATarget::getHitBySpell(const ASpell& src) const {
    std::cout << _type << " has been " src.getEffect() << "!" << std::endl;
}

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

void ASpell::launch(const ATarget &src) const {
    src.getHitBySpell(*this);
}

std::string ASpell::getName() const {
    return _name;
}
std::string ASpell::getEffect() const {
    return _effect;
}

ASpell::ASpell(const std::string& name, const std::string& effect): _name(name), _effect(effect){ return; }
ASpell::~ASpell() {return;}


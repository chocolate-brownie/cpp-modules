/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:51:46 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/28 17:30:14 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) { this->_weapon = NULL; }
void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }

void HumanB::attack() {
  if (_weapon != NULL) {
    std::cout << this->_name << " attacks with their " << _weapon->getType()
              << std::endl;
  }
}
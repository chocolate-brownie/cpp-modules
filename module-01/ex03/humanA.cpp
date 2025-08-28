/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:00:17 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/28 16:28:20 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    : _name(name), _weapon(weapon) {
  return;
}

void HumanA::attack() {
  std::cout << this->_name << " attacks with their " << this->_weapon.getType()
            << std::endl;
}
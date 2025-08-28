/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:53:35 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/28 16:02:45 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/** Getters and Setters */
void Weapon::setType(std::string type) { this->_type = type; }
const std::string &Weapon::getType(void) const { return this->_type; }

/** Constructor */
Weapon::Weapon(std::string type) : _type(type) { return; }
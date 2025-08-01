/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:41:18 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/01 16:11:01 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contact.class.hpp"

/** @note Using this-> is optional here but can make it clearer that you're
referring to a member variable. */
void Contact::setFirstName(std::string name) { this->firstName = name; }
std::string Contact::getFirstName() const { return this->firstName; }

void Contact::setLastName(std::string name) { this->lastName = name; }
std::string Contact::getLastName() const { return this->lastName; }

void Contact::setNickName(std::string name) { this->nickName = name; }
std::string Contact::getNickName() const { return this->nickName; }

void Contact::setDarkestSecret(std::string secret) {
  this->darkestSecret = secret;
}
std::string Contact::getDarkestSecret() const { return this->darkestSecret; }

void Contact::setPhoneNumber(std::string number) { this->phoneNumber = number; }
std::string Contact::getPhoneNumber() const { return this->phoneNumber; };

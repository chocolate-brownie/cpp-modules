/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:13:16 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/01 16:27:52 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include "phonebook.hpp"

class Contact {
private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string darkestSecret;
  std::string phoneNumber;

/** @note its good practice keep the definitions here and move the implementation
to a corresponding file */
public:
  void setFirstName(std::string name);
  std::string getFirstName() const;
  void setLastName(std::string name);
  std::string getLastName() const;
  void setNickName(std::string name);
  std::string getNickName() const;
  void setDarkestSecret(std::string secret);
  std::string getDarkestSecret() const;
  void setPhoneNumber(std::string number);
  std::string getPhoneNumber() const;
};

#endif
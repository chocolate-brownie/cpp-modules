/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:07:33 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/01 17:45:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "contact.class.hpp"

class PhoneBook {
private:
  Contact contacts[8];
  int nbrOfContacts;
  int index;
  std::string getInput(std::string prompt);
  void printContactsTable();

public:
  PhoneBook();
  void addContact();
  void searchContact();
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:14:09 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/01 17:58:49 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contact.class.hpp"
#include "../includes/phonebook.class.hpp"
#include <unistd.h>

PhoneBook::PhoneBook() {
  nbrOfContacts = 0;
  index = 0;

  std::cout << "✅ Phonebook is ready" << std::endl;
  sleep(1);
  std::system("clear");
  std::cout << "🔄 Loading..." << std::endl;
  sleep(1);
  std::system("clear");
}

std::string PhoneBook::getInput(std::string prompt) {
  std::string input = "";
  while (input.empty()) {
    std::cout << prompt;
    getline(std::cin, input);
    if (input.empty()) {
      std::cout << "😓 Input cannot be empty. Please try again." << std::endl;
    }
  }
  return input;
}

void PhoneBook::printContactsTable() {
  std::cout << std::endl
            << "---- ✍️ Contact details ----" << std::endl
            << std::endl;

  std::string separator = "+----------+----------+----------+----------+\n";
  std::cout << separator << std::right << "|" << std::endl;
}

void PhoneBook::addContact() {
  std::system("clear");
  std::cout << std::endl
            << GREEN << "---------------- 📑 Adding a contact ----------------"
            << RESET << std::endl
            << std::endl;

  contacts[index].setFirstName(getInput("First name: "));
  contacts[index].setLastName(getInput("Last name: "));
  contacts[index].setPhoneNumber(getInput("Phone number: "));
  contacts[index].setDarkestSecret(getInput("Darkest secret: "));

  index = (index + 1) % 8;
  if (nbrOfContacts < 8) {
    nbrOfContacts++;
  }

  std::cout << std::endl << "🥳 Contact added successfully" << std::endl;
  sleep(1);
}

void PhoneBook::searchContact() { printContactsTable(); }

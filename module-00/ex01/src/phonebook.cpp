/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:14:09 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/05 15:36:10 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"
#include "../includes/contact.class.hpp"
#include "../includes/phonebook.class.hpp"

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

std::string PhoneBook::truncate(std::string text) {
  if (text.length() > 10) {
    return text.substr(0, 9) + ".";
  }
  return text;
}

void PhoneBook::printContactsTable() {
  std::cout << std::endl
            << YELLOW
            << "---------------- 🔍 Searching a contact ----------------"
            << RESET << std::endl
            << std::endl;
  std::cout << BLUE << "+----------+----------+----------+----------+" << RESET
            << std::endl;
  std::cout << BLUE << "|" << RESET << std::setw(10) << "Index" << BLUE << "|"
            << RESET << std::setw(10) << "First Name" << BLUE << "|" << RESET
            << std::setw(10) << "Last Name" << BLUE << "|" << RESET
            << std::setw(10) << "Nickname" << BLUE << "|" << RESET << std::endl;
  std::cout << BLUE << "+----------+----------+----------+----------+" << RESET
            << std::endl;

  for (int i = 0; i < nbrOfContacts; i++) {
    std::cout << BLUE << "|" << RESET << std::setw(10) << i << BLUE << "|"
              << RESET << std::setw(10) << truncate(contacts[i].getFirstName())
              << BLUE << "|" << RESET << std::setw(10)
              << truncate(contacts[i].getLastName()) << BLUE << "|" << RESET
              << std::setw(10) << truncate(contacts[i].getNickName()) << BLUE
              << "|" << RESET << std::endl;
  }
  std::cout << BLUE << "+----------+----------+----------+----------+" << RESET
            << std::endl;

  if (nbrOfContacts == 0) {
    std::cout << "\nPhonebook is empty. Please ADD a contact first."
              << std::endl;
    sleep(2);
    return;
  }
}
void PhoneBook::addContact() {
  std::system("clear");

  if (nbrOfContacts == 8) {
    std::cout << YELLOW << "⚠️  Warning: The phonebook is full." << RESET << std::endl;
    std::cout << "Adding a new contact will replace the oldest one." << std::endl;
    sleep(1);
  }

  std::cout << std::endl
            << GREEN << "---------------- 📑 Adding a contact ----------------"
            << RESET << std::endl
            << std::endl;

  contacts[index].setFirstName(getInput("First name: "));
  contacts[index].setLastName(getInput("Last name: "));
  contacts[index].setNickName(getInput("Nickname: "));
  contacts[index].setPhoneNumber(getInput("Phone number: "));
  contacts[index].setDarkestSecret(getInput("Darkest secret: "));

  index = (index + 1) % 8;
  if (nbrOfContacts < 8) {
    nbrOfContacts++;
  }

  std::cout << std::endl << "🥳 Contact added successfully" << std::endl;
  sleep(1);
}

void PhoneBook::searchContact() {
  std::system("clear");
  printContactsTable();

  if (nbrOfContacts == 0) {
    return;
  }

  std::cout << std::endl;
  std::string input = getInput("Enter an index for full information: ");
  std::stringstream ss(input);
  int chosen_index = -1;

  if (ss >> chosen_index && ss.eof()) {
    if (chosen_index >= 0 && chosen_index < nbrOfContacts) {
      std::cout << std::endl
                << GREEN << "--- ✅ Contact Details ---" << RESET << std::endl
                << std::endl;
      std::cout << "First Name:     " << contacts[chosen_index].getFirstName()
                << std::endl;
      std::cout << "Last Name:      " << contacts[chosen_index].getLastName()
                << std::endl;
      std::cout << "Nickname:       " << contacts[chosen_index].getNickName()
                << std::endl;
      std::cout << "Phone Number:   " << contacts[chosen_index].getPhoneNumber()
                << std::endl;
      std::cout << "Darkest Secret: "
                << contacts[chosen_index].getDarkestSecret() << std::endl;
    } else {
      std::cout << std::endl << "❌ Error: Index is out of range." << std::endl;
    }
  } else {
    std::cout << std::endl << "❌ Error: Invalid input." << std::endl;
  }

  std::cout << std::endl << BLUE << "Press Enter to continue..." << RESET;
  std::cin.get();
}

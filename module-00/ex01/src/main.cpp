/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:19:38 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/01 18:54:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.class.hpp"
#include "../includes/phonebook.hpp"

static void showManual(void) {
  sleep(1);
  std::system("clear");

  std::cout << std::endl
            << "------------------- 📔 Phonebook -------------------"
            << std::endl
            << std::endl;
  std::cout << "Please choose one of the following commands:" << std::endl
            << std::endl;
  std::cout << GREEN << "📑 ADD:    " << RESET << "Save a new contact"
            << std::endl;
  std::cout << YELLOW << "🔎 SEARCH: " << RESET << "Display a specific contact"
            << std::endl;
  std::cout << RED << "🚪 EXIT:   " << RESET << "Quit the phonebook"
            << std::endl
            << std::endl;
}

int main(void) {
  std::string userInput;
  PhoneBook phoneBook;

  while (true) {
    showManual();
    std::cout << "👉 Choose an option: ";
    getline(std::cin, userInput);

    if (userInput == "EXIT") {
      std::cout << "Goodbye! 👋" << std::endl;
      sleep(1);
      std::system("clear");
      break;
    } else if (userInput == "ADD") {
      phoneBook.addContact();
    } else if (userInput == "SEARCH") {
      phoneBook.searchContact();
    } else {
      std::cout << RED << "❌ Error: Invalid option. Please try again." << RESET
                << std::endl;
    }
  }
  return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:19:38 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/26 18:30:54 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"
#include <cstdlib>
#include <string>

static void showManual() {

  cout << endl << "--Phonebook--" << endl << endl;
  cout << "The program only accepts..." << endl << endl;
  cout << GREEN << "ADD: " << RESET << "save a new contact" << endl;
  cout << YELLOW << "SEARCH: " << RESET << "display a specific contact" << endl;
  cout << RED << "EXIT: " << RESET
       << "The program quits and the contacts are lost forever!" << endl
       << endl;
}

int main(void) {

  string userInput;
  while (1) {
    showManual();
    cout << "Choose an option: ";
    getline(cin, userInput);
    if (userInput == "EXIT") {
      cout << "Exiting the phonebook" << endl;
      return 0;
    } else if (userInput == "ADD") {
      //   save_contact(); TODO:
    } else if (userInput == "SEARCH") {
      //   search_contact(); TODO:
    }
  }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:02:50 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/30 19:07:25 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl
      << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl
      << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years, whereas you started working here just last month."
      << std::endl
      << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl
            << std::endl;
}

void Harl::complain(std::string level) {
  void (Harl::*funcPtr[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
                                &Harl::error};

  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  int i = -1;
  while (++i < 4) {
    if (i == 3 && level != levels[i]) {
      i = -1;
      break;
    }
    if (levels[i] == level)
      break;
  }

  switch (i) {
  default:
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
    break;
  case 0:
    (this->*funcPtr[0])();
  case 1:
    (this->*funcPtr[1])();
  case 2:
    (this->*funcPtr[2])();
  case 3:
    (this->*funcPtr[3])();
    break;
  }
  return;
}
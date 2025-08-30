/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:02:50 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/30 17:53:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <stdlib.h>

void Harl::debug(void) {
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning(void) {
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years, whereas you started working here just last month."
      << std::endl;
}

void Harl::error(void) {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

/**
Dynamic Dispatch Without If/Else

Instead of writing code like:

if (level == "DEBUG") debug();
else if (level == "INFO") info();
else if (level == "WARNING") warning();
else if (level == "ERROR") error();

return_type (ClassName::*pointer_name)(argument_types) =
&ClassName::member_function;
*/
void Harl::complain(std::string level) {
  void (Harl::*actions[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
                                &Harl::error};
  int lvl = atoi(level.c_str());
  (this->*actions[lvl])();
}
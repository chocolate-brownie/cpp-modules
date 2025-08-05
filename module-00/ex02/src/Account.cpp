/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:51:44 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/05 17:56:12 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*----------------------------------------------------------------------------*/
/*---------------------------Constructor--------------------------------------*/
/*----------------------------------------------------------------------------*/
Account::Account(int initial_deposit) {
  this->_accountIndex = _nbAccounts;

}



void Account::_displayTimestamp(void) {
  std::time_t now = std::time(NULL);
  struct tm *time_info = std::localtime(&now);

  std::cout << '[' << (time_info->tm_year + 1900) << std::setw(2)
            << std::setfill('0') << (time_info->tm_mon + 1) << std::setw(2)
            << std::setfill('0') << time_info->tm_mday << '_' << std::setw(2)
            << std::setfill('0') << time_info->tm_hour << std::setw(2)
            << std::setfill('0') << time_info->tm_min << std::setw(2)
            << std::setfill('0') << time_info->tm_sec << ']';
  return;
}

int main(void) {

  return 0;
}

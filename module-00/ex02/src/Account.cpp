/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:51:44 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/05 19:07:44 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
#include <algorithm>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* Function to display the time in the given format*/
void Account::_displayTimestamp(void) {
  std::time_t now = std::time(NULL);
  struct tm *time_info = std::localtime(&now);

  std::cout << MAGENTA << '[' << (time_info->tm_year + 1900) << std::setw(2)
            << std::setfill('0') << (time_info->tm_mon + 1) << std::setw(2)
            << std::setfill('0') << time_info->tm_mday << '_' << std::setw(2)
            << std::setfill('0') << time_info->tm_hour << std::setw(2)
            << std::setfill('0') << time_info->tm_min << std::setw(2)
            << std::setfill('0') << time_info->tm_sec << ']' << RESET;
  return;
}

/*------------+ ------------+ ------------+ ------------+ ------------*/
/*------------+ ----CONSTRUCTOR AND DECONSTRUCTOR---------------------*/
/*------------+ ------------+ ------------+ ------------+ ------------*/
Account::Account(int initial_deposit) {
  this->_accountIndex = _nbAccounts;
  _nbAccounts++;

  this->_amount = initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  _totalAmount += initial_deposit;

  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << "; amount:" << this->_amount
            << "; created" << std::endl;
}

Account::~Account() {
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << "; amount:" << this->_amount
            << "; closed" << std::endl;
}

int main(void) {
  Account account1(500);
  Account account2(100);
  return 0;
}

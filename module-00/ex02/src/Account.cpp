/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:51:44 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/25 19:26:10 by mgodawat         ###   ########.fr       */
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

/*------------+ ---------+ GETTERS & SETTERS +---------------------*/
int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

/*------------+ ---------+ TIMESTAMP +---------------------*/
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

/*------------+ ----CONSTRUCTOR AND DECONSTRUCTOR---------------------*/
Account::Account(int initial_deposit) {
  this->_accountIndex = _nbAccounts;
  _nbAccounts++;

  this->_amount = initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  _totalAmount += initial_deposit;

  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created" << std::endl;
}

Account::~Account() {
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

/*------------+ ---- MAIN FUNCTIONS ---------------------*/

/* Step 1: Implement the function displayAccountInfos
that display the account information.
According to the tests.cpp file, the first functions called after the accounts
are created are displayAccountsInfos() and displayStatus(). */
void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << YELLOW << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl << RESET;
}

/* Step 2: Implement displayStatus()
This function is called for each individual account object.
Its job is to print the details of that specific account.
Your Task: Write the code for this function. It should print the account's
index, current amount, and its number of deposits and withdrawals. */
void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/* Step 3: Implement makeDeposit()
This function is called for each account to add money to its balance.
Your implementation needs to update both the individual account's data and the
shared static totals. */
void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";deposit:" << deposit;

  this->_amount += deposit;
  this->_nbDeposits++;

  _totalAmount += deposit;
  _totalNbDeposits++;

  std::cout << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

/* Step 4: Implement makeWithdrawal()
This function attempts to remove money from an account. The key part is checking
if the account has enough funds. */
bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";withdrawal:";

  if (withdrawal > this->_amount) {
    std::cout << "refused" << std::endl;
    return false;
  }

  std::cout << withdrawal;
  this->_amount -= withdrawal;
  this->_nbWithdrawals++;

  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;

  std::cout << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

  return true;
}

/* Step 5: This function simply returns the current balance of the account. */
int Account::checkAmount(void) const {
  return this->_amount;
}
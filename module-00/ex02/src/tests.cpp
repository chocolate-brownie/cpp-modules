// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "../includes/Account.hpp"
#include <algorithm>
#include <functional>
#include <vector>

int main(void) {

  typedef std::vector<Account::t> accounts_t;
  typedef std::vector<int> ints_t;
  typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

  /** It creates an array of integers called amounts to be used as the starting
  balances for the new accounts.*/
  int const amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
  size_t const amounts_size(sizeof(amounts) / sizeof(int));

  /** The line accounts_t accounts( amounts, amounts + amounts_size );
  creates a std::vector (a dynamic array) of Account objects. */
  accounts_t accounts(amounts, amounts + amounts_size);
  accounts_t::iterator acc_begin = accounts.begin();
  accounts_t::iterator acc_end = accounts.end();

  /** It creates two more integer arrays: d for deposits and w for withdrawals.
  These contain the exact values that will be deposited into and withdrawn from
  the accounts. */
  int const d[] = {5, 765, 564, 2, 87, 23, 9, 20};
  size_t const d_size(sizeof(d) / sizeof(int));
  ints_t deposits(d, d + d_size);
  ints_t::iterator dep_begin = deposits.begin();
  ints_t::iterator dep_end = deposits.end();

  int const w[] = {321, 34, 657, 4, 76, 275, 657, 7654};
  size_t const w_size(sizeof(w) / sizeof(int));
  ints_t withdrawals(w, w + w_size);
  ints_t::iterator wit_begin = withdrawals.begin();
  ints_t::iterator wit_end = withdrawals.end();

  /** Account::displayAccountsInfos();: This calls your static function
  to print the first summary line of the bank's total funds. */
  Account::displayAccountsInfos();
  /** This is a loop that calls your displayStatus() function on every single
  account, printing each one's individual balance and transaction history. */
  std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

  /** A for loop iterates through all the accounts and the deposits array at the
  same time.

  Inside the loop, (*(it.first)).makeDeposit( *(it.second) ); calls your
  makeDeposit function on each account, passing in the corresponding amount from
  the d array. This is where the "deposit" log messages are generated.*/
  for (acc_int_t it(acc_begin, dep_begin);
       it.first != acc_end && it.second != dep_end;
       ++(it.first), ++(it.second)) {

    (*(it.first)).makeDeposit(*(it.second));
  }

  /** The program calls displayAccountsInfos() and displayStatus() again so you
  can see the state of all accounts after the deposits have been made. */
  Account::displayAccountsInfos();
  std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

  /* The program prints the status of all accounts one last time.
  When main returns 0, the program ends. At this exact moment, all the
  Account objects in the accounts vector are destroyed, and your ~Account()
  destructor is called for each one, printing the final "closed" messages. */
  for (acc_int_t it(acc_begin, wit_begin);
       it.first != acc_end && it.second != wit_end;
       ++(it.first), ++(it.second)) {

    (*(it.first)).makeWithdrawal(*(it.second));
  }

  Account::displayAccountsInfos();
  std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

  return 0;
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

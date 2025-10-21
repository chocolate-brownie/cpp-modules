#ifndef BITCOINEXCHANGEEXCEPTIONS_HPP
#define BITCOINEXCHANGEEXCEPTIONS_HPP

#include <exception>
#include <string>

class BitCoinExchangeException : public std::exception {
 private:
  std::string _msg;

 public:
  explicit BitCoinExchangeException(const std::string& message) throw();
  virtual ~BitCoinExchangeException() throw();

  virtual const char* what() const throw();
};

#endif

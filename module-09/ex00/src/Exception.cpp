#include "../include/BitcoinExchangeException.hpp"

BitCoinExchangeException::BitCoinExchangeException(
    const std::string& message) throw()
    : _msg(message) {}

BitCoinExchangeException::~BitCoinExchangeException() throw() {}

const char* BitCoinExchangeException::what() const throw() {
  return _msg.c_str();
}

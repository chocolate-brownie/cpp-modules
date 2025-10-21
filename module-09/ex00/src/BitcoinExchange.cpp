#include "../include/BitcoinExchange.hpp"

BitCoinExchange::BitCoinExchange() : _dbFilePath("data/data.csv") {
  BitCoinExchange::_parseDbFile(_dbFilePath);

#ifdef DEBUG
  std::cout << "\n[DEBUG]: Database parsing complete. Map size is: "
            << _priceDatabase.size() << " ---" << std::endl;
  std::map<std::string, double>::iterator it = _priceDatabase.begin();
  for (int i = 0; i < 5 && it != _priceDatabase.end(); ++i, ++it) {
    std::cout << it->first << " : " << it->second << std::endl;
  }
  std::cout << std::endl;
#endif
}

BitCoinExchange::~BitCoinExchange() { return; }

#include "../include/BitcoinExchange.hpp"

// -------------------- Constructor ------------------------------------
BitCoinExchange::BitCoinExchange() : _dbFilePath("data/data.csv") {
    BitCoinExchange::_parseDbFile(_dbFilePath);

#ifdef DEBUG
    std::cout << "\n[DEBUG]: Constructor. Map size is: "
              << _priceDatabase.size() << " ---" << std::endl;
    std::map<std::string, double>::iterator it = _priceDatabase.begin();
    for (int i = 0; i < 5 && it != _priceDatabase.end(); ++i, ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    std::cout << std::endl;
#endif
}

BitCoinExchange::BitCoinExchange(const BitCoinExchange& other)
    : _dbFilePath(other._dbFilePath) {
    _priceDatabase = other._priceDatabase;
    _priceInputFile = other._priceInputFile;
#ifdef DEBUG
    std::cout << "[DEBUG]: Copy constructor called" << std::endl;
#endif
}

BitCoinExchange& BitCoinExchange::operator=(const BitCoinExchange& other) {
#ifdef DEBUG
    std::cout << "[DEBUG]: Copy assignment operator called" << std::endl;
#endif
    if (this != &other) {
        _priceDatabase = other._priceDatabase;
        _priceInputFile = other._priceInputFile;
    }
    return *this;
}

// -------------------- Deconstructor ------------------------------------
BitCoinExchange::~BitCoinExchange() { return; }

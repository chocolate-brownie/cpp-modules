#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*
1. Parse the data.csv file and push the data into a struct or a class

2. Process the input file (check for the file validation), program must parse
and validate the "date | value" format. handle the errors as shown in the
examples, such as "Error: bad input" or "Error: not a positive number."

3. Using maps specifiy the key as the DATE as [year-month-day] so you can
trigger it to the searching algorithm. How will you use the map to solve the
more complex problem of finding the closest earlier date when an exact match
isn't found? What specific std::map functions might help you with that?

4. output message must end with a newline character and be displayed to the
standard output 2011-01-03 => 3 = 0.9
*/

#include <cstdio>
#include <cstdlib>
#include <fstream>   // IWYU pragma: keep
#include <iostream>  // IWYU pragma: keep
#include <map>
#include <sstream>  // IWYU pragma: keep
#include <string>

#include "BitcoinExchangeException.hpp"  // IWYU pragma: keep

class BitCoinExchange {
private:
    std::map<std::string, double> _priceDatabase;
    std::map<std::string, double> _priceInputFile;
    const std::string             _dbFilePath;

    void   _parseDbFile(const std::string& dbFilePath);
    double _findPriceForDate(const std::string& date) const;

public:
    void processInputFile(const std::string& filePath);

    BitCoinExchange();
    BitCoinExchange(const BitCoinExchange& other);
    BitCoinExchange& operator=(const BitCoinExchange& other);
    ~BitCoinExchange();
};

#endif

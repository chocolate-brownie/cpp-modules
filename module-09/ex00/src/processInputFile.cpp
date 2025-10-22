#include <iostream>
#include <sstream>

#include "../include/BitcoinExchange.hpp"

/* Check whether the first 10 characters in the line that I am reading is a
 * valid date */
static bool isValidDateFormat(const std::string& date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' && date[7] != '-') return false;

    unsigned int year, month, day;
    char dash1, dash2;

    std::istringstream ss(date);
    if (!(ss >> year >> dash1 >> month >> dash2 >> day)) return false;
    if (!ss.eof()) return false;

    if (!((month >= 1 && month <= 12) || (day >= 1 && day <= 31))) return false;

    // Basic check for months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    // Check for February and leap years
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (isLeap && day > 29) return false;
        if (!isLeap && day > 28) return false;
    }

    return true;
}

static bool isValidValue(const double val) {
    if (val < 0 || val > 1000) {
        std::cerr << "Error: A valid value must be either a float or a "
                     "positive integer, between 0 and 1000"
                  << std::endl;
        return false;
    }
    return true;
}

/* [TODO] This method should validate the current reading line, whether the line
 * is exactly the xxxx-xx-xx | double or a comment */
static bool parseLine(std::string& readLine, std::string& date, double& val) {
    std::istringstream ss(readLine);
    /* [NOTE] The extraction operator (>>) reads from this internal buffer until
     * it hits whitespace or the end of the string, parsing and converting the
     * input as needed (e.g., converting string tokens to integers or other
     * types). */
    char seperator;
    if (!(ss >> date >> seperator >> val)) return false;

    if (!ss.eof()) {
        std::cerr << "Error: Bad input " << readLine << std::endl;
        return false;
    }

    if (!isValidDateFormat(date)) {
        std::cerr << "Error: Invalid date format " << date << std::endl;
        return false;
    } else if (seperator != '|') {
        std::cerr << "Error: Invalid seperator " << seperator << std::endl;
        return false;
    } else if (isValidValue(val)) {
        std::cerr << "Error: Invalid value " << val << std::endl;
        return false;
    }

    return true;
}

/* [TODO] Algorithm
 * if the current line starts with a '#' std::cout that line
 * if the current line matches the format of date | btcAmount do the
 * algorithm to find the value everything else should be not valid */
void BitCoinExchange::processInputFile(const std::string& filePath) {
    std::ifstream file(filePath.c_str());
    if (!file.good())
        throw BitCoinExchangeException("Input file could not be opened.");

    std::string readLine;
    while (std::getline(file, readLine)) {
        if (readLine.empty()) continue;

        std::string date;
        double val;

        /* Check if not the readLine is a valid format according to date | val
         * throw exception */
        if (!parseLine(readLine, date, val))
            throw BitCoinExchangeException(
                "Current input is not a valid line format.\nPlease follow the "
                "format [date | value]\nExample: 2011-12-23 | 4");

        double price = BitCoinExchange::_findPriceForDate(date);
        std::cout << date << "=>" << val << " = " << (val * price) << std::endl;
        return;
    }

#ifdef DEBUG
    std::cout << "\n[DEBUG]: Input file parsing complete. Map size is: "
              << _priceInputFile.size() << " ---" << std::endl;
    for (std::map<std::string, double>::iterator it = _priceInputFile.begin();
         it != _priceInputFile.end(); ++it) {
        std::cout << "Date: " << it->first << ", Rate: " << it->second
                  << std::endl;
    }
    std::cout << std::endl;
#endif

    return;
}

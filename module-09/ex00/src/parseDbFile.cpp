#include "../include/BitcoinExchange.hpp"
#include "../include/BitcoinExchangeException.hpp"
/* This method would check the validity of the data.csv file skip the first line
and push the date and rate seperate by a ',' into a std::map container */
void BitCoinExchange::_parseDbFile(const std::string& dbFilePath) {
    std::ifstream file(dbFilePath.c_str());
    if (!file.good()) {
        throw BitCoinExchangeException(
            "Error: Databse file does not exist or cannot be opened");
    }

    std::string line;
    std::getline(file, line);  // read and discard the headerline

    while (std::getline(file, line)) {
        /* I save the line I read with getline to isstream so I can read the
         * line again to seperate the date, and the exrate */
        std::istringstream ss(line);

        std::string date;
        std::string rateStr;

        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            double rate;
            std::istringstream ss(rateStr);

            /* If I can convert the rateStr to rate (double) using istringstream
             * push it to the map */
            if (!(ss >> rate))
                throw BitCoinExchangeException(
                    "The string was not a valid number");
            _priceDatabase[date] = rate;  // map updated for each line
        }
    }

    file.close();
}

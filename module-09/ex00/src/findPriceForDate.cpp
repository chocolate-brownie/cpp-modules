#include "../include/BitcoinExchange.hpp"

double BitCoinExchange::_findPriceForDate(const std::string& date) const
{
    /* [NOTE] The lower_bound() member function in std::map is used to find the
     * position of the first element whose key is not less than (that is,
     * greater than or equal to) a given key. It returns an iterator to this
     * element within the map.​
     *
     * for example: if you wanna find the lowr_bound() for "2012-01-13" it would
     points to...
     *
     * 2012-01-08,7.2
     * 2012-01-11,7.1
     * 2012-01-14,6.81 <----- HERE
     *
     * and to get to the closest date regarding to the price you would have to
     get one step backwards. */

    std::map<std::string, double>::const_iterator it = _priceDatabase.lower_bound(date);

    if (it != _priceDatabase.end() && it->first == date)
        return it->second;
    if (it == _priceDatabase.begin())
        return it->second;

    --it;
    return it->second;
}

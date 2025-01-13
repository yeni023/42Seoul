#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <ctime>

class BitcoinExchange {
    private:
        std::map<std::string, float> _exchangeRates;

        bool isValidDate(std::string date) const;
        void printError(std::string msg);
        void printExchange(std::string date, float value);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadExchangeRates(std::string data);
        void exchange(std::string input);
};

#endif
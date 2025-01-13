#include "BitcoinExchange.hpp"

// void leaks() {
//   system("leaks btc");
// }

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange exchange;
        exchange.loadExchangeRates("data.csv");
        exchange.exchange(av[1]);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    // atexit(leaks);
    return 0;
}
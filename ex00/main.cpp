#include "BitcoinExchange.hpp"


int main(int ac,char **ag)
{
    if (ac != 2)
        return 0;
    Btc mybtc;
    mybtc.all(ag[1]);
    return 0;
}
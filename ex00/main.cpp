#include "BitcoinExchange.hpp"


int main(int ac,char **ag)
{
    if (ac != 2)
    {
        std::cout << "Error" <<std::endl;
        return 0;
    }
    Btc mybtc;
    mybtc.all(ag[1]);
    return 0;
}
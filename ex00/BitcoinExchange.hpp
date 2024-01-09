#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdlib.h>

class Btc
{
    private:
        std::map<std::string,float> map;
        std::string data_date;
        std::string data_value;
        std::string date;
        std::string value;
        size_t year;
        size_t month;
        size_t day;
        float btc_value;
        void make_map(void);
        int day_value_check();
        int value_check();
        void    check_for_empty(std::string);
    public:
        Btc();
        ~Btc();
        Btc(const Btc &other);
        Btc &operator=(const Btc &other);
        void all(std::string);
};
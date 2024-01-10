#include "BitcoinExchange.hpp"

Btc::Btc()
{

}

Btc::~Btc()
{

}

Btc::Btc(const Btc &other)
{
    *this = other;
}

Btc &Btc::operator=(const Btc &other)
{
    if (this != &other)
    {
        map = other.map;
        data_date = other.data_date;
        data_value = other.data_value;
        date = other.date;
        value = other.value;
        year = other.year;
        month = other.month;
        day = other.day;
        btc_value = other.btc_value;
    }
    return *this;
}

int Btc::value_check()
{
    int j = 0;
    int k = 0;
    for (int i = 0; value[i] ; i++)
    {
        if (value[i] == '-' && k == 0)
        {
            k++;
            continue;
        }
        if (isdigit(value[i]))
            continue;
        if (value[i] == '.' && isdigit(value[i - 1])  && isdigit(value[i + 1]) && j == 0)
        {
            j++;
            continue;
        }
        throw std::out_of_range("Error: bad input =>");
    }
    char* value_c = &value[0];
    btc_value= std::atof(value_c) ;
    if (btc_value < 0)
        throw std::out_of_range("Error: not a positive number ");
    if (btc_value > 1000)
        throw std::out_of_range("Error: too large a number ");
    return 1;
}

int Btc::day_value_check()
{
    switch (month) 
    {
        case 4:
        case 6:
        case 9:
        case 11:
            if (day < 1 || day > 30)
                return 0;
            break;
        case 2:
            if (year % 4 == 0) {
                if (day < 1 || day > 29)
                    return 0;
            } 
            else {
                if (day < 1 || day > 28)
                    return 0;
            }
            break;
        default:
            if (day < 1 || day > 31)
                return 0;
            break;
    }
    return (1);
}


void Btc::make_map()
{
    std::ifstream file("data.csv");
    std::string line;

    if (!file.is_open())
    {
        std::cout << "Error: file does not exist" << std::endl;
        exit(1);
    }
    if (file.peek() == std::ifstream::traits_type::eof()) 
    {
        std::cout << "Error: file is empty" << std::endl;
        exit(1);
    }
    std::getline(file,line);
    while(std::getline(file,line))
    {
        data_date = line.substr(0,10);
        data_value = line.substr(11);
        char* c_value = &data_value[0];
        map[data_date] = std::atof(c_value);
    }
}

void Btc::check_for_empty(std::string line)
{
    int i = 0;
    while(line[i] == ' ')
        i++;
    if (line[i] == '\0')
        throw std::out_of_range("Error: empty line");
}


void Btc::parsing_date(std::string line)
{
    if (line[11] != '|')
        throw std::out_of_range("Error: bad input =>");
    if (line[10] != ' ' || line[12] != ' ')
        throw std::out_of_range("Error: bad input =>");
    date = line.substr(0,10);
    value = line.substr(13);
    if (value.length() == 0)
        throw std::out_of_range("Error: bad input =>");
    if (date.length() != 10)
        throw std::out_of_range("Error: bad input =>");
   if (date[4]!= '-' || date[7] != '-')
        throw std::out_of_range("Error: bad input =>");
   for(int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (isdigit(date[i]))
            continue;
        throw std::out_of_range("Error: bad input =>");
    }
}

void Btc::all(std::string str)
{
    std::ifstream file(str.c_str());
    std::string line;

    if (!file.is_open())
    {
        std::cout << "Error: file does not exist" << std::endl;
        exit(1);
    }
    if (file.peek() == std::ifstream::traits_type::eof()) 
    {
        std::cout << "Error: file is empty" << std::endl;
        exit(1);
    }
    std::getline(file,line);
    if(line != "date | value")
    {
        std::cout << "Error: invalid file format" << std::endl;
        exit(1);
    }
    make_map();
    while(std::getline(file,line))
    {
        try
        {
            check_for_empty(line);
            parsing_date(line);
            year = atoi((line.substr(0,4)).c_str());
            if (year < 2009 || year > 9999)
                throw std::out_of_range("Error: bad input =>");
            month = atoi((line.substr(5,2)).c_str());
            if (month < 1 || month > 12)
                throw std::out_of_range("Error: bad input =>");
            day = atoi((line.substr(8,2)).c_str());
            if (day_value_check() == 0)
                throw std::out_of_range("Error: bad input =>");
            value_check();
            std::map<std::string,float>::iterator it;
            it = map.lower_bound(date);
            if (date == it->first)
                std::cout<<date<<" => "<<value<<" = "<<btc_value * it->second<<std::endl;
            else if (it != map.begin())
            {
                it--;
                std::cout<<date<<" => "<<value<<" = "<<btc_value * it->second <<std::endl;
            }
            else 
                std::cout<<date<<" => "<<value<<" = "<<btc_value * it->second <<std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << " " << line <<std::endl;}
    }
}
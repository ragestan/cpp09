#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{    
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        myStack = other.myStack;
        top_value = other.top_value;
        not_top_value = other.not_top_value;
    }
    return *this;
}

void    RPN::error_check(std::string str)
{
    int i = 0;

    while (str[i] == ' ')
            i++;
    if (isdigit(str[i]))
                i++;
    while (str[i] == ' ')
            i++;
    if (str[i] == '\0')
        throw std::out_of_range("Error");
    while (str[i]) {
        if (isdigit(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' )
            i++;
        else
            throw std::out_of_range("Error");
        if (str[i] == ' ')
            i++;
        else if (str[i] == '\0')
            break;
        else
            throw std::out_of_range("Error");
    }
}


void RPN::operation(char op)
{
    if (myStack.size() < 2)
        throw std::out_of_range("Error");
    top_value = myStack.top(); 
    myStack.pop();
    not_top_value = myStack.top();
    myStack.pop();
    switch (op) {
        case '+':
            myStack.push(not_top_value + top_value);
            break;
        case '-':
            myStack.push(not_top_value - top_value);
            break;
        case '*':
            myStack.push(not_top_value * top_value);
            break;
        case '/':
            if (top_value != 0)
                myStack.push(not_top_value / top_value);
            else
                throw std::out_of_range("Error: Division by zero");
            break;
    }
}

void RPN::parsing_ag(std::string str)
{
    int i = 0;
    try {
        error_check(str);
        while(str[i]) {
            if (str[i] == ' ') {
                i++;
                continue;
            }
            if (isdigit(str[i])) {
                myStack.push(str[i] - '0');
                i++;
                continue;
            } 
            if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' ) {
                operation(str[i]);
                i++;
            }
        }
        if (myStack.size() != 1)
            throw std::out_of_range("Error");
        std::cout << myStack.top() << std::endl;
    }
    catch (std::exception &e) {
            std::cerr << e.what() << std::endl;}
}
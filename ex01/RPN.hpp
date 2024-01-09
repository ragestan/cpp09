#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stack>

class RPN
{
    private:
        std::stack<int> myStack;
        int top_value;
        int not_top_value;
        void error_check(std::string);
        void operation(char op);
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        void parsing_ag(std::string);
};
#include "RPN.hpp"

int main(int ac, char **ag)
{
    if (ac != 2)
    {
        std::cout << "Error" <<std::endl;
        return 0;
    }
    RPN rp;
    rp.parsing_ag(ag[1]);
    return 0;
}
#include "PmergeMe.hpp"

int main(int ac,char **ag)
{
    if (ac <= 2 || ac > 3001)
        return 0;
    PmergeMe me;
    std::cout << "Before: " ;
    for(int i = 1; i < ac; i++)
        std::cout << ag[i] << " ";
    std::cout << std::endl;
    clock_t start = clock();
    me.sort_Ford_Johnson_vector(ag);
    clock_t end = clock();
    me.print();
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::victor : " << (float)((end - start)/CLOCKS_PER_SEC) << " us" << std::endl;
    start = clock();
    me.sort_Ford_Johnson_deque(ag);
    end = clock();
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << (float)((end - start)/CLOCKS_PER_SEC) << " us" << std::endl;
    return 0;
}
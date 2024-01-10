#include "PmergeMe.hpp"

int main(int ac,char **ag)
{
    if (ac <= 2 || ac > 3001)
        return 0;
    try {
        PmergeMe me;
        clock_t start = clock();
        me.sort_Ford_Johnson_vector(ag);
        clock_t end = clock();
        std::cout << "Before: " ;
        for(int i = 1; i < ac; i++)
            std::cout << ag[i] << " ";
        std::cout << std::endl;    
        me.print();
        double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::victor : " << time << " us" << std::endl;
        start = clock();
        me.sort_Ford_Johnson_deque(ag);
        end = clock();
        time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << time << " us" << std::endl;
        return 0;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;}
}
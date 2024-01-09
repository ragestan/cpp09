#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    pair = 1;
}

PmergeMe::~PmergeMe()
{    
}

void PmergeMe::print()
{
    std::cout << "After : " ;
    for(size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}


void PmergeMe::check_argument_vector(char **ag)
{
    size_t x = 1;
    size_t y = 0;

    while(ag[x])
    {
        y = 0;
        while(isdigit(ag[x][y]))
            y++;
        if (ag[x][y] != '\0')
            throw std::out_of_range("Error");
        vec.push_back(atoi(ag[x]));   
        x++;
    }
}

void PmergeMe::pair_vector()
{
    size_t i = 0;

    while((i < vec.size() && vec.size()%2 == 0) || (i < vec.size() - 1 && vec.size()%2 == 1))
    {
        pairVector.push_back(std::make_pair(vec[i], vec[i + 1]));
        i += 2;
    }
    if (vec.size()%2 == 0)
        pair = 0;
}


void PmergeMe::Pairwise_comparison()
{
    for (size_t i = 0; i < pairVector.size(); ++i)
        if (pairVector[i].first < pairVector[i].second)
            std::swap(pairVector[i].first, pairVector[i].second);
}

void PmergeMe::RePairwise_comparison(int i)
{
    if (pairVector[i].first < pairVector[i].second)
        std::swap(pairVector[i].first, pairVector[i].second);    
}

void PmergeMe::Recursion(size_t o)
{
    if (o == pairVector.size() - 1)
        return;
    for (size_t i = o + 1; i < pairVector.size(); ++i)
    {
        if(pairVector[i].first < pairVector[o].first)
        {
            std::swap(pairVector[o].first, pairVector[i].first);
            RePairwise_comparison(o);
        }
    }
    Recursion(++o);
}

void PmergeMe::Insertion()
{
    int temp;

    if (pair == 1)
        temp = vec[vec.size() - 1];
    vec.clear();
    for (size_t i = 0; i < pairVector.size(); i++)
        vec.push_back(pairVector[i].first); 
    for (size_t i = 0; i < pairVector.size(); i++)
    {
        std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), pairVector[i].second);
        vec.insert(it, pairVector[i].second);
    }
    pairVector.clear();
    if (pair == 1)
    {
        std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), temp);
        vec.insert(it, temp);
    }
}

void PmergeMe::sort_Ford_Johnson_vector(char **ag)
{
    try {
        check_argument_vector(ag);
        pair_vector();
        Pairwise_comparison();
        Recursion(0);
        Insertion();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;}
}

void PmergeMe::check_argument_deque(char **ag)
{
    size_t x = 1;
    size_t y = 0;

    while(ag[x])
    {
        y = 0;
        while(isdigit(ag[x][y]))
            y++;
        if (ag[x][y] != '\0')
            throw std::out_of_range("Error");
        deq.push_back(atoi(ag[x]));   
        x++;
    }
}

void PmergeMe::pair_deque()
{
    size_t i = 0;
    if (deq.size()%2 == 0)
        pair = 0;
    while((i < deq.size() && deq.size()%2 == 0) || (i < deq.size() - 1 && deq.size()%2 == 1))
    {
        pairDeque.push_back(std::make_pair(deq[i], deq[i + 1]));
        i += 2;
    }
}

void PmergeMe::Pairwise_comparison_deque()
{
    for (size_t i = 0; i < pairDeque.size(); ++i)
        if (pairDeque[i].first < pairDeque[i].second)
            std::swap(pairDeque[i].first, pairDeque[i].second);   
}

void PmergeMe::RePairwise_comparison_deque(int i)
{
    if (pairDeque[i].first < pairDeque[i].second)
        std::swap(pairDeque[i].first, pairDeque[i].second);    
}

void PmergeMe::Recursion_deque(size_t o)
{
    if (o == pairDeque.size() - 1)
        return;
    for (size_t i = o + 1; i < pairDeque.size(); ++i)
    {
        if(pairDeque[i].first < pairDeque[o].first)
        {
            std::swap(pairDeque[o].first, pairDeque[i].first);
            RePairwise_comparison(o);
        }
    }
    Recursion_deque(++o);
}

void PmergeMe::Insertion_deque()
{
    int temp;

    if (pair == 1)
        temp = deq[deq.size() - 1];
    deq.clear();
    for (size_t i = 0; i < pairDeque.size(); i++)
        deq.push_back(pairDeque[i].first); 
    for (size_t i = 0; i < pairDeque.size(); i++)
    {
        std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), pairDeque[i].second);
        deq.insert(it, pairDeque[i].second);
    }
    pairDeque.clear();
    if (pair == 1)
    {
        std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), temp);
        deq.insert(it, temp);
    }
}

void PmergeMe::sort_Ford_Johnson_deque(char **ag)
{
    try {
        check_argument_deque(ag);
        pair_deque();
        Pairwise_comparison_deque();
        Recursion_deque(0);
        Insertion_deque();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;}
}
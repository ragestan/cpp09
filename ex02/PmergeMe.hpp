#pragma once
#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

class PmergeMe
{
    private:
        void check_argument_vector(char **ag);
        void check_argument_deque(char **ag);
        void pair_vector();
        void pair_deque();
        void Pairwise_comparison();
        void Pairwise_comparison_deque();
        void RePairwise_comparison(int);
        void RePairwise_comparison_deque(int);
        void Recursion(size_t);
        void Recursion_deque(size_t);
        void Insertion();
        void Insertion_deque();
        int pair;
        std::deque<int> deq;
        std::deque<std::pair<int, int> > pairDeque;
        std::vector<int> vec;
        std::vector<std::pair<int, int> > pairVector;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        void sort_Ford_Johnson_vector(char **ag);
        void sort_Ford_Johnson_deque(char **ag);
        void print();
};
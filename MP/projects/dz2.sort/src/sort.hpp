#ifndef SORT_METHODS_HPP
#define SORT_METHODS_HPP

#include <vector>
#include <cmath>
#include <iostream>

namespace mik{
    void merge_sort(std::vector<int>& A, int p, int r);
    void merge(std::vector<int>& A, int p, int q, int r);

    void insertion_sort(std::vector<int>& array_to_sort, int begin, int end);
    void merge_sort_insertionMOD(std::vector<int>& array_to_sort, int begin, int end, int m);

    void bubble_sort(std::vector<int>& arr);

    void print_array(const char* const comment, int* arr, const int size);
}

#endif

#include "sort.hpp"
#include <iostream>

void mik::merge_sort(std::vector<int>& A, int p, int r){
    if (p<r){
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

void mik::merge(std::vector<int>& A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> sub_array1(begin(A)+p, begin(A)+p+n1);
    std::vector<int> sub_array2(begin(A)+p+n1, begin(A)+p+n1+n2);
    
    sub_array1.push_back(pow(10, 9));
    sub_array2.push_back(pow(10, 9));
    int i = 0, j = 0;
    for (int k = p; k<r+1; k++){
        if (sub_array1[i] < sub_array2[j]){
            A[k] = sub_array1[i++];
        }
        else{
            A[k] = sub_array2[j++];
        }
    }
}

void mik::insertion_sort(std::vector<int> &array_to_sort, int begin, int end){
    for (int i = begin+1; i <= end; i++){
        int j = i;
        int temp = array_to_sort[i];
        while (j > begin && temp < array_to_sort[j-1]){
            array_to_sort[j] = array_to_sort[j-1];
            j--;
        }
        array_to_sort[j] = temp;
    }
}

void mik::merge_sort_insertionMOD(std::vector<int>& A, int p, int r, int m){
    if (p<r && r-p > m){
        int q = (p + r) / 2;
        merge_sort_insertionMOD(A, p, q, m);
        merge_sort_insertionMOD(A, q+1, r, m);
        merge(A, p, q, r);
    }else{
        
        insertion_sort(A, p, r);
    }
}

void mik::bubble_sort(std::vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
            }
        }
    }
}

void mik::print_array(const char* const comment, int* arr, const int size) {
    const char format = ' ';
    std::cout << comment;
    for (int i = 0; i < size; i++) {
        std::cout << format << arr[i];
    }
    std::cout << std::endl;
}


#include "sort.hpp"

int main() {
    std::vector<int> arr_vector = {1, 2, 4, 9, 3, 12};
    
    const int arr_size = arr_vector.size();

    mik::print_array("Массив до сортировки:", arr_vector.data(), arr_size);
    
    mik::merge_sort(arr_vector, 0, arr_size - 1);

    mik::print_array("Массив после сортировки:", arr_vector.data(), arr_size);

    return 0;
}

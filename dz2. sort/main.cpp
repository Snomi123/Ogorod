#include "io.hpp"
#include "sort.hpp"

int main() {
    int arr[] = {1, 2, 4, 9, 3, 12};
	const int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	print_array("Массив до сортировки:", arr, arr_size);
    
    sortings::bubble_sort(arr, arr_size);

    print_array("Массив после сортировки:", arr, arr_size);

    return 0;
}

#include <cmath>
#include <iostream>

void print_array(const char* const comment, int* arr, const int size);

int main() {
    int arr_size = 20;
    int* arr = new int[arr_size];
    
    for (int i = 0; i < arr_size; i++){
        arr[i] = rand() % 20;
    }
    
    print_array("Был сгенерирован массив:",arr, arr_size);
    
    for (int i = 0; i < (arr_size/2); i++){
        std::swap(arr[i], arr[19 - i]);
    }

    print_array("Массив после обработки:", arr, arr_size);
    
    return 0;
}

void print_array(const char* const comment, int* arr, const int size) {
    const char space = ' ';
    std::cout << comment;
    for (int i = 0; i < size; i++) {
        std::cout << space << arr[i];
    }
    std::cout << std::endl;
}


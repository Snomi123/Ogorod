#include "vector.hpp"
#include <iostream>
#include <algorithm>

using biv::Vector;

template<typename T>
Vector<T>::Vector() {
    arr = new T[START_CAPACITY]; // Выделяем память под начальную ёмкость
}

template<typename T>
Vector<T>::~Vector() {
    delete[] arr; // Освобождаем память
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
    return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
    for (std::size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
    if (position > size) {
        return false;
    }

    // Увеличиваем ёмкость, если массив заполнен
    if (size == capacity) {
        capacity *= 2;
        T* new_arr = new T[capacity];
        std::copy(arr, arr + size, new_arr);
        delete[] arr;
        arr = new_arr;
    }

    // Сдвигаем элементы вправо
    for (std::size_t i = size; i > position; --i) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value; // Вставляем элемент
    ++size;
    return true;
}

template<typename T>
void Vector<T>::print() const noexcept {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) { // Увеличиваем ёмкость
        capacity *= 2;
        T* new_arr = new T[capacity];
        std::copy(arr, arr + size, new_arr);
        delete[] arr;
        arr = new_arr;
    }
    arr[size++] = value; // Добавляем элемент в конец
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {
    for (std::size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            // Сдвигаем элементы влево
            for (std::size_t j = i; j < size - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            --size;
            return true;
        }
    }
    return false; // Элемент не найден
}

template class biv::Vector<int>;

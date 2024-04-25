#include "vector.hpp"

using GGolub::Vector;

template <typename T>
Vector<T>::Vector() noexcept {
    _size = 0;
    capacity = 10;
}

template <typename T>
Vector<T>::~Vector() noexcept {
    delete[] arr;
}

template <typename T>
void Vector<T>::push_back(const T &value) noexcept {
    if(_size == 0){
        arr = new T[capacity];
        arr[_size++] = value;
    }
    else if(_size % capacity == 0){
        T* arr1 = new T[_size + capacity];
        for(int i = 0; i < _size; i++){
            arr1[i] = arr[i];
        }
        arr1[_size++] = value;
        arr = arr1;
        arr1 = nullptr;
    }
    else{
        arr[_size++] = value;
    }
}

template <typename T>
void Vector<T>::print() const noexcept {
    for(int i = 0; i < _size; i++)
        std::cout << arr[i] << " ";
}

template <typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
    for (int i = 0; i < _size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool Vector<T>::insert(const int position, const T& value) {
    if (_size == 0) {this->push_back(value); return 1;}
    if (_size < position ||  position < 0) { return 0;}

    _size++;
    T* arr1 = new T[_size];
    for(int i = 0; i < position; i++){
        arr1[i] = arr[i];
    }
    arr1[position] = value;
    for(int i = position + 1; i < _size; i++){
        arr1[i] = arr[i-1];
    }
    arr = arr1;
    arr1 = nullptr;
    return 1;
}

template <typename T>
bool Vector<T>::remove_first(const T& value) noexcept {
    for (int i = 0; i < _size; i++) {
        if (arr[i] == value) {
            T* arr1 = new T[_size - 1];
            for(int j = 0; j < i; j++){
                arr1[j] = arr[j];
            }
            for(int j = i + 1; j <= _size; j++){
                arr1[j] = arr[j];
            }
            arr = arr1;
            arr1 = nullptr;
            return 1;
        }
    }
    return 0;
}

template <typename T>
std::size_t Vector<T>::size() const noexcept {
    return _size;
}

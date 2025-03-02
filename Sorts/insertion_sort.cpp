#include <iostream>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int *arr, const size_t size){
    if (size <= 1){
        return;
    }

    for(size_t i = 1; i < size; ++i){
        size_t j = i - 1;
        while (arr[j + 1] < arr[j] && j >=0){
            swap(arr[j + 1], arr[j]);
            --j;
        }
    }
}
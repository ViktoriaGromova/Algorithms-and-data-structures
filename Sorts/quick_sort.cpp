#include <iostream>
#include <random>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

std::pair<size_t, size_t> partition(int *arr, const size_t size, const int pivot)
{
    size_t i = 0;
    for (size_t j = 0; j < size; ++j)
    {
        if(arr[j] < pivot){
            swap(arr[j], arr[i]);
            ++i;
        }
    }

    size_t k = i, n = i;
    while(n < size){
        if(arr[n] == pivot && arr[k] != pivot){
            swap(arr[k], arr[n]);
            ++k;
        }
        ++n;
    }
    return {i, k};
}

void quickSort(int *arr, const size_t size)
{
    if (size <= 1)
    {
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);

    int pivot = arr[dis(gen)];

    std::pair<size_t, size_t> indices = partition(arr, size, pivot);
    size_t i = indices.first;
    size_t j = indices.second;
    quickSort(arr, i);
    quickSort(arr + j, size - j);
}
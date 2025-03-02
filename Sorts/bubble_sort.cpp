#include <iostream>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *arr, const size_t size)
{
    if (size <= 1)
    {
        return;
    }

    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
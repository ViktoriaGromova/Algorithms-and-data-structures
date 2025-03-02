#include <iostream>
#include <cstring>

void Merge(int *left_arr, const size_t size_left_arr, int *right_arr, const size_t size_right_arr, int *arr)
{
    size_t i = 0, j = 0;
    while (i < size_left_arr || j < size_right_arr)
    {
        if ((j == size_right_arr) || (i < size_left_arr && left_arr[i] <= right_arr[j]))
        {
            arr[i + j] = left_arr[i];
            ++i;
        }
        else
        {
            arr[i + j] = right_arr[j];
            ++j;
        }
    }
}

void mergeSort(int *arr, const size_t size)
{
    if (size <= 1)
    {
        return;
    }

    const size_t mid = size / 2;
    int *left = new int[mid];
    int *right = new int[size - mid];

    std::memcpy(left, arr, mid * sizeof(int));
    std::memcpy(right, arr + mid, (size - mid) * sizeof(int));

    mergeSort(left, mid);
    mergeSort(right, size - mid);

    Merge(left, mid, right, size - mid, arr);

    delete[] left;
    delete[] right;
}
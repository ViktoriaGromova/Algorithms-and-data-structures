#include <iostream>
#include <cstring>

int min(int *arr, const size_t size)
{
    int minValue = arr[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (minValue > arr[i])
        {
            minValue = arr[i];
        }
    }
    return minValue;
}

int max(int *arr, const size_t size)
{
    int maxValue = arr[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (maxValue < arr[i])
        {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

void fillArrZero(int *arr, const size_t size){
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = 0;
    }
}

void countingSort(int *arr, const size_t size)
{
    if (size <= 1)
    {
        return;
    }

    const int minValue = min(arr, size);
    const int maxValue = max(arr, size);

    const int countingArrSize = maxValue - minValue + 1;

    int *countingArr = new int[countingArrSize];

    fillArrZero(countingArr, countingArrSize);

    for (size_t i = 0; i < size; ++i)
    {
        ++countingArr[arr[i] - minValue];
    }

    int j = 0;
    for (size_t i = 0; i < countingArrSize; ++i)
    {
        for (int count = 0; count < countingArr[i]; ++count) {
            arr[j] = i + minValue;
            ++j;
        }
    }
}
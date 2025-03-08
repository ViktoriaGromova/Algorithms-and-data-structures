#include <iostream>
#include <ctime>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *arr, const size_t size) // To find the median
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

int findMedian(int *arr, int tileSize)
{
    if (tileSize % 2 == 0)
    {
        return arr[tileSize / 2];
    }
    return arr[tileSize / 2 - 1];
}

int searchMedian(int *arr, const size_t size) // тут надо скопировать массив, а не передавать по указателю.
{
    const size_t range = 5;
    const size_t count = size / range;

    int *medians = new int[count + 1];

    for (size_t i = 0; i < count; ++i)
    {
        bubbleSort(arr + range * i, range);
        medians[i] = arr[2 + i * 5];
    }

    size_t tileSize = size - count * range;
    if (tileSize)
    {
        bubbleSort(arr + range * count, tileSize);
        medians[count] = findMedian(arr + range * count, tileSize);
    }
    bubbleSort(medians, count + 1);
    int median_elen = findMedian(medians, count + 1);
    delete[] medians;
    return median_elen;
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

void derandomizedQuickSort(int *arr, const size_t size)
{
    if (size <= 1)
    {
        return;
    }

    int pivot = searchMedian(arr, size);

    std::pair<size_t, size_t> indices = partition(arr, size, pivot);
    size_t i = indices.first;
    size_t j = indices.second;
    derandomizedQuickSort(arr, i);
    derandomizedQuickSort(arr + j, size - j);
}

int main()
{
    srand(time(0));
    const size_t size = 5;
    int staticArr[] = {1, 8, 3, 5, 9};
    int *arr = new int[size];

    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = 1 + rand() % 100;
    }

    std::cout << "Before sort: [ ";
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;

    derandomizedQuickSort(arr, size);
    std::cout << "After sort: [ ";
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;

    delete[] arr;
    return 0;
}
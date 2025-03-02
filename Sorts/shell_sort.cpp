#include <iostream>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int interval(int *arr, const size_t size)
{
    int c2;
    int i = 0;
    do
    {
        if (i % 2)
        {
            int c1 = std::pow(2, i / 2);
            arr[i] = 9 * c1 * (c1 - 1) + 1;
        }
        else
        {
            int c2 = std::pow(2, i / 2);
            arr[i] = c2 * (8 * c2 - 6 * 1.41421) + 1;
        }
        ++i;
    } while (3 * arr[i] > size);
    return i;
}

void shellSort(int *arr, const size_t size){
    if (size <= 1){
        return;
    }

    const size_t inc_size = 30;
    int* inc = new int[inc_size]; 
    size_t size_inc = interval(inc, size);

    for(size_t i = 1; i < size && size_inc >=0; ++i){
        int coef_inc = inc[--size_inc];
        
        size_t j = i - 1;
        while (arr[j + 1] < arr[j] && j >=0){
            swap(arr[j + 1], arr[j]);
            --j;
        }
    }
}
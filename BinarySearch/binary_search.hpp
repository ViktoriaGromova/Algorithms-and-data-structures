#include <iostream>

void binarySearch(int *arr, const size_t size, int target)
{
    size_t left = 0;
    size_t right = size - 1;

    while (left <= right)
    {
        size_t mid = (left + right) / 2;

        if (*(arr + mid) > target)
        {
            right = mid - 1;
        }
        else
        {
            if (*(arr + mid) < target)
            { 
                left = mid + 1;
            }
            else
            {
                std::cout << "Find\n";
                return;
            }
        }
    }
    std::cout << "Not Find\n";
}
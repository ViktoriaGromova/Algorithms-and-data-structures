#include <iostream>
#include <ctime>

void  Partition(){
    
}


void quickSort(int *arr, const size_t size){
    if (size <= 1){
        return;
    }

    int x = arr[rand() % (size - 1)];

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

    quickSort(arr, size);
    std::cout << "After sort: [ ";
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;

    delete[] arr;
    return 0;
}
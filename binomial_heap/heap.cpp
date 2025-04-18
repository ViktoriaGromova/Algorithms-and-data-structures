#include <stdexcept>

#include "heap.hpp"

void BinomialHeap::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BinomialHeap::copy(int *array, int *newArray, const size_t newSize)
{
    for (int i = 0; i < newSize; ++i)
    {
        newArray[i] = array[i];
    }
}

BinomialHeap::BinomialHeap(const int value) : size(1)
{
    arr = new int[size];
    arr[0] = value;
}

void BinomialHeap::siftUp(const size_t index)
{
    if (!index)
    {
        return;
    }

    const size_t parentIndex = (index - 1) / 2;

    if (arr[parentIndex] > arr[index])
    {
        swap(arr[parentIndex], arr[index]);
        siftUp(parentIndex);
    }
}

void BinomialHeap::siftDown(const size_t index)
{
    if (2 * index > size - 2)
    {
        return;
    }

    size_t childIndex = 2 * index + 1;

    if (childIndex + 1 < size - 1 && arr[childIndex] > arr[childIndex + 1])
    {
        ++childIndex;
    }

    if (arr[childIndex] < arr[index])
    {
        swap(arr[childIndex], arr[index]);
        siftDown(childIndex);
    }
}

int BinomialHeap::getMin() const
{
        if (arr != nullptr)
        return arr[0];
}

void BinomialHeap::insert(const int value)
{
    int *newArr = new int[size + 1];
    copy(arr, newArr, size);

    delete[] arr;

    arr = newArr;
    newArr[size++] = value;

    siftUp(size - 1);
}

void BinomialHeap::extractMin()
{
    swap(arr[0], arr[size - 1]);
    --size;
    siftDown(0);
}

void BinomialHeap::decreaseKey(int index, const int delta)
{
    if (delta < 0)
    {
        throw std::invalid_argument("Delta must be non-negative.");
    }

    arr[index] -= delta;
    siftUp(index);
}

BinomialHeap::~BinomialHeap()
{
    delete[] arr;
}
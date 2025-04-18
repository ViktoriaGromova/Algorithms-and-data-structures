#include "vector.hpp"

#include <cstring>

template <typename T>
Vector<T>::Vector(const size_t size, const T value) : size(size), capacity(size > 0 ? 2 * size : 1), data(new T[capacity])
{
    memset(data, value, size * sizeof(int));
}

template <typename T>
void Vector<T>::resize(const size_t newSize) // O*(capacity)
{
    capacity = newSize;
    T *tempData = new T[capacity];
    memcpy(tempData, data, size * sizeof(int));
    delete[] data;
    data = tempData;
}

template <typename T>
void Vector<T>::push_back(const T &value) // O*(1)
{
    if (size >= capacity)
    {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template <typename T>
void Vector<T>::pop_back() // O*(1)
{
    if (size = 0)
    {
        throw std::out_of_range("Cannot pop from an empty Vector.");
    }
    --size;
    if (size < capacity / 4)
    {
        resize(capacity / 2);
    }
}

template <typename T>
size_t Vector<T>::get_size()
{
    return size;
}

template <typename T>
T &Vector<T>::operator[](const size_t i) // O*(1)
{
    if (i >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}
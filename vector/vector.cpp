#include "vector.hpp"

#include <cstring>

Vector::Vector(const size_t size, const int value = 0) : size(size), capacity(size > 0 ? 2 * size : 1), data(new int[capacity])
{
    memset(data, value, size * sizeof(int));
}

Vector::~Vector()
{
    delete[] data;
}
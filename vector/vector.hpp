#include <iostream>

template <typename T>
class Vector
{
public:
    Vector() : capacity(0), size(0), data(nullptr) {}
    Vector(const size_t size, const T value);
    void push_back(const T& value);
    void pop_back();
    size_t get_size();
    T& operator[](const size_t i);
    ~Vector();

private:
    void resize(const size_t newSize);

    size_t capacity;
    size_t size;
    T *data;
};
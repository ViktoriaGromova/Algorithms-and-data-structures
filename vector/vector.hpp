#include <iostream>

class Vector
{
public:
    Vector() : capacity(0), size(0), data(nullptr) {}
    Vector(const size_t size, const int value = 0);

    ~Vector();
private:
    void resize();

    size_t capacity;
    size_t size;
    int *data;
};
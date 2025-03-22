#include <iostream>

class BinomialHeap
{
private:
    size_t size;
    int *arr;

    void siftUp(const size_t index);
    void siftDown(const size_t index);
    void swap(int &a, int &b);
    void copy(int *a, int *b, const size_t newSize);

public:
    BinomialHeap(const int value);
    void insert(const int value);
    int getMin() const;
    void extractMin();
    void decreaseKey(int index, const int delta); //*a - delta
    ~BinomialHeap();
};
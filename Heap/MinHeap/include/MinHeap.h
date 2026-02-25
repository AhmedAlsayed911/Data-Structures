#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>

class MinHeap
{
private:
    std::vector<int> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);

public:
    MinHeap();

    void insert(int value);
    int extractMin();
    int peek();
    bool isEmpty();
    int getSize();
    void display();
};

#endif

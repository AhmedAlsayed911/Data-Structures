#include "../include/MinHeap.h"
#include <iostream>
#include <stdexcept>

MinHeap::MinHeap() {}

int MinHeap::parent(int i) { return (i - 1) / 2; }
int MinHeap::leftChild(int i) { return 2 * i + 1; }
int MinHeap::rightChild(int i) { return 2 * i + 2; }

void MinHeap::heapifyUp(int index)
{
    while (index > 0 && heap[parent(index)] > heap[index])
    {
        std::swap(heap[parent(index)], heap[index]);
        index = parent(index);
    }
}

void MinHeap::heapifyDown(int index)
{
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);
    int n = heap.size();

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index)
    {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void MinHeap::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int MinHeap::extractMin()
{
    if (isEmpty())
        throw std::underflow_error("Heap is empty");

    int minVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    if (!isEmpty())
        heapifyDown(0);

    return minVal;
}

int MinHeap::peek()
{
    if (isEmpty())
        throw std::underflow_error("Heap is empty");
    return heap[0];
}

bool MinHeap::isEmpty()
{
    return heap.empty();
}

int MinHeap::getSize()
{
    return heap.size();
}

void MinHeap::display()
{
    for (int val : heap)
        std::cout << val << " ";
    std::cout << std::endl;
}

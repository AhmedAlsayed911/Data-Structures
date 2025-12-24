#include "../include/Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size)
{
    capacity = size;
    arr = new int[capacity];
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue()
{
    delete[] arr;
}

void Queue::enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue is full!" << endl;
        return;
    }
    
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    count++;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        return -1;
    }
    
    int value = arr[front];
    front = (front + 1) % capacity;
    count--;
    return value;
}

int Queue::peek()
{
    if (isEmpty())
    {
        return -1;
    }
    return arr[front];
}

bool Queue::isEmpty()
{
    return count == 0;
}

bool Queue::isFull()
{
    return count == capacity;
}

int Queue::getSize()
{
    return count;
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    
    int index = front;
    for (int i = 0; i < count; i++)
    {
        cout << arr[index] << " ";
        index = (index + 1) % capacity;
    }
    cout << endl;
}

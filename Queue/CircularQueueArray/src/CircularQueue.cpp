#include "../headers/CircularQueue.h"
#include <iostream>
using namespace std;

CircularQueue::CircularQueue(int s)
{
    length = s;
    arr = new int[length];
    front = 0;
    rear = -1;
    count = 0;
}

CircularQueue::~CircularQueue()
{
    delete[] arr;
}

void CircularQueue::enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue is full! Cannot enqueue " << value << endl;
        return;
    }

    rear = (rear + 1) % length;
    arr[rear] = value;
    count++;
}

int CircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty!!"<< endl;
        return -1;
    }

    int value = arr[front];
    front = (front + 1) % length;
    count--;
    cout << "Dequeued: " << value << endl;
    return value;
}

int CircularQueue::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return arr[front];
}

bool CircularQueue::isEmpty()
{
    return count == 0;
}

bool CircularQueue::isFull()
{
    return count == length;
}

int CircularQueue::size()
{
    return count;
}

void CircularQueue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = 0; i < count; i++)
    {
        int index = (front + i) % length;
        cout << arr[index] << " ";
    }
    cout << endl;
    cout << "Front: " << front << ", Rear: " << rear << ", Size: " << count << "/" << length << endl;
}
#include "../include/Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size)
{
    capacity = size;
    arr = new int[capacity];
    top = -1;
}

Stack::~Stack()
{
    delete[] arr;
}

void Stack::push(int value)
{
    if (isFull())
    {
        cout << "Stack overflow!" << endl;
        return;
    }
    arr[++top] = value;
}

int Stack::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    return arr[top--];
}

int Stack::peek()
{
    if (isEmpty())
    {
        return -1;
    }
    return arr[top];
}

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == capacity - 1;
}

int Stack::getSize()
{
    return top + 1;
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

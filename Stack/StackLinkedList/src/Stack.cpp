#include "../include/Stack.h"
#include <iostream>
using namespace std;

Node::Node(int d)
{
    data = d;
    next = NULL;
}

Stack::Stack()
{
    top = NULL;
    size = 0;
}

void Stack::push(int value)
{
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    size++;
}

int Stack::pop()
{
    if (isEmpty())
    {
        return -1;
    }

    Node *temp = top;
    int poppedValue = top->data;
    top = top->next;
    delete temp;
    size--;
    return poppedValue;
}

int Stack::peek()
{
    if (isEmpty())
    {
        return -1;
    }
    return top->data;
}

bool Stack::isEmpty()
{
    return top == NULL;
}

int Stack::getSize()
{
    return size;
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    Node *current = top;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}


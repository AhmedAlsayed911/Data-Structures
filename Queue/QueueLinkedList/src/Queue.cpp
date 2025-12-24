#include "../include/Queue.h"
#include <iostream>

using namespace std;

Node::Node(int d)
{
    data = d;
    next = NULL;
}

Queue::Queue()
{
    front = NULL;
    rear = NULL;
    size = 0;
}

void Queue::enqueue(int d)
{
    Node* newNode = new Node(d);
    
    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        return -1;
    }
    
    Node* temp = front;
    int value = front->data;
    front = front->next;
    
    if (front == NULL)
    {
        rear = NULL;
    }
    
    delete temp;
    size--;
    return value;
}

bool Queue::isEmpty()
{
    return front == NULL;
}

void Queue::display()
{
    if(isEmpty())
        {cout<<"Queue is Empty!!"; return;}

        Node* temp = front;
    while (temp != NULL)
    {
        cout<<temp ->data<<endl;
        temp = temp ->next;
    }
}
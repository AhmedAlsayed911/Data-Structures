#ifndef QUEUE_H
#define QUEUE_H

struct Node
{
    int data;
    Node *next;

    Node(int d);
};

class Queue
{
private:
    int size;
    Node* rear;
    Node* front;

public:
    Queue();

    void enqueue(int d);
    int dequeue();
    bool isEmpty();
    void display();
};

#endif
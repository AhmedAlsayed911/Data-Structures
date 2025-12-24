#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size = 100);
    ~Queue();
    
    void enqueue(int value);
    int dequeue();
    int peek();
    
    bool isEmpty();
    bool isFull();
    int getSize();
    
    void display();
};

#endif

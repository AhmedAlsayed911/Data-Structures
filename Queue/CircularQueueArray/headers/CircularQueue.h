#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int length;
    int count;

public:
    CircularQueue(int s);
    ~CircularQueue();
    
    void enqueue(int value);
    int dequeue();
    int peek();
    
    bool isEmpty();
    bool isFull();
    int size();
    
    void display();
};

#endif
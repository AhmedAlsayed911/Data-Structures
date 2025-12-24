#ifndef STACK_H
#define STACK_H

struct Node
{
    int data;
    Node* next;

    Node(int d);
};

class Stack
{

private:
    Node *top;
    int size;

public:
    Stack();
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
    int getSize();
    void display();
    ~Stack();
};

#endif

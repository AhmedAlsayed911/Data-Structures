#include <iostream>
#include "../include/Queue.h"
using namespace std;

int main()
{
    Queue q(5);
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    cout << "Queue contents: ";
    q.display();
    
    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.getSize() << endl;
    
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    
    cout << "Queue contents after dequeuing: ";
    q.display();
    
    q.enqueue(60);
    q.enqueue(70);
    
    cout << "Queue contents after enqueuing: ";
    q.display();
    
    return 0;
}

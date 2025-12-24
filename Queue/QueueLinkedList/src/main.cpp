#include "../include/Queue.h"
#include <iostream>

using namespace std;

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.enqueue(30);

    q.display();
//    q.enqueue(30);
//    q.enqueue(40);


//    cout << "Dequeued: " << q.dequeue() << endl;
//    cout << "Dequeued: " << q.dequeue() << endl;
//
//
//    q.enqueue(50);
//
//
//    cout << "Dequeued: " << q.dequeue() << endl;
//    cout << "Dequeued: " << q.dequeue() << endl;
//    cout << "Dequeued: " << q.dequeue() << endl;


//    q.dequeue();

    return 0;
}

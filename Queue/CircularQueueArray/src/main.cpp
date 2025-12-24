#include "../headers/CircularQueue.h"
#include <iostream>
using namespace std;

int main() {
  
    CircularQueue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.display();
    
    cout << endl;
    
    queue.enqueue(60);
    
    cout << endl;
    

    queue.dequeue();
    queue.dequeue();
    queue.display();
    
    cout << endl;
    
    queue.enqueue(60);
    queue.enqueue(70);
    queue.display();
    
    cout << endl;
    
    queue.display();
    
    cout << endl;
    

    while (!queue.isEmpty()) {
        queue.dequeue();
    }
    
    cout << endl;
    
   
    queue.dequeue();
    
    return 0;
}
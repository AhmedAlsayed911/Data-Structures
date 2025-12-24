#include <iostream>
#include "../include/Stack.h"
using namespace std;

int main()
{
    Stack s(5);
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    cout << "Stack contents: ";
    s.display();
    
    cout << "Top element: " << s.peek() << endl;
    cout << "Stack size: " << s.getSize() << endl;
    
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    
    cout << "Stack contents after popping: ";
    s.display();
    
    return 0;
}

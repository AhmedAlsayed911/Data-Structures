#include <iostream>
#include "../include/Stack.h"
using namespace std;

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "\nStack size: " << stack.getSize() << endl;
    stack.display();

    cout << "\nTop element: " << stack.peek() << endl;

    cout << endl;
    stack.pop();
    stack.pop();

    cout << "\nAfter popping:" << endl;
    stack.display();
    cout << "Stack size: " << stack.getSize() << endl;

    cout << "\nTop element: " << stack.peek() << endl;

    return 0;
}

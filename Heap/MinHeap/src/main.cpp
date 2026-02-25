#include <iostream>
#include "../include/MinHeap.h"

int main()
{
    MinHeap h;

    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(1);
    h.insert(7);

    std::cout << "Heap: ";
    h.display();

    std::cout << "Min: " << h.peek() << std::endl;

    std::cout << "Extract Min: " << h.extractMin() << std::endl;
    std::cout << "Heap after extract: ";
    h.display();

    std::cout << "Size: " << h.getSize() << std::endl;

    return 0;
}

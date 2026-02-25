#include <iostream>
#include "../include/HashTable.h"

int main()
{
    HashTable ht(7);

    ht.insert(1, "Alice");
    ht.insert(2, "Bob");
    ht.insert(8, "Charlie");
    ht.insert(15, "Dave");
    ht.insert(3, "Eve");

    std::cout << "Hash Table:" << std::endl;
    ht.display();

    std::string val;
    if (ht.search(8, val))
        std::cout << "Found key 8: " << val << std::endl;
    else
        std::cout << "Key 8 not found" << std::endl;

    ht.remove(8);
    std::cout << "After removing key 8:" << std::endl;
    ht.display();

    std::cout << "Size: " << ht.getSize() << std::endl;
    std::cout << "Load Factor: " << ht.loadFactor() << std::endl;

    return 0;
}

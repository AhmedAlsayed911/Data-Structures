#include <iostream>
#include "../include/AVLTree.h"

int main()
{
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    std::cout << "Inorder: ";
    tree.inorder();

    std::cout << "Preorder: ";
    tree.preorder();

    std::cout << "Search 25: " << (tree.search(25) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 99: " << (tree.search(99) ? "Found" : "Not Found") << std::endl;

    tree.remove(30);
    std::cout << "After removing 30 - Inorder: ";
    tree.inorder();

    return 0;
}

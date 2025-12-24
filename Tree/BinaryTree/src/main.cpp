#include <iostream>
#include "../headers/BinaryTree.h"
using namespace std;

int main()
{
    BinaryTree tree;

    tree.insertRecursive(50);
    tree.insertRecursive(30);
    tree.insertRecursive(70);
    tree.insertRecursive(20);
    tree.insertRecursive(40);
    tree.insertRecursive(60);
    tree.insertRecursive(80);

    tree.inorder();
    tree.preorder();
    tree.postorder();

    int searchValue = 40;

    if (tree.search(searchValue))
        cout << "Found!" << endl;

    else
        cout << "Not found!" << endl;

    searchValue = 100;

    if (tree.search(searchValue))
        cout << "Found!" << endl;

    else
        cout << "Not found!" << endl;


    int value = 40;
    Node *parent = tree.findParent(value);
    if (parent != nullptr)
        cout << "Parent of " << value << " is: " << parent->data << endl;

    else
        cout << "Node " << value << " has no parent (root or not found)" << endl;


    value = 50;
    parent = tree.findParent(value);
    if (parent != nullptr)
        cout << "Parent of " << value << " is: " << parent->data << endl;

    else
        cout << "Node " << value << " has no parent (root or not found)" << endl;


    tree.insertLoop(25);
    tree.insertLoop(75);
    tree.inorder();

    tree.deleteValue(20);
    tree.inorder();

    tree.deleteValue(30);
    tree.inorder();

    tree.deleteValue(50);
    tree.inorder();

    return 0;
}

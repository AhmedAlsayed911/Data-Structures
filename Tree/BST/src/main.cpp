#include <iostream>
#include "../headers/BST.h"
using namespace std;

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.display();

    if (tree.find(40))
        cout << "Found 40" << endl;
    else
        cout << "Not found" << endl;

    tree.remove(20);
    tree.display();

    tree.remove(30);
    tree.display();

    tree.remove(50);
    tree.display();

    return 0;
}

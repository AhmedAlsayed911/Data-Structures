#include <iostream>
#include "../headers/Tree.h"
using namespace std;

int main()
{
    Tree tree(1);

    tree.addChild(1, 2);
    tree.addChild(1, 3);
    tree.addChild(1, 4);

    tree.addChild(2, 5);
    tree.addChild(2, 6);

    tree.addChild(3, 7);

    tree.addChild(4, 8);
    tree.addChild(4, 9);
    tree.addChild(4, 10);

    tree.display();

    cout << "Node 1 has " << tree.countChildren(1) << " children" << endl;
    cout << "Node 4 has " << tree.countChildren(4) << " children" << endl;

    return 0;
}

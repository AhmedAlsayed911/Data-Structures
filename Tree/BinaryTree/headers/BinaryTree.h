#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

struct Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
private:
    Node *root;

    Node *insertRecursive(Node *node, int value);
    void inorderTraversal(Node *node);
    void preorderTraversal(Node *node);
    void postorderTraversal(Node *node);
    Node *searchNode(Node *node, int value);
    Node *findMin(Node *node);
    Node *deleteNode(Node *node, int value);

public:
    BinaryTree();
    ~BinaryTree();

    void insertLoop(int value);
    void insertRecursive(int value);
    Node *findParent(int value);
    void inorder();
    void preorder();
    void postorder();
    bool search(int value);
    void deleteValue(int value);
    Node *getRoot() { return root; }

    void destroyTree(Node *node);
};

#endif

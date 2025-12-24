#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

class Node
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

class BST
{
private:
    Node *root;

    Node *insertNode(Node *node, int value);
    void inorder(Node *node);
    Node *search(Node *node, int value);
    Node *deleteNode(Node *node, int value);
    Node *findMin(Node *node);

public:
    BST();
    ~BST();

    void insert(int value);
    void display();
    bool find(int value);
    void remove(int value);
    void destroy(Node *node);
};

#endif

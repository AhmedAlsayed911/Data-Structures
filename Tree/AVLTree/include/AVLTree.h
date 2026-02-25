#ifndef AVLTREE_H
#define AVLTREE_H

struct AVLNode
{
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int val);
};

class AVLTree
{
private:
    AVLNode* root;

    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    void updateHeight(AVLNode* node);

    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* balance(AVLNode* node);

    AVLNode* insert(AVLNode* node, int value);
    AVLNode* remove(AVLNode* node, int value);
    AVLNode* minNode(AVLNode* node);

    void inorder(AVLNode* node);
    void preorder(AVLNode* node);
    void clear(AVLNode* node);

public:
    AVLTree();
    ~AVLTree();

    void insert(int value);
    void remove(int value);
    bool search(int value);

    void inorder();
    void preorder();
};

#endif

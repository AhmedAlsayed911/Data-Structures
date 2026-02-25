#include "../include/AVLTree.h"
#include <iostream>
#include <algorithm>

AVLNode::AVLNode(int val) : data(val), height(1), left(nullptr), right(nullptr) {}

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree()
{
    clear(root);
}

void AVLTree::clear(AVLNode* node)
{
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

int AVLTree::height(AVLNode* node)
{
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(AVLNode* node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

void AVLTree::updateHeight(AVLNode* node)
{
    if (node)
        node->height = 1 + std::max(height(node->left), height(node->right));
}

AVLNode* AVLTree::rotateRight(AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

AVLNode* AVLTree::balance(AVLNode* node)
{
    updateHeight(node);
    int bf = balanceFactor(node);

    if (bf > 1)
    {
        if (balanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (bf < -1)
    {
        if (balanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

AVLNode* AVLTree::insert(AVLNode* node, int value)
{
    if (!node) return new AVLNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    return balance(node);
}

AVLNode* AVLTree::minNode(AVLNode* node)
{
    while (node->left)
        node = node->left;
    return node;
}

AVLNode* AVLTree::remove(AVLNode* node, int value)
{
    if (!node) return nullptr;

    if (value < node->data)
        node->left = remove(node->left, value);
    else if (value > node->data)
        node->right = remove(node->right, value);
    else
    {
        if (!node->left || !node->right)
        {
            AVLNode* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }
        AVLNode* temp = minNode(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }

    return balance(node);
}

void AVLTree::insert(int value)
{
    root = insert(root, value);
}

void AVLTree::remove(int value)
{
    root = remove(root, value);
}

bool AVLTree::search(int value)
{
    AVLNode* curr = root;
    while (curr)
    {
        if (value == curr->data) return true;
        curr = value < curr->data ? curr->left : curr->right;
    }
    return false;
}

void AVLTree::inorder(AVLNode* node)
{
    if (!node) return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void AVLTree::preorder(AVLNode* node)
{
    if (!node) return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void AVLTree::inorder()
{
    inorder(root);
    std::cout << std::endl;
}

void AVLTree::preorder()
{
    preorder(root);
    std::cout << std::endl;
}

#include "../headers/BinaryTree.h"

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::~BinaryTree()
{
    destroyTree(root);
}

void BinaryTree::destroyTree(Node *node)
{
    if (node != NULL)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BinaryTree::insertLoop(int value)
{
    Node *newNode = new Node(value);

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    Node *current = root;
    Node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (value < current->data)
            current = current->left;

        else if (value > current->data)
            current = current->right;

        else
        {
            delete newNode;
            return;
        }
    }

    if (value < parent->data)
        parent->left = newNode;

    else
        parent->right = newNode;
}

void BinaryTree::insertRecursive(int value)
{
    root = insertRecursive(root, value);
}

Node *BinaryTree::insertRecursive(Node *node, int value)
{
    if (node == NULL)
        return new Node(value);

    if (value < node->data)
        node->left = insertRecursive(node->left, value);

    else if (value > node->data)
        node->right = insertRecursive(node->right, value);

    return node;
}

Node *BinaryTree::findParent(int value)
{
    if (root == NULL || root->data == value)
        return NULL;

    Node *current = root;
    Node *parent = NULL;

    while (current != NULL && current->data != value)
    {
        parent = current;

        if (value < current->data)
            current = current->left;

        else
            current = current->right;
    }

    if (current == NULL)
        return NULL;

    return parent;
}

void BinaryTree::inorder()
{
    cout << "Inorder: ";
    inorderTraversal(root);
    cout << endl;
}

void BinaryTree::inorderTraversal(Node *node)
{
    if (node != NULL)
    {
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

void BinaryTree::preorder()
{
    cout << "Preorder: ";
    preorderTraversal(root);
    cout << endl;
}

void BinaryTree::preorderTraversal(Node *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void BinaryTree::postorder()
{
    cout << "Postorder: ";
    postorderTraversal(root);
    cout << endl;
}

void BinaryTree::postorderTraversal(Node *node)
{
    if (node != NULL)
    {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
}

bool BinaryTree::search(int value)
{
    return searchNode(root, value) != NULL;
}

Node *BinaryTree::searchNode(Node *node, int value)
{
    if (node == NULL || node->data == value)
        return node;

    if (value < node->data)
        return searchNode(node->left, value);

    else
        return searchNode(node->right, value);
}

Node *BinaryTree::findMin(Node *node)
{
    while (node->left != NULL)
        node = node->left;

    return node;
}

void BinaryTree::deleteValue(int value)
{
    root = deleteNode(root, value);
}

Node *BinaryTree::deleteNode(Node *node, int value)
{
    if (node == NULL)
        return NULL;

    if (value < node->data)
        node->left = deleteNode(node->left, value);

    else if (value > node->data)
        node->right = deleteNode(node->right, value);

    else
    {
        if (node->left == NULL)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }

        Node *temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

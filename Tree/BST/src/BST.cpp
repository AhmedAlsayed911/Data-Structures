#include "../headers/BST.h"

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    destroy(root);
}

void BST::destroy(Node *node)
{
    if (node != NULL)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

Node *BST::insertNode(Node *node, int value)
{
    if (node == NULL)
        return new Node(value);

    if (value < node->data)
        node->left = insertNode(node->left, value);
    else if (value > node->data)
        node->right = insertNode(node->right, value);

    return node;
}

void BST::insert(int value)
{
    root = insertNode(root, value);
}

void BST::inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void BST::display()
{
    inorder(root);
    cout << endl;
}

Node *BST::search(Node *node, int value)
{
    if (node == NULL || node->data == value)
        return node;

    if (value < node->data)
        return search(node->left, value);

    return search(node->right, value);
}

bool BST::find(int value)
{
    return search(root, value) != NULL;
}

Node *BST::findMin(Node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node *BST::deleteNode(Node *node, int value)
{
    if (node == NULL)
        return node;

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

void BST::remove(int value)
{
    root = deleteNode(root, value);
}

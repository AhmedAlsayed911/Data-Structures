#include "../headers/Tree.h"

Tree::Tree(int rootValue)
{
    root = new TreeNode(rootValue);
}

Tree::~Tree()
{
    destroy(root);
}

void Tree::destroy(TreeNode *node)
{
    if (node != NULL)
    {
        for (int i = 0; i < node->children.size(); i++)
        {
            destroy(node->children[i]);
        }
        delete node;
    }
}

TreeNode *Tree::findNode(TreeNode *node, int value)
{
    if (node == NULL)
        return NULL;

    if (node->data == value)
        return node;

    for (int i = 0; i < node->children.size(); i++)
    {
        TreeNode *result = findNode(node->children[i], value);
        if (result != NULL)
            return result;
    }

    return NULL;
}

TreeNode *Tree::find(int value)
{
    return findNode(root, value);
}

void Tree::addChild(int parentValue, int childValue)
{
    TreeNode *parent = find(parentValue);
    if (parent != NULL)
    {
        TreeNode *child = new TreeNode(childValue);
        parent->children.push_back(child);
    }
}

void Tree::displayPreorder(TreeNode *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        for (int i = 0; i < node->children.size(); i++)
        {
            displayPreorder(node->children[i]);
        }
    }
}

void Tree::display()
{
    displayPreorder(root);
    cout << endl;
}

int Tree::countChildren(int parentValue)
{
    TreeNode *parent = find(parentValue);
    if (parent != NULL)
        return parent->children.size();
    return 0;
}

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int d)
    {
        data = d;
    }
};

class Tree
{
private:
    TreeNode *root;

    void displayPreorder(TreeNode *node);
    TreeNode *findNode(TreeNode *node, int value);
    void destroy(TreeNode *node);

public:
    Tree(int rootValue);
    ~Tree();

    void addChild(int parentValue, int childValue);
    void display();
    TreeNode *find(int value);
    int countChildren(int parentValue);
};

#endif

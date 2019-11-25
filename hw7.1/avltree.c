#include "avltree.h"

struct Node
{
    int value;
    int height;
    Node *left;
    Node *right;
};

int height(Node *node)
{
    return node->height;
}

int balanceFactor(Node *node)
{
    return height(node->right) - height(node->left);
}

void updateHeight(Node *node)
{
    int heightLeft = height(node->left);
    int heightRight = height(node->right);
    node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

Node* rotateRight(Node *root)
{
    Node *pivot = root->left;
    root->left = pivot->right;
    pivot->right = root;
    return pivot;
}

Node* rotateLeft(Node *root)
{
    Node *pivot = root->right;
    root->right = pivot->left;
    pivot->left = root;
    return pivot;
}

Node* balance(Node *root)
{
    updateHeight(root);
    if (balanceFactor(root) == 2)
    {
        if (balanceFactor(root->right) < 0)
        {
            root->right = rotateRight(root->right);
        }
        return rotateLeft(root);
    }
    else if (balanceFactor(root) == -2)
    {
        if (balanceFactor(root->left) < 0)
        {
            root->left = rotateLeft(root->left);
        }
        return rotateRight(root);
    }
    return root;
}
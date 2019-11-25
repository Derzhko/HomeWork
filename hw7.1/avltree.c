#include <stdio.h>
#include "avltree.h"
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    int value;
    int height;
    Node *left;
    Node *right;
};

Node* createNode(int value)
{
    Node *root;
    root->left = NULL;
    root->right = NULL;
    root->value = value;
    return root;
}



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

void add(int value, Node *root)
{
    Node *newNode = root;
    Node *previousNode = NULL;
    while (true)
    {
        if (value > newNode->value)
        {
            if (newNode->right == NULL)
            {
                newNode->right = createNode(value);
                balance(previousNode);
                return;
            }
            else
            {
                previousNode = newNode;
                newNode = newNode->right;
            }
        }
        else
        {
            if (newNode->left == NULL)
            {
                newNode->left = createNode(value);
                balance(previousNode);
                return;
            }
            else
            {
                previousNode = newNode;
                newNode = newNode->left;
            }
        }
    }
}

int deleteNode(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else if (node->left == NULL && node->right == NULL)
    {
        int returnedValue = node->value;
        free(node);
        return returnedValue;
    }
    else if (node->right != NULL)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        int returnedValue = node->value;
        free(node);
        return returnedValue;
    }
    else
    {
        int returnedValue = node->value;
        free(node);
        return returnedValue;
    }
}
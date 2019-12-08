#include "avltree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct BinaryTreeNode
{
    int value;
    int height;
    BinaryTreeNode *leftChild;
    BinaryTreeNode *rightChild;
};

struct BinaryTree
{
    BinaryTreeNode *root;
};

BinaryTree *createTree()
{
    BinaryTree *newTree = malloc(sizeof(BinaryTree));
    newTree->root = NULL;
    return newTree;
}

BinaryTreeNode *createNode(int value)
{
    BinaryTreeNode *newNode = malloc(sizeof(BinaryTreeNode));
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

int height(BinaryTreeNode* node)
{
    return node ? node->height : 0;
}

int balanceFactor(BinaryTreeNode* node)
{
    return height(node->rightChild) - height(node->leftChild);
}

void updateHeight(BinaryTreeNode* node)
{
    int rightHeight = height(node->rightChild);
    int leftHeight = height(node->leftChild);
    node->height = (rightHeight > leftHeight ? rightHeight : leftHeight) + 1;
}

BinaryTreeNode* rotateRight(BinaryTreeNode* root)
{
    BinaryTreeNode* pivot = root->leftChild;
    root->leftChild = pivot->rightChild;
    pivot->rightChild = root;
    updateHeight(root);
    updateHeight(pivot);
    return pivot;
}

BinaryTreeNode* rotateLeft(BinaryTreeNode* root)
{
    BinaryTreeNode* pivot = root->rightChild;
    root->rightChild = pivot->leftChild;
    pivot->leftChild = root;
    updateHeight(root);
    updateHeight(pivot);
}

BinaryTreeNode* balance(BinaryTreeNode* node)
{
    updateHeight(node);

    if (balanceFactor(node) == 2)
    {
        if(balanceFactor(node->rightChild) < 0)
        {
            node->rightChild = rotateRight(node->rightChild);
        }
        return(rotateLeft(node));
    }

    if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->leftChild) > 0)
        {
            node->leftChild = rotateLeft(node->leftChild);
        }
        return rotateRight(node);
    }

    return node;
}

void add(int value, BinaryTree *tree)
{
    if (tree->root == NULL)
    {
        tree->root = createNode(value);
        return;
    }
    else
    {
        BinaryTreeNode *parent = tree->root;
        BinaryTreeNode *pivot = malloc(sizeof(BinaryTreeNode));
        while (true)
        {
            if (value > parent->value)
            {
                pivot = parent;
                if (parent->rightChild != NULL)
                {
                    parent = parent->rightChild;
                }
                else
                {
                    parent->rightChild = createNode(value);
                    balance(pivot);
                    return;
                }
            }
            else if (value < parent->value)
            {
                pivot = parent;
                if (parent->leftChild != NULL)
                {
                    parent = parent->leftChild;
                }
                else
                {
                    parent->leftChild = createNode(value);
                    balance(pivot);
                    return;
                }
            }
        }
    }
}

bool search(int value, BinaryTree *tree)
{
    BinaryTreeNode *node = tree->root;
    while (true)
    {
        if (node->value == value)
        {
            return true;
        }
        else if (value > node->value)
        {
            if (node->rightChild != NULL)
            {
                node = node->rightChild;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (node->leftChild != NULL)
            {
                node = node->leftChild;
            }
            else
            {
                return false;
            }
        }
    }
}

int delete(int value, BinaryTree *tree)
{
    BinaryTreeNode *child = tree->root;
    BinaryTreeNode *parent = malloc(sizeof(BinaryTreeNode));
    while (true)
    {
        if (child == NULL)
        {
            printf("ERROR: there is no such element\n");
            return 0;
        }
        if (value > child->value)
        {
            parent = child;
            child = child->rightChild;
        }
        else if (value < child->value)
        {
            parent = child;
            child = child->leftChild;
        }
        else
        {
            break;
        }
    }
    int deletedValue = 0;
    if (child->leftChild == NULL && child->rightChild == NULL)
    {
        if (parent->leftChild == child)
        {
            parent->leftChild = NULL;
        }
        else
        {
            parent->rightChild = NULL;
        }
        deletedValue = child->value;
        free(child);
    }
    else if (child->leftChild == NULL)
    {
        if (parent->leftChild == child)
        {
            parent->leftChild = child->rightChild;
        }
        else
        {
            parent->rightChild = child->rightChild;
        }
        deletedValue = child->value;
        free(child);
    }
    else if (child->rightChild == NULL)
    {
        if (parent->leftChild == child)
        {
            parent->leftChild = child->leftChild;
        }
        else
        {
            parent->rightChild = child->leftChild;
        }
        deletedValue = child->value;
        free(child);
    }
    else
    {
        deletedValue = child->value;
        BinaryTreeNode *minimumRightChild = child->rightChild;
        BinaryTreeNode *parentRightChild = child;
        while (minimumRightChild->leftChild != NULL)
        {
            parentRightChild = minimumRightChild;
            minimumRightChild = minimumRightChild->leftChild;
        }
        child->value = minimumRightChild->value;
        if (parentRightChild->leftChild == minimumRightChild)
        {
            parentRightChild->leftChild = NULL;
        }
        else
        {
            parentRightChild->rightChild = NULL;
        }
        free(minimumRightChild);
    }
    return deletedValue;
}

void printIncrementalValuesRealization(BinaryTreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    printIncrementalValuesRealization(node->leftChild);
    printf("%d ", node->value);
    printIncrementalValuesRealization(node->rightChild);
}

void printIncrementalValues(BinaryTree *tree)
{
    printIncrementalValuesRealization(tree->root);
}

void printDecrementValuesRealization(BinaryTreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    printDecrementValuesRealization(node->rightChild);
    printf("%d ", node->value);
    printDecrementValuesRealization(node->leftChild);
}

void printDecrementValues(BinaryTree *tree)
{
    printDecrementValuesRealization(tree->root);
}

void printAlternativeViewRealization(BinaryTreeNode *node)
{
    if (node == NULL)
    {
        printf("NULL");
        return;
    }
    printf("(%d ", node->value);
    printAlternativeViewRealization(node->rightChild);
    printf(" ");
    printAlternativeViewRealization(node->leftChild);
    printf(")");
}

void printAlternativeView(BinaryTree *tree)
{
    printAlternativeViewRealization(tree->root);
}
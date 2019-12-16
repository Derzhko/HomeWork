#include "bsttree.h"
#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode
{
    int value;
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

void deleteNode(BinaryTreeNode* node)
{
    if (node == NULL)
    {
        return;
    }
    deleteNode(node->rightChild);
    deleteNode(node->leftChild);
    free(node);
    return;
}

void deleteTree(BinaryTree* tree)
{
    deleteNode(tree->root);
    free(tree);
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
        while (true)
        {
            if (value > parent->value)
            {
                if (parent->rightChild != NULL)
                {
                    parent = parent->rightChild;
                }
                else
                {
                    parent->rightChild = createNode(value);
                    return;
                }
            }
            else if (value < parent->value)
            {
                if (parent->leftChild != NULL)
                {
                    parent = parent->leftChild;
                }
                else
                {
                    parent->leftChild = createNode(value);
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

void deleteNodeWithEmptyLeftChild(BinaryTree *tree, BinaryTreeNode *parent, BinaryTreeNode *child)
{
    if (child == tree->root)
    {
        tree->root = child->rightChild;
    }
    else if (parent->leftChild == child)
    {
        parent->leftChild = child->rightChild;
    }
    else
    {
        parent->rightChild = child->rightChild;
    }
}

void deleteNodeWithEmptyRightChild(BinaryTree *tree, BinaryTreeNode *parent, BinaryTreeNode *child)
{
    if (child == tree->root)
    {
        tree->root = child->leftChild;
    }
    else if (parent->leftChild == child)
    {
        parent->leftChild = child->leftChild;
    }
    else
    {
        parent->rightChild = child->leftChild;
    }
}

void searchMinimumRightChild(BinaryTreeNode *minimumRightChild, BinaryTreeNode *parentRightChild)
{
    while (minimumRightChild->leftChild != NULL)
    {
        parentRightChild = minimumRightChild;
        minimumRightChild = minimumRightChild->leftChild;
    }
}

int delete(int value, BinaryTree *tree)
{
    BinaryTreeNode *child = tree->root;
    BinaryTreeNode *parent = malloc(sizeof(BinaryTreeNode));
    if (child == NULL)
    {
        printf("ERROR: there is no such element\n");
        return 0;
    }
    while (child->value != value)
    {
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
        if (child == NULL)
        {
            printf("ERROR: there is no such element\n");
            return 0;
        }
    }
    int deletedValue = 0;
    if (child->leftChild == NULL && child->rightChild == NULL)
    {
        if (child == tree->root)
        {
            tree->root = NULL;
        }
        else if (parent->leftChild == child)
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
        deleteNodeWithEmptyLeftChild(tree, parent, child);
        deletedValue = child->value;
        free(child);
    }
    else if (child->rightChild == NULL)
    {
        deleteNodeWithEmptyRightChild(tree, parent, child);
        deletedValue = child->value;
        free(child);
    }
    else
    {
        deletedValue = child->value;
        BinaryTreeNode *minimumRightChild = child->rightChild;
        BinaryTreeNode *parentRightChild = child;
        searchMinimumRightChild(minimumRightChild, parentRightChild);
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
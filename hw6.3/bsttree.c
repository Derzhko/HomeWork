//
// Created by alxderzhko on 28.11.2019.
//

#include "bsttree.h"
#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
};

struct BinaryTree
{
    BinaryTreeNode* root;
};

BinaryTree* createTree()
{
    BinaryTree* newTree = malloc(sizeof(BinaryTree));
    newTree->root = NULL;
    return newTree;
}

BinaryTreeNode* createNode(int value)
{
    BinaryTreeNode* newNode = malloc(sizeof(BinaryTreeNode));
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

void add(int value, BinaryTree* tree)
{
    if (tree->root == NULL)
    {
        tree->root = createNode(value);
        return;
    }
    else
    {
        BinaryTreeNode* parent = tree->root;
        while(true)
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

bool search(int value, BinaryTree* tree)
{
    BinaryTreeNode* node = tree->root;
    while(true)
    {
        if(node->value == value)
        {
            return true;
        }
        else if (value > node->value)
        {
            if  (node->rightChild != NULL)
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

int delete(int value, BinaryTree* tree)
{
    if (tree->root == NULL)
    {
        return (int)NULL;
    }
    else
    {
        BinaryTreeNode* child = tree->root;
        BinaryTreeNode* parent = malloc(sizeof(BinaryTreeNode));
        while(true)
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
            while(minimumRightChild->leftChild != NULL)
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
}
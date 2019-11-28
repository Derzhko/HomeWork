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
        return NULL;
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
        if (child->leftChild == NULL && child->rightChild == NULL)
        {
            int deletedValue = child->value;
            free(child);
            return deletedValue;
        }
        else if (child->leftChild == NULL)
        {
            int deletedValue = child->value;
            BinaryTreeNode* deletedNode = child;
            child = child->rightChild;
            free(deletedNode);
            return deletedValue;
        }
        else if (child->rightChild == NULL)
        {
            int deletedValue = child->value;
            BinaryTreeNode* deletedNode = child;
            child = child->leftChild;
            free(deletedNode);
            return deletedValue;
        }
    }
}
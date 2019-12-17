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
    newNode->height = 1;
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

int height(BinaryTreeNode* node)
{
    return node != NULL ? node->height : 0;
}

int balanceFactor(BinaryTreeNode* node)
{
    return height(node->rightChild) - height(node->leftChild);
}

void updateHeight(BinaryTreeNode* node)
{
    int rightHeight = height(node->rightChild);
    int leftHeight = height(node->leftChild);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
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
    return pivot;
}

BinaryTreeNode* balance(BinaryTreeNode* node)
{
    updateHeight(node);
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->rightChild) < 0)
        {
            node->rightChild = rotateRight(node->rightChild);
        }
        return rotateLeft(node);
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

BinaryTreeNode* addElement(int value, BinaryTreeNode *newNode)
{
    if (newNode == NULL)
    {
        return createNode(value);
    }
    if (value < newNode->value)
    {
        newNode->leftChild = addElement(value, newNode->leftChild);
    }
    else
    {
        newNode->rightChild = addElement(value, newNode->rightChild);
    }
    return balance(newNode);
}

BinaryTreeNode* add(int value, BinaryTree* tree)
{
    if (tree->root == NULL)
    {
        tree->root = createNode(value);
    }
    else
    {
        tree->root = addElement(value, tree->root);
    }
    return tree->root;
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

BinaryTreeNode* findMinimumValue(BinaryTreeNode* node)
{
    return node->leftChild != NULL ? findMinimumValue(node->leftChild) : node;
}

BinaryTreeNode* removeMinimumValue(BinaryTreeNode* node)
{
    if (node->leftChild == NULL)
    {
        return node->rightChild;
    }
    node->leftChild = removeMinimumValue(node->leftChild);
    return balance(node);
}

BinaryTreeNode* removeElement(int value, BinaryTreeNode* node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (value < node->value)
    {
        node->leftChild = removeElement(value, node->leftChild);
    }
    else if (value > node->value)
    {
        node->rightChild = removeElement(value, node->rightChild);
    }
    else
    {
        BinaryTreeNode* leftNode = node->leftChild;
        BinaryTreeNode* rightNode = node->rightChild;
        free(node);
        if (rightNode == NULL)
        {
            return leftNode;
        }
        BinaryTreeNode* minimum = findMinimumValue(rightNode);
        minimum->rightChild = removeMinimumValue(rightNode);
        minimum->leftChild = leftNode;
        return balance(minimum);
    }
    return balance(node);
}

void delete(int value, BinaryTree* tree)
{
    tree->root = removeElement(value, tree->root);
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
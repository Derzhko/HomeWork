#ifndef BSTTREE_H
#define BSTTREE_H

#include <stdbool.h>

typedef struct BinaryTree BinaryTree;
typedef struct BinaryTreeNode BinaryTreeNode;

BinaryTree* createTree();

void add(int value, BinaryTree* tree);
int delete(int value, BinaryTree* tree);
bool search(int value, BinaryTree* tree);

void printIncrementalValues(BinaryTree* tree);
void printDecrementValues(BinaryTree* tree);

void printAlternativeView(BinaryTree* tree);
#endif //BSTTREE_H

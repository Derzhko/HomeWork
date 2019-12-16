#ifndef AVLTREE_H
#define AVLTREE_H
#include <stdbool.h>

typedef struct BinaryTree BinaryTree;
typedef struct BinaryTreeNode BinaryTreeNode;

BinaryTree* createTree();
void deleteTree(BinaryTree* tree);

BinaryTreeNode* add(int value, BinaryTree* tree);
void delete(int value, BinaryTree* tree);
bool search(int value, BinaryTree* tree);

void printIncrementalValues(BinaryTree* tree);
void printDecrementValues(BinaryTree* tree);

void printAlternativeView(BinaryTree* tree);

#endif //AVLTREE_H

//
// Created by alxderzhko on 28.11.2019.
//

#ifndef BSTTREE_H
#define BSTTREE_H

#include <stdbool.h>

typedef struct BinaryTree BinaryTree;
typedef struct BinaryTreeNode BinaryTreeNode;

BinaryTree* createTree();

void add(int value, BinaryTree* tree);
int delete(int value, BinaryTree* tree);
bool search(int value, BinaryTree* tree);

#endif //BSTTREE_H

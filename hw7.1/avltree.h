#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct Node Node;
typedef struct AvlTree AvlTree;

int height(Node *node);
int balanceFactor(Node *node);
void updateHeight(Node *node);
void add(int value, Node *root);
Node* createNode(int value);

#endif //AVLTREE_H

#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct Node Node;

int height(Node *node);
int balanceFactor(Node *node);
void updateHeight(Node *node);

#endif //AVLTREE_H

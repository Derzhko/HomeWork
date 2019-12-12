#include <stdio.h>
#include "avltree.h"

int main() {
    BinaryTree* myTree = createTree();
    add(1, myTree);
    add(2, myTree);
    add(3, myTree);
    add(4, myTree);
    printAlternativeView(myTree);
    return 0;
}
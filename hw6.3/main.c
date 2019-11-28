#include <stdio.h>
#include "bsttree.h"

int main()
{
    BinaryTree *myTree = createTree();
    add(3, myTree);
    add(1, myTree);
    add(5, myTree);
    add(4, myTree);
    for (int i = 0; i < 7; ++i)
    {
        printf("Is %d are in tree? %d\n", i, search(i, myTree));
    }
    delete(1, myTree);
    printf("\n");
    for (int i = 0; i < 7; ++i)
    {
        printf("Is %d are in tree? %d\n", i, search(i, myTree));
    }
    add(6, myTree);
    delete(5, myTree);
    printf("\n");
    for (int i = 0; i < 7; ++i)
    {
        printf("Is %d are in tree? %d\n", i, search(i, myTree));
    }
    return 0;
}
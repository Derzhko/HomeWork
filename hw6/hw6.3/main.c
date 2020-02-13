#include <stdio.h>
#include "bsttree.h"
#include <stdlib.h>
int main()
{
    BinaryTree *myTree = createTree();
    int number = 0;
    int value = 0;
    while (true)
    {
        printf("1: add value\n");
        printf("2: delete value\n");
        printf("3: search value\n");
        printf("4: Output values in ascending order\n");
        printf("5: Output values in descending order\n");
        printf("6: Output values in alternative format\n");
        printf("7: exit\n");
        scanf("%d", &number);
        switch (number)
        {
            case 1:
                printf("insert value\n");
                scanf("%d", &value);
                if (value != 0 && value == NULL)
                {
                    printf("Insert incorrect value\n");
                }
                else
                {
                    add(value, myTree);
                }
                break;
            case 2:
                printf("insert value\n");
                scanf("%d", &value);
                if (value != 0 && value == NULL)
                {
                    printf("Insert incorrect value\n");
                }
                else
                {
                    delete(value, myTree);
                }
                break;
            case 3:
                printf("insert value\n");
                scanf("%d", &value);
                if (value != 0 && value == NULL)
                {
                    printf("Insert incorrect value\n");
                }
                else
                {
                    printf("Is %d are in tree? ", value);
                    printf(search(value, myTree) ? "YES\n" : "NO\n");
                }
                break;
            case 4:
                printf("Output values in ascending order\n");
                printIncrementalValues(myTree);
                printf("\n");
                break;
            case 5:
                printf("Output values in descending order\n");
                printDecrementValues(myTree);
                printf("\n");
                break;
            case 6:
                printf("Output values in alternative format\n");
                printAlternativeView(myTree);
                printf("\n");
                break;
            case 7:
                deleteTree(myTree);
                return 0;
        }
    }
}
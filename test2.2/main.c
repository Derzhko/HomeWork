#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    List* myList = createList();
    printf("Insert count of element\n");
    int count = 0;
    scanf("%d", &count);
    int value = 0;
    for (int i = 0; i < count; ++i)
    {
        printf("Insert value\n");
        scanf("%d", &value);
        add(value, myList);
    }
    insertionSort(myList);
    printValue(myList);
    return 0;
}
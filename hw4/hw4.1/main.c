#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

int safePosition(List* list, int step)
{
    for (int i = step; size(list) != 1; i += step)
    {
        delete(i % size(list) == 0 ? size(list) : i % size(list), list);
    }
    return getValue(1, list);
}

int main()
{
    int size = 0;
    int step = 0;
    printf("Insert number of soldiers\n");
    scanf("%d", &size);
    List* list = createList(size);
    printf("Insert number of killed soldier\n");
    scanf("%d", &step);
    printf("safe position is %d\n", safePosition(list, step));
    return 0;
}
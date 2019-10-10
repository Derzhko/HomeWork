#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arrayLength = 0;
    printf("Insert array length\n");
    scanf("%d", &arrayLength);
    int *array = malloc(arrayLength * sizeof(int));
    printf("Insert value\n");
    for (int i = 0; i < arrayLength; ++i)
    {
        scanf("%d", &array[i]);
    }
    int counter = 0;
    for (int i = 0; i < arrayLength; ++i)
    {
        if (array[i] == 0)
        {
            array[i] = array[i - counter];
            array[i - counter] = 0;
        }
    }
    printf("Final array\n");
    for (int i = 0; i < arrayLength; ++i)
    {
        printf("%d ", &array[i]);
    }
    return 0;
}
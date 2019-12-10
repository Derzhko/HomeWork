#include <stdio.h>

const int arrayMaxLength = 20;

void moveZerosToEnd(int *numbers, int arrayLength)
{
    for (int i = 0; i < arrayLength; ++i)
    {
        if (numbers[i] == 0)
        {
            for (int j = i; j < arrayLength - 1; ++j)
            {
                numbers[j] = numbers[j + 1];
            }
            numbers[arrayLength - 1] = 0;
        }
    }
}

int main()
{
    int numbers[arrayMaxLength];
    for (int i = 0; i < arrayMaxLength; ++i)
    {
        numbers[i] = 0;
    }
    int arrayLength = 0;
    printf("Insert length\n");
    scanf("%d", &arrayLength);
    printf("Insert your numbers\n");
    for (int i = 0; i < arrayLength; ++i)
    {
        scanf("%d", &numbers[i]);
    }
    moveZerosToEnd(numbers, arrayLength);
    printf("Result array\n");
    for (int i = 0; i < arrayLength; ++i)
    {
        printf("%d ", numbers[i]);
    }
    return 0;
}
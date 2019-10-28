#include <stdio.h>

const int arrayMaxLength = 20;

void putEnd(int *numbers, int arrayLength)
{
    int index = arrayLength - 1;
    for (int i = arrayLength - 1; i >= 0; --i)
    {
        if (numbers[i] == 0)
        {
            numbers[i] = numbers[index];
            numbers[index] = 0;
            --index;
        }
    }
}

int main() {
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

    putEnd(numbers, arrayLength);

    printf("Result array\n");
    for (int i = 0; i < arrayLength; ++i)
    {
        printf("%d ", numbers[i]);
    }
    return 0;
}
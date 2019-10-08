#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int startLength = 10;

void insertionSort(int numbers[], int arrayLength)
{
    for (int i = 2; i < arrayLength; i += 2)
    {
        int j = i;
        while (j > 0 && numbers[j - 2] > numbers[j])
        {
            int tmp = numbers[j];
            numbers[j] = numbers[j - 2];
            numbers[j - 2] = tmp;
            j -= 2;
        }
    }
    return;
}

int main()
{
    int *numbers = malloc(startLength * sizeof(int));
    int arrayLength = startLength;
    int length = 0;
    char answer = '\0';
    for (int i = 0; i < startLength; ++i)
    {
        numbers[i] = 0;
    }
    printf("Do you want insert a value?(y/n)\n");
    scanf("%c", &answer);
    if (answer == 'y')
    {
        int number = 0;
        printf("Insert value and insert '0', when you will want to stop\n");
        scanf("%d", &number);
        for (int i = 0; number != 0; ++i)
        {
            if (i == arrayLength)
            {
                int *helperArray = malloc((arrayLength + startLength) * sizeof(int));
                for (int i = 0; i < arrayLength + startLength; ++i)
                {
                    helperArray[i] = 0;
                }
                for (int i = 0; i < arrayLength; ++i)
                {
                    helperArray[i] = numbers[i];
                }
                int *index = numbers;
                free(index);
                numbers = helperArray;
                arrayLength += startLength;
            }
            numbers[i] = number;
            scanf("%d", &number);
            length = i + 1;
        }
    }
    else
    {
        printf("Insert length\n");
        scanf("%d", &length);
        if (length > startLength)
        {
            numbers = malloc(length * sizeof(int));
        }
        srand(time(NULL));
        for (int i = 0; i < length; ++i)
        {
            numbers[i] = rand() % 31 + 11;
        }
    }

    insertionSort(numbers, length);
    printf("'Sorted' array\n");
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}
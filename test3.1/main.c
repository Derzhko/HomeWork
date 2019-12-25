#include <stdio.h>

void shellSort(int array[], int arrayLength)
{
    int delta = arrayLength / 2;
    while (delta > 0)
    {
        for (int i = 0; i < arrayLength - delta; ++i)
        {
            for (int j = i; j >= 0 && array[j] > array[j + delta]; --j)
            {
                int helper = array[j];
                array[j] = array[j + delta];
                array[j + delta] = helper;
            }
        }
        delta /= 2;
    }
}

int main()
{
    int arrayLength = 0;
    printf("Insert length of array\n");
    scanf("%d", &arrayLength);
    int numbers[arrayLength];
    for (int i = 0; i < arrayLength; ++i)
    {
        int number = 0;
        printf("Insert number\n");
        scanf("%d", &number);
        numbers[i] = number;
    }
    shellSort(numbers, arrayLength);
    printf("sorted array: ");
    for (int i = 0; i < arrayLength; ++i)
    {
        printf("%d ", numbers[i]);
    }
    return 0;
}
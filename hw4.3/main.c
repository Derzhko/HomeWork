#include <stdio.h>

const int maxLength = 15;

void spiralOutput(int array[maxLength][maxLength], int length)
{
    int delta = 0;
    int indexOfCenter = length / 2;
    int i = indexOfCenter;
    int j = indexOfCenter;
    printf("%d ", array[i][j]);
    ++j;
    while (delta <= length - 2)
    {
        for (int index = j; j <= index + delta; ++j)
        {
            printf("%d ", array[i][j]);
        }
        --j;
        ++i;
        for (int index = i; i <= index + delta; ++i)
        {
            printf("%d ", array[i][j]);
        }
        --i;
        --j;
        ++delta;
        for (int index = j; j >= index - delta; --j)
        {
            printf("%d ", array[i][j]);
        }
        ++j;
        --i;
        for (int index = i; i >= index - delta; --i)
        {
            printf("%d ", array[i][j]);
        }
        ++i;
        ++j;
        ++delta;
    }
    --delta;
    for (int index = j ; j <= index + delta; ++j)
    {
        printf("%d ", array[i][j]);
    }
    --j;
    ++i;
}

int main()
{
    int array[maxLength][maxLength];
    int length = 0;
    for (int i = 0; i < maxLength; i++)
    {
        for (int j = 0; j < maxLength; j++)
        {
            array[i][j] = 0;
        }
    }
    printf("Insert length of array\n");
    scanf("%d", &length);
    printf("Insert value\n");
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("Input array\n");
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            if (array[i][j] >= 10)
            {
                printf("%d\t", array[i][j]);
            }
            else
            {
                printf("%d\t", array[i][j]);
            }
        }
        printf("\n");
    }
    printf("Spiral output value\n");
    spiralOutput(array, length);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void otherSum(int *sum, int arrayLength, int value)
{
    if(sum[value - arrayLength + 1] != 0)
    {
        sum[value - arrayLength] += sum[value - arrayLength + 1];
        sum[arrayLength - 1] = 0;
        printf("\n");
        for (int i = 0; i < value; ++i)
        {
            printf("%d ", sum[i]);
        }
        otherSum(sum, arrayLength - 1, value);
    }
    else
    {
        return;
    }
}

int main() {
    int value = 0;
    printf("Insert your value\n");
    scanf("%d", &value);
    int *sum = malloc(value * sizeof(int));
    for (int i = 0; i < value; ++i)
    {
        sum[i] = 1;
    }
    otherSum(sum, value, value);
    return 0;
}
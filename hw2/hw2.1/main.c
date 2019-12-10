#include <stdio.h>
#include <stdlib.h>

void otherSum(int *sum, int nose, )

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
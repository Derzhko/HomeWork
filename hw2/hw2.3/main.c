#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

const int numbersLength = 10;

int compare(const void * x1, const void * x2)
{
    return ( *(int*)x1 - *(int*)x2 );
}

int main()
{
    int try = 0;
    int cows = 0;
    int bulls = 0;
    int numbers[numbersLength];
    for (int i = 0; i < numbersLength; ++i)
    {
        numbers[i] = i;
    }
    int value = 0;
    for (int i = 4; i > 0; )
    {
        srand(time(NULL));
        int helper = rand() % (10 - 4 + i) + (4 - i);
        if (numbers[helper] != -1)
        {
            value = value + numbers[helper] * (int)pow(10, i - 1);
            numbers[helper] = -1;
            qsort(&numbers[4 - i], numbersLength - 4 + i, sizeof(int), compare);
            --i;
        }
    }
    if (value > 10000)
    {
        value -= 1000;
    }
    do
    {
        cows = 0;
        bulls = 0;
        printf("Insert your four-digit number\n");
        scanf("%d", &try);
        if ((try >= 1234) && (try <= 9876))
        {
            for (int i = 1; i <= 4; ++i)
            {
                int valueNumber = (value % (int) pow(10, i)) / (int) pow(10, i - 1);
                for (int j = 1; j <= 4; ++j)
                {
                    int tryNumber = (try % (int) pow(10, j) / (int) pow(10, j - 1));
                    if ((valueNumber == tryNumber) && (i == j))
                    {
                        ++bulls;
                    } else if (valueNumber == tryNumber)
                    {
                        ++cows;
                    }
                }
            }
            printf("cows: %d\n", cows);
            printf("bulls: %d\t", bulls);
            printf("(value to check the code: %d)\n", value);
        }
        else
        {
            printf("Insert incorrect number\n");
        }
    }
    while (bulls != 4);
    printf("YOU WIN!!");
    return 0;
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int numbersLength = 10;

int main()
{
    int try = 1234;
    int cows = 0;
    int bulls = 0;
    int numbers[numbersLength];
    int value[] = {0, 0, 0, 0};
    int tryValue[] = {0, 0, 0, 0};
    for (int i = 0; i < numbersLength; ++i)
    {
        numbers[i] = i;
    }
    srand(time(NULL));
    for (int i = 0; i < 4; )
    {
        int randomIndex = 0;
        if (i == 0)
        {
            randomIndex = rand() % 9 + 1;
        }
        else
        {
            randomIndex = rand() % (9 - i) + i;
        }
        if (numbers[randomIndex] != -1)
        {
            value[i] = numbers[randomIndex];
            numbers[randomIndex] = numbers[i];
            numbers[i] = -1;
            ++i;
        }
    }
    do
    {
        cows = 0;
        bulls = 0;
        printf("Insert your four-digit number\n");
        scanf("%d", &try);
        if ((try >= 1234) && (try <= 9876))
        {
            for (int i = 0; i < 4; i++)
            {
                tryValue[3 - i] = try % 10;
                try = try / 10;
            }
            for (int i = 0; i < 4; ++i)
            {
                int valuesDigit = value[i];
                for (int j = 0; j < 4; ++j)
                {
                    int tryDigit = tryValue[j];
                    if (valuesDigit == tryDigit)
                    {
                        if (i == j)
                        {
                            ++bulls;
                        }
                        else
                        {
                            ++cows;
                        }
                    }
                }
            }
            printf("cows: %d\n", cows);
            printf("bulls: %d\n", bulls);
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
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

const int numbersLength = 10;

int getDigitByPosition(int number, int position)
{
    return (number % (int) pow(10, position)) / (int) pow(10, position - 1);
}

int main()
{
    int try = 1234;
    int cows = 0;
    int bulls = 0;
    int numbers[numbersLength];
    for (int i = 0; i < numbersLength; ++i)
    {
        numbers[i] = i;
    }
    int value = 0;
    for (int i = 0; i < 4; )
    {
        srand(time(NULL));
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
            value = value * 10 + numbers[randomIndex];
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
            for (int i = 1; i <= 4; ++i)
            {
                int valuesDigit = getDigitByPosition(value, i);
                for (int j = 1; j <= 4; ++j)
                {
                    int tryDigit = getDigitByPosition(try, j);
                    if (valuesDigit == tryDigit)
                    {
                        if (i == j)
                        {
                            ++bulls;
                        }
                    } else if (valuesDigit == tryDigit)
                    {
                        ++cows;
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
#include <stdio.h>

int searchGcd(int number1, int number2);//Наибольший общий делитель

void fraction(int k)
{
    double eps = 1;
    for (int i = 2; i <= k + 1; ++i)
    {
        eps /= (i + 0.);
    }
    int numeratorMin = k - 1;
    int denominatorMin = k;
    double maxValue = (k - 1.) / k;
    double previous = 0;
    while (previous < maxValue - eps)
    {
        for (int n = 1; n <= k - 1; ++n)
        {
            for (int d = k; d > n; --d)
            {
                if (previous + eps < n / (d + 0.) && n / (d + 0.) < maxValue + eps && searchGcd(n, d) == 1)
                {
                    maxValue = n / (d + 0.);
                    numeratorMin = n;
                    denominatorMin = d;
                }
            }
        }
        printf("%d / %d\n", numeratorMin, denominatorMin);
        previous = maxValue;
        maxValue = (k - 1.) / k;
    }
    return;
}


int main()
{
    int maxDenominator = 0;
    printf("Insert max denominator\n");
    scanf("%d", &maxDenominator);
    fraction(maxDenominator);
    return 0;
}

int searchGcd(int number1, int number2)
{
    while (number1 != 0 && number2 != 0) {
        if (number1 >= number2)
        {
            number1 %= number2;
        }
        else
        {
            number2 %= number1;
        }
    }
    int result = number1 | number2;
    return result;
}
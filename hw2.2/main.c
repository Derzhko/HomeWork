#include <stdio.h>

int getGCD(int a, int b)
{
    while (a != 0 && b != 0) {
        if (a >= b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    int result = 0;
    if (a == 0)
    {
        result = b;
    }
    else
    {
        result = a;
    }
    return result;
}

void findingAFraction(int k)
{
    double eps = 1;
    for (int i = 2; i <= k + 1; ++i)
    {
        eps /= (i + 0.);
    }
    int numeratorMin = k - 1;
    int denominatorMin = k;
    double min = (k - 1.) / k;
    double previous = 0;
    while (previous < min - eps)
    {
        for (int n = 1; n <= k - 1; ++n)
        {
            for (int d = k; d > n; --d)
            {
                if (previous + eps < n / (d + 0.) && n / (d + 0.) < min + eps && getGCD(n, d) == 1)
                {
                    min = n / (d + 0.);
                    numeratorMin = n;
                    denominatorMin = d;
                }
            }
        }
        printf("%d / %d\n", numeratorMin, denominatorMin);
        previous = min;
        min = (k - 1.) / k;
    }
    return;
}


int main()
{
    int maxDenominator = 0;
    printf("Insert max denominator\n");
    scanf("%d", &maxDenominator);
    findingAFraction(maxDenominator);
    return 0;
}


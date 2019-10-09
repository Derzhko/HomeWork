#include <stdio.h>

int gcd(int a, int b);//Наибольший общий делитель

void fraction(int k)
{
    double eps = 1;
    for (int i = 2; i <= k + 1; ++i)
    {
        eps /= (i + 0.);
    }
    int n_min = k - 1;
    int d_min = k;
    double min = (k - 1.) / k;
    double previous = 0;
    while (previous < min - eps)
    {
        for (int n = 1; n <= k - 1; ++n)
        {
            for (int d = k; d > n; --d)
            {
                if (previous + eps < n / (d + 0.) && n / (d + 0.) < min + eps && gcd(n, d) == 1)
                {
                    min = n / (d + 0.);
                    n_min = n;
                    d_min = d;
                }
            }
        }
        printf("%d / %d\n", n_min, d_min);
        previous = min;
        min = (k - 1.)/k;
    }
    return;
}


int main()
{
    int maxDen;
    printf("Insert max denominator\n");
    scanf("%d", &maxDen);
    fraction(maxDen);
    return 0;
}

int gcd(int a, int b)
{
    while (a != 0 &&  b != 0) {
        if (a >= b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return a | b;
}
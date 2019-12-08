#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

const int lengthOfFraction = 52;

double convertingArrayToDouble(int array[])
{
    double number = 1;
    for (int i = 0; i < lengthOfFraction; ++i)
    {
        number += array[i] * pow(2, -(i + 1));
    }
    return number;
}

void differentiationNumber(int *sign, int *exponent, double *fraction, unsigned char *numberInBinaryCode)
{
    *exponent = 0;
    int fractionInBite[lengthOfFraction];
    int index = 0;
    bool isZero = true;
    for (int i = 0; i < lengthOfFraction; ++i)
    {
        fractionInBite[i] = 0;
    }
    for (int i = 7; i >= 0; --i)
    {
        for (int j = 7; j >= 0; --j)
        {
            isZero = numberInBinaryCode[i] & (1 << j) ? false : isZero;
            if (i == 7)
            {
                if (j == 7)
                {
                    *sign = (numberInBinaryCode[i] & (1 << 7)) ? 1 : 0;
                }
                else
                {
                    *exponent |= (numberInBinaryCode[i] & (1 << j)) << 4;
                }
            }
            else if (i == 6)
            {
                if (j > 3)
                {
                    *exponent |= (numberInBinaryCode[i] & (1 << j)) >> 4;
                }
                else
                {
                    fractionInBite[index] = numberInBinaryCode[i] & (1 << j) ? 1 : 0;
                    index++;
                }
            }
            else
            {
                fractionInBite[index] = numberInBinaryCode[i] & (1 << j) ? 1 : 0;
                index++;
            }
        }
    }
    if (isZero)
    {
        *exponent = 1023;
        return;
    }
    *fraction = convertingArrayToDouble(fractionInBite);
}

int main()
{
    double number = 0.0;
    unsigned char *numberInBinaryCode = malloc(sizeof(double));
    numberInBinaryCode = (unsigned char *) &number;
    printf("Insert number\n");
    scanf("%lf", &number);
    int sign = 0;
    int exponent = 0;
    double fraction = 0.0;
    differentiationNumber(&sign, &exponent, &fraction, numberInBinaryCode);
    free(numberInBinaryCode);
    printf("Number in exponential form\n");
    printf("%c%f*2^%d", (sign == 1) ? '-' : '+', fraction, exponent - 1023);
    return 0;
}
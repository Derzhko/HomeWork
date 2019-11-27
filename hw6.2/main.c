#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int lengthOfInt = 32;

void add(int sum[], int term1[], int term2[])
{
    int reserve = 0;
    for (int i = lengthOfInt - 1; i >= 0; --i)
    {
        sum[i] = (term1[i] + term2[i] + reserve) % 2;
        reserve = (term1[i] + term2[i] + reserve) / 2;
    }
}

void convertingNumberInAdditionalCode(int numberInBinaryCode[], int number)
{
    if (number < 0)
    {
        number = abs(number);
        numberInBinaryCode[0] = 1;
    }
    for (int i = lengthOfInt - 1; number > 0; --i)
    {
        numberInBinaryCode[i] = number % 2;
        number /= 2;
    }
    if (numberInBinaryCode[0] == 1)
    {
        numberInBinaryCode[0] = 0;
        for (int i = 0; i < lengthOfInt; ++i)
        {
            numberInBinaryCode[i] = numberInBinaryCode[i] == 1 ? 0 : 1;
        }
        int reserve = 1;
        for (int i = lengthOfInt - 1; i >= 0; --i)
        {
            int helper = numberInBinaryCode[i] + reserve;
            numberInBinaryCode[i] = (helper) % 2;
            reserve = (helper) / 2;
        }
    }
}

void subtractMinusOne(int numInBinaryCode[])
{
    int index = lengthOfInt - 1;
    while (numInBinaryCode[index] == 0)
    {
        --index;
    }
    numInBinaryCode[index] = 0;
    for (int i = index + 1; i < lengthOfInt; ++i)
    {
        numInBinaryCode[i] = 1;
    }
}

int convertingFromAdditionalBinaryToDec(int numberInBinaryCode[])
{
    int number = 0;
    if (numberInBinaryCode[0] == 1)
    {
        subtractMinusOne(numberInBinaryCode);
        for (int i = 1; i < lengthOfInt; ++i)
        {
            numberInBinaryCode[i] = numberInBinaryCode[i] == 1 ? 0 : 1;
        }
    }
    for (int i = lengthOfInt - 1; i > 0; --i)
    {
        number += numberInBinaryCode[i] *  (int)pow(2, lengthOfInt - 1 - i);
    }
    if (numberInBinaryCode[0] == 1)
    {
        number *= -1;
    }
    return number;
}

void printNumberInBinaryCode(int *numberInBinaryCode)
{
    for (int i = 0; i < lengthOfInt; ++i)
    {
        printf("%d", numberInBinaryCode[i]);
    }
    printf("\n");
}

int main()
{
    int term1 = 0;
    int term2 = 0;
    int sum = 0;
    printf("Insert first term\n");
    scanf("%d", &term1);
    printf("Insert second term\n");
    scanf("%d", &term2);
    int term1InBinaryCode[lengthOfInt];
    int term2InBinaryCode[lengthOfInt];
    int sumInBinaryCode[lengthOfInt];
    for (int i = 0; i < lengthOfInt; ++i)
    {
        term1InBinaryCode[i] = 0;
        term2InBinaryCode[i] = 0;
        sumInBinaryCode[i] = 0;
    }
    convertingNumberInAdditionalCode(term1InBinaryCode, term1);
    convertingNumberInAdditionalCode(term2InBinaryCode, term2);
    printf("first term in additional code\n");
    printNumberInBinaryCode(term1InBinaryCode);
    printf("second term in additional code\n");
    printNumberInBinaryCode(term2InBinaryCode);
    add(sumInBinaryCode, term1InBinaryCode, term2InBinaryCode);
    printf("sum in additional code\n");
    printNumberInBinaryCode(sumInBinaryCode);
    sum = convertingFromAdditionalBinaryToDec(sumInBinaryCode);
    printf("sum\n");
    printf("%d", sum);
    return 0;
}
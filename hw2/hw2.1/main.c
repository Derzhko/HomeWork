#include <stdio.h>

const int maxNumber = 20;

void printTerms(int arrayOfTerms[], int indexOfNose, int indexOfTale, int number)
{
}

int main() {
    int number = 0;
    int arrayOfTerms[maxNumber];
    int indexOfNose = 0;
    int indexOfTale = 0;
    for (int i = 0; i < maxNumber; ++i)
    {
        arrayOfTerms[i] = 0;
    }
    printf("Insert number\n");
    scanf("%d", &number);
    arrayOfTerms[0] = 7;
    printTerms(arrayOfTerms, indexOfNose, indexOfTale);
    return 0;
}
#include <stdio.h>
#include <math.h>

const int numbersMaxLength = 9;

void sort(int numbers[], int numbersLength)
{
    for (int i = 0; i < numbersLength; ++i)
    {
        for (int j = 0; j < numbersLength - 1; ++j)
        {
            if (numbers[j] > numbers[j + 1])
            {
                numbers[j] = numbers[j] + numbers[j + 1];
                numbers[j + 1] = numbers[j] - numbers[j + 1];
                numbers[j] = numbers[j] - numbers[j + 1];
            }
        }
    }
    return;
}

int main()
{
    int number = 0;
    int numbers[numbersMaxLength];
    int numbersLength = 0;
    int otherNumber = 0;

    for (int i = 0; i < numbersMaxLength; ++i)
    {
        numbers[i] = -1;
    }

    printf("Insert your number\n");
    scanf("%d", &number);

    while (number > 0)
    {
        ++numbersLength;
        numbers[numbersLength - 1] = number % 10;
        number = number / 10;
    }

    sort(numbers, numbersLength);
    for (int i = 0; i < numbersLength; ++i)
    {
        otherNumber = otherNumber + (numbers[i] * pow(10, numbersLength - i - 1));
    }

    printf("Minimal number\n%d", otherNumber);
    return 0;
}
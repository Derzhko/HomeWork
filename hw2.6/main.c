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
}

int main()
{
    int number = 0;
    int numbers[numbersMaxLength];
    int numbersLength = 0;
    int otherNumber = 0;

    for (int i = 0; i < numbersMaxLength; ++i)
    {
        numbers[i] = 0;
    }

    printf("Insert your number\n");
    scanf("%d", &number);

    while (number > 0)
    {
        numbers[numbersLength] = number % 10;
        number = number / 10;
        ++numbersLength;
    }

    sort(numbers, numbersLength);
    int index = 0;
    for (index = 0; numbers[index] == 0; ++index)
    {
    }
    if (numbers[0] == 0)
    {
        numbers[0] = numbers[index];
        numbers[index] = 0;
    }
    for (int i = 0; i < numbersLength; ++i)
    {
        otherNumber = otherNumber * 10 + numbers[i];
    }

    printf("Minimal number\n%d", otherNumber);
    return 0;
}
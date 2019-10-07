#include <stdio.h>
#include <stdbool.h>

const int numbersMaxLength = 50;

void qSort(int *numbers, int nose, int tail)
{
    int helper = 0;
    int indexOfElement = (nose + tail) / 2;
    int indexOfNose = nose - 1;
    int indexOfTail = tail + 1;

    if (nose >= tail)
    {
        return;
    }

    while (true)
    {
        do
        {
            ++indexOfNose;
        }
        while (numbers[indexOfNose] < numbers[indexOfElement]);

        do
        {
            --indexOfTail;
        }
        while (numbers[indexOfTail] > numbers[indexOfElement]);

        if (indexOfNose < indexOfTail)
        {
            helper = numbers[indexOfTail];
            numbers[indexOfTail] = numbers[indexOfNose];
            numbers[indexOfNose] = helper;

            if (indexOfElement == indexOfNose)
            {
                indexOfElement = indexOfTail;
                ++indexOfTail;
            }
            else if (indexOfElement == indexOfTail)
            {
                indexOfElement = indexOfNose;
                --indexOfNose;
            }
        }
        else
        {
            break;
        }
    }

    qSort(numbers, nose, indexOfElement - 1);
    qSort(numbers, indexOfElement + 1, tail);


    return;
}

int main()
{
    int numbers[numbersMaxLength];
    int numbersLength = 0;
    for (int i = 0; i < numbersMaxLength; ++i)
    {
        numbers[i] = -1;
    }

    printf("Insert length\n");
    scanf("%d", &numbersLength);
    printf("Insert your number\n");

    for (int i = 0; i < numbersLength; ++i)
    {
        scanf("%d", &numbers[i]);
    }

    qSort(numbers, 0, numbersLength - 1);


    int number1 = numbers[numbersLength - 1];
    int index = -1;
    for (int i = numbersLength - 2; i >= 0; --i)
    {
        if (numbers[i] == number1)
        {
            index = i;
            break;
        }
        number1 = numbers[i];
    }

    if (index != -1)
    {
        printf("\nMax number: %d", numbers[index]);
    }
    else
    {
        printf("\nMax number is not to be");
    }
    return 0;
}
#include <stdio.h>
#include <stdbool.h>

const int numbersMaxLength = 50;

void quickSort(int *numbers, int nose, int tail)
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

    quickSort(numbers, nose, indexOfElement - 1);
    quickSort(numbers, indexOfElement + 1, tail);

    return;
}

int main()
{
    int numbers[numbersMaxLength];
    int numbersLength = 0;
    for (int i = 0; i < numbersMaxLength; ++i)
    {
        numbers[i] = 0;
    }

    printf("Insert length\n");
    scanf("%d", &numbersLength);
    printf("Insert your numbers\n");

    for (int i = 0; i < numbersLength; ++i)
    {
        scanf("%d", &numbers[i]);
    }

    quickSort(numbers, 0, numbersLength - 1);

    int index = -1;
    for (int i = numbersLength - 2; i >= 0; --i)
    {
        if (numbers[i] == numbers[numbersLength - 1])
        {
            index = i;
            break;
        }
        numbers[numbersLength - 1] = numbers[i];
    }

    if (index != -1)
    {
        printf("\nMax number: %d", numbers[index]);
    }
    else
    {
        printf("\nMax number does not exist");
    }
    return 0;
}
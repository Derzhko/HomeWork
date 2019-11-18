#include <stdio.h>
#include <stdbool.h>


const int numbersMaxLength = 20;

void findingMaxElement(int parent, int numbers[], int numbersLength)
{
    bool isMax = false;
    while (!isMax)
    {
        int helper = numbers[parent];
        int firstSubsidiary = 2 * parent + 1;
        int secondSubsidiary = 2 * parent + 2;
        if (secondSubsidiary < numbersLength)
        {
            if (numbers[firstSubsidiary] > numbers[secondSubsidiary])
            {
                numbers[parent] = numbers[firstSubsidiary];
                numbers[firstSubsidiary] = helper;
                parent = firstSubsidiary;
            }
            else
            {
                numbers[parent] = numbers[secondSubsidiary];
                numbers[secondSubsidiary] = helper;
                parent = secondSubsidiary;
            }
        }
        else
        {
            numbers[parent] = numbers[firstSubsidiary];
            numbers[firstSubsidiary] = helper;
            parent = firstSubsidiary;
        }

        if (parent <= (numbersLength / 2 - 1))
        {
            if (numbers[firstSubsidiary] < numbers[parent])
            {
                if (secondSubsidiary < numbersLength)
                {
                    if (numbers[secondSubsidiary] < numbers[parent])
                    {
                        isMax = true;
                    }
                }
                else
                {
                    isMax = true;
                }
            }
        }
        else
        {
            isMax = true;
        }
    }
}

void heapsort(int numbers[], int numbersLength)
{

    if (numbersLength == 1)
    {
        return;
    }

    for (int i = numbersLength / 2 - 1; i >= 0; --i)
    {
        if (numbers[2 * i + 1] > numbers [i] || (2 * i + 2 < numbersLength && numbers[2 * i + 2] > numbers[i]))
        {
            findingMaxElement(i, numbers, numbersLength);
        }
    }
    int helper = numbers[0];
    numbers[0] = numbers[numbersLength - 1];
    numbers[numbersLength - 1] = helper;
    heapsort(numbers, numbersLength - 1);
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
    printf("Insert count of numbers\n");
    scanf("%d", &numbersLength);
    printf("Insert numbers\n");
    for (int i = 0; i < numbersLength; ++i)
    {
        scanf("%d", &numbers[i]);
    }
    heapsort(numbers, numbersLength);

    printf("Sorted numbers\n");
    for (int i = 0; i < numbersLength; ++i)
    {
        printf("%d ", numbers[i]);
    }
        return 0;
}
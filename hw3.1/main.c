#include <stdio.h>
#include <stdbool.h>


const int numbersMaxLength = 20;

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
            int index = i;
            bool isMax = false;
            while (!isMax)
            {
                int helper = numbers[index];
                if (2 * index + 2 < numbersLength)
                {
                    if (numbers[2 * index + 1] > numbers[2 * index + 2])
                    {
                        numbers[index] = numbers[2 * index + 1];
                        numbers[2 * index + 1] = helper;
                        index = 2 * index + 1;
                    }
                    else
                    {
                        numbers[index] = numbers[2 * index + 2];
                        numbers[2 * index + 2] = helper;
                        index = 2 * index + 2;
                    }
                }
                else
                {
                    numbers[index] = numbers[2 * index + 1];
                    numbers[2 * index + 1] = helper;
                    index = 2 * index + 1;
                }

                if (index <= (numbersLength / 2 - 1))
                {
                    if (numbers[2 * index + 1] < numbers[index])
                    {
                        if (2 * index + 2 < numbersLength)
                        {
                            if (numbers[2 * index + 2] < numbers[index])
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
#include <stdio.h>

const int maxLength = 30;

int main()
{
    char check = '/0';
    printf("Insert text\n");
    char set[maxLength];
    for (int i = 0; i < maxLength; ++i)
    {
        set[i] = '\0';
    }
    int size = 0;
    char value = '\0';
    int countOfWord = 0;
    int countOfLetter = 0;
    do
    {
        scanf("%c", &value);
        if (set[size - 1] != ' ' && value == ' ')
        {
            ++countOfWord;
        }
        if (value != ' ' && value != '\n')
        {
            ++countOfLetter;
        }
        set[size] = value;
        ++size;
    }
    while (value != '\n');
    ++countOfWord;
    int newSize = 0;
    printf("Insert your length\n");
    scanf("%d", &newSize);
    int countOfGap = countOfWord - 1;
    int countOfSpace = newSize - countOfLetter;
    int additiveSpace = countOfSpace / countOfGap;
    int remainderSpace = countOfSpace % countOfGap;
    char newSet[newSize];
    for (int i = 0; i < newSize; ++i)
    {
        newSet[i] = '\0';
    }
    int countOfAddSpace = 0;
    int index = 0;
    for (int i = 0; i < size; ++i)
    {
        if (set[i] != ' ' && set[i] != '\n')
        {
            newSet[index] = set[i];
            ++index;
        }
        else if (set[i] == ' ')
        {
            int countOfLocalSpace = 0;
            while (countOfLocalSpace < additiveSpace)
            {
                newSet[index + countOfLocalSpace] = ' ';
                ++countOfLocalSpace;
            }
            index += countOfLocalSpace;
            if (remainderSpace > 0)
            {
                newSet[index + countOfAddSpace] = ' ';
                ++index;
                --remainderSpace;
            }
            while (set[i + 1] == ' ')
            {
                ++i;
            }
        }
    }
    printf("Result set\n");
    for (int i = 0; i < newSize; ++i)
    {
        printf("%c", newSet[i]);
    }
    return 0;
}
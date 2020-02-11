#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int maxLength = 20;

bool isDigit(char digit)
{
    if (digit >= '0' && digit <= '9')
    {
        return true;
    }
    return false;
}

bool scanner (char* numberSet)
{
    int index = 0;
    int state = 0;

    while (true)
    {
        switch (state)
        {
            case 0:
            {
                if (numberSet[index] == '+' || numberSet[index] == '-')
                {
                    state = 1;
                    break;
                }
                if (isDigit(numberSet[index]))
                {
                    state = 1;
                    break;
                }
                return false;
            }

            case 1:
            {
                if (isDigit(numberSet[index]))
                {
                    break;
                }
                if (numberSet[index] == '.')
                {
                    state = 2;
                    break;
                }
                if (numberSet[index] == 'E')
                {
                    state = 3;
                    break;
                }
                if (numberSet[index] == '\0')
                {
                    return true;
                }
                return false;
            }

            case 2:
            {
                if (isDigit(numberSet[index]))
                {
                    break;
                }
                if (numberSet[index] == 'E')
                {
                    state = 3;
                    break;
                }
                if (numberSet[index] == '\0')
                {
                    return true;
                }
                return false;
            }

            case 3:
            {
                if (isDigit(numberSet[index]))
                {
                    state = 4;
                    break;
                }
                if (numberSet[index] == '+' || numberSet[index] == '-')
                {
                    state = 4;
                    break;
                }
                return false;
            }

            case 4:
            {
                if (isDigit(numberSet[index]))
                {
                    break;
                }
                if (numberSet[index] == '\0')
                {
                    return true;
                }
                return false;
            }
        }
        ++index;
    }
}

int main()
{
    char numberSet[maxLength];
    for (int i = 0; i < maxLength; ++i)
    {
        numberSet[i] = '\0';
    }
    printf("Insert real number\n");
    fgets(numberSet, maxLength, stdin);
    numberSet[strlen(numberSet) - 1] = '\0';
    if (scanner (numberSet))
    {
        printf("It valid string");
    }
    else
    {
        printf("It invalid string");
    }
    return 0;
}
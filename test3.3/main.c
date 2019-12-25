#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isName(char* set)
{
    int index = 0;
    int state = 0;
    while (true)
    {
        switch (state)
        {
            case 0:
            {
                if ((int)set[index] - (int)'0' >= 0 && (int)set[index] - (int)'0' <= 9)
                {
                    state = 1;
                    break;
                }
                return false;
            }
            case 1:
            {
                if ((int)set[index] - (int)'0' >= 0 && (int)set[index] - (int)'0' <= 9)
                {
                    state = 2;
                    break;
                }
                return false;
            }
            case 2:
            {
                if (set[index] == 'B' || set[index] == 'M' || set[index] == 'S')
                {
                    state = 3;
                    break;
                }
                return false;
            }
            case 3:
            {
                if ((int)set[index] - (int)'0' >= 1 && (int)set[index] - (int)'0' <= 9)
                {
                    state = 4;
                    break;
                }
                return false;
            }
            case 4:
            {
                if (set[index] == '0')
                {
                    state = 5;
                    break;
                }
                if (set[index] == '-')
                {
                    state = 6;
                    break;
                }
                return false;
            }
            case 5:
            {
                if (set[index] == '-')
                {
                    state = 6;
                    break;
                }
                return false;
            }
            case 6:
            {
                if (set[index] == 'm')
                {
                    state = 7;
                    break;
                }
                return false;
            }
            case 7:
            {
                if (set[index] == 'm')
                {
                    state = 8;
                    break;
                }
                return false;
            }
            case 8:
            {
                if (set[index] == '\0')
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
    int stringLength = 9;
    char* set = malloc(sizeof(char) * stringLength);
    for (int i = 0; i < stringLength; ++i)
    {
        set[i] = '\0';
    }
    printf("Enter group name\n");
    fgets(set, stringLength, stdin);
    printf(isName(set) ? "Yes, this is the name of the mathmech's group" : "No, this is not the name of the mathmech's group");
    return 0;
}
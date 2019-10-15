#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int stringMaxLength = 15;
const int arrayLength = 26;

int main()
{
    bool isPossible = true;
    char string[stringMaxLength];
    char subString[stringMaxLength];
    int charCounter[arrayLength];
    for (int i = 0; i < stringMaxLength; ++i)
    {
        string[i] = '\0';
        subString[i] = '\0';
    }
    for (int i = 0; i < arrayLength; ++i)
    {
        charCounter[i] = 0;
    }
    printf("Insert first string\n");
    scanf("%s", string);
    printf("Insert second string\n");
    scanf("%s", subString);
    const int stringLength = strlen(string);
    const int subStringLength = strlen(subString);

    for (int i = 0; i < stringLength; ++i)
    {
        ++charCounter[string[i] - 'a'];
    }

    for (int i = 0; i < subStringLength; ++i)
    {
        if (charCounter[subString[i] - 'a'] != 0)
        {
            --charCounter[subString[i] - 'a'];
        }
        else
        {
            isPossible = false;
        }
    }

    if (isPossible)
    {
        printf("Is possible");
    }
    else
    {
        printf("Is impossible");
    }

    return 0;
}
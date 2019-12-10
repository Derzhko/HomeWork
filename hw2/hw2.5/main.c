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
    fgets(string, stringMaxLength, stdin);
    printf("Insert second string\n");
    fgets(subString, stringMaxLength, stdin);
    const int stringLength = strlen(string);
    const int subStringLength = strlen(subString);

    for (int i = 0; i < stringLength; ++i)
    {
        ++charCounter[string[i] - 'a'];
    }

    for (int i = 0; i < subStringLength; ++i)
    {
            --charCounter[subString[i] - 'a'];
    }
    for (int i = 0; i < arrayLength; ++i)
    {
        if (charCounter[i] != 0)
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
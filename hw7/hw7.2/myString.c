#include "myString.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct String
{
    char* set;
};

String* createString(char* set)
{
    String* newString = malloc(sizeof(String));
    newString->set = malloc(sizeof(char) * strlen(set));
    newString->set = set;
    return newString;
}

void deleteString(String* string)
{
    free(string);
}

String* clone(String* string)
{
    String* cloneString = malloc(sizeof(String));
    cloneString = malloc(sizeof(char) * strlen(string->set));
    for (int i = 0; i < strlen(string->set); ++i)
    {
        cloneString->set[i] = string->set[i];
    }
    return cloneString;
}

String* concat(String* string1, String* string2)
{
    String* resultString = malloc(sizeof(String));
    int lengthOfString1 = strlen(string1->set);
    int lengthOfString2 = strlen(string2->set);
    int resultLength = lengthOfString1 + lengthOfString2;
    resultString->set = malloc(sizeof(char) * resultLength);
    for (int i = 0; i < resultLength; ++i)
    {
        if (i < lengthOfString1)
        {
            resultString->set[i] = string1->set[i];
        }
        else
        {
            resultString->set[i] = string2->set[i - lengthOfString2];
        }
    }
    deleteString(string1);
    deleteString(string2);
    return resultString;
}

bool isEqual(String* string1, String* string2)
{
    int lengthOfString1 = strlen(string1->set);
    int lengthOfString2 = strlen(string2->set);
    int maxLength = lengthOfString1 > lengthOfString2 ? lengthOfString1 : lengthOfString2;
    for (int i = 0; i < maxLength; i++)
    {
        if (string1->set[i] != string2->set[i])
        {
            return false;
        }
    }
    return true;
}

int lengthOfString(String* string)
{
    if (string == NULL)
    {
        return 0;
    }
    int length = 0;
    while (string->set[length] != '\0')
    {
        ++length;
    }
    return length;
}

bool isEmpty(String* string)
{
    if (string == NULL)
    {
        return true;
    }
    if (string->set[0] == '\0')
    {
        return true;
    }
    return false;
}


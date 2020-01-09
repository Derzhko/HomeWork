#include "myString.h"
#include <stdlib.h>
#include <stdbool.h>

struct String
{
    char* set;
    int lengthOfSet;
};

String* createString(char* set)
{
    String* newString = malloc(sizeof(String));
    newString->lengthOfSet = 0;
    while (set[newString->lengthOfSet] != '\0')
    {
        ++(newString->lengthOfSet);
    }
    newString->set = malloc(sizeof(char) * (newString->lengthOfSet + 1));
    for (int i = 0; i <= newString->lengthOfSet; ++i)
    {
        newString->set[i] = set[i];
    }
    return newString;
}

void deleteString(String* string)
{
    free(string->set);
    free(string);
}

int lengthOfString(String* string)
{
    return string->lengthOfSet;
}

String* clone(String* string)
{
    String* cloneString = malloc(sizeof(String));
    cloneString->set = malloc(sizeof(char) * lengthOfString(string));
    cloneString->lengthOfSet = lengthOfString(string);
    for (int i = 0; i <= lengthOfString(string); ++i)
    {
        cloneString->set[i] = string->set[i];
    }
    return cloneString;
}

String* concat(String* string1, String* string2)
{
    String* resultString = malloc(sizeof(String));
    int lengthOfString1 = lengthOfString(string1);
    int lengthOfString2 = lengthOfString(string2);
    int resultLength = lengthOfString1 + lengthOfString2;
    resultString->set = malloc(sizeof(char) * resultLength);
    resultString->lengthOfSet = resultLength;
    for (int i = 0; i <= resultLength; ++i)
    {
        resultString->set[i] = '\0';
    }
    for (int i = 0; i < resultLength; ++i)
    {
        if (i < lengthOfString1)
        {
            resultString->set[i] = string1->set[i];
        }
        else
        {
            resultString->set[i] = string2->set[i - lengthOfString1];
        }
    }
    deleteString(string1);
    return resultString;
}

bool isEqual(String* string1, String* string2)
{
    int lengthOfString1 = lengthOfString(string1);
    int lengthOfString2 = lengthOfString(string2);
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

String* cutOut(String* inputString, int headIndex, int taleIndex)
{
    String* outputString = malloc(sizeof(String));
    int lengthOfInputString = lengthOfString(inputString);
    for (int i = 0; i <= taleIndex; ++i)
    {
        if (i >= headIndex && i <= taleIndex)
        {
            outputString->set[i - headIndex] = inputString->set[i];
        }
    }
    return outputString;
}

char* getS(String* string)
{
    return string->set;
}
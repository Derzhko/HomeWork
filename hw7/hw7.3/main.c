#include <stdio.h>
#include <stdlib.h>
#include "myString.h"

typedef struct Word Word;

int hashSize = 16;
Word* hashTable;
int countOfElement = 0;

struct Word
{
    String* setOfWord;
    int frequency;
    int try;
};

int hashFunction(char *value)
{
    int result = 0;
    for (int i = 0; value[i] != '\0'; ++i)
    {
        result = (result + value[i]) % hashSize;
    }
    return result;
}

void fillInNewHashTable(String* value, int helperFrequency)
{
    int index = hashFunction(getS(value));
    int interval = 1;
    for (int i = 0; i < hashSize; ++i)
    {
        if (hashTable[index % hashSize].frequency == 0)
        {
            hashTable[index % hashSize].setOfWord = clone(value);
            hashTable[index % hashSize].frequency = helperFrequency;
            hashTable[index % hashSize].try = i + 1;
            ++countOfElement;
            return;
        }
        else if (isEqual(hashTable[index % hashSize].setOfWord, value))
        {
            ++hashTable[index % hashSize].frequency;
            return;
        }
        interval += i;
        index += interval;
    }
}

Word* createNewHashTable()
{
    Word* helperHashTable = malloc(sizeof(Word) * hashSize);
    for (int i = 0; i < hashSize; ++i)
    {
        helperHashTable[i] = hashTable[i];
    }
    free(hashTable);
    hashSize *= 2;
    hashTable = malloc(sizeof(Word) * hashSize);
    for (int i = 0; i < hashSize; ++i)
    {
        hashTable[i].frequency = 0;
        hashTable[i].try = 0;
    }
    for (int i = 0; i < hashSize / 2; ++i)
    {
        if (helperHashTable[i].frequency != 0)
        {
            fillInNewHashTable(helperHashTable[i].setOfWord, helperHashTable[i].frequency);
        }
    }
    return hashTable;
}

void add(String* value)
{
    double loadFactor = (double)countOfElement / hashSize;
    if (loadFactor > 0.9)
    {
        countOfElement = 0;
        hashTable = createNewHashTable();
    }
    int index = hashFunction(getS(value));
    int interval = 1;
    for (int i = 0; i < hashSize; ++i)
    {
        if (hashTable[index % hashSize].frequency == 0)
        {
            hashTable[index % hashSize].setOfWord = clone(value);
            hashTable[index % hashSize].frequency = 1;
            hashTable[index % hashSize].try = i + 1;
            ++countOfElement;
            return;
        }
        else if (isEqual(hashTable[index % hashSize].setOfWord, value))
        {
            ++hashTable[index % hashSize].frequency;
            return;
        }
        interval += i;
        index += interval;
    }
}

double averageSearch()
{
    double allTry = 0;
    for (int i = 0; i < hashSize; ++i)
    {
        allTry += hashTable[i].try;
    }
    return allTry / countOfElement;
}

void findMaximumTry()
{
    int maximumTry = 0;
    int index = 0;
    for (int i = 0; i < hashSize; ++i)
    {
        if (hashTable[i].try > maximumTry)
        {
            maximumTry = hashTable[i].try;
            index = i;
        }
    }
    printf("maximum number of try: %d  key: %s\n", hashTable[index].try, getS(hashTable[index].setOfWord));
}

int main()
{
    hashTable = malloc(sizeof(Word) * hashSize);
    for (int i = 0; i < hashSize; ++i)
    {
        hashTable[i].frequency = 0;
        hashTable[i].try = 0;
    }
    FILE* file = fopen("../file.txt", "r");
    if (file == NULL)
    {
        printf("Error: file is not open");
        return 0;
    }
    char charInFile;
    String* string = NULL;
    do
    {
        charInFile = fgetc(file);
        if (charInFile != ' ' && charInFile != '\t' && charInFile != '\0' && charInFile != EOF && charInFile != '\n')
        {
            if (string == NULL)
            {
                string = createString("");
            }
            char* st2 = malloc(sizeof(char) * 2);
            st2[0] = charInFile;
            st2[1] = '\0';
            String* string2 = createString(st2);
            string = concat(string, string2);
            free(st2);
            deleteString(string2);
        }
        else if (string != NULL)
        {
            add(string);
            deleteString(string);
            string = NULL;
        }
    }
    while (charInFile != EOF);
    printf("load factor: %f\n", (double)countOfElement / hashSize);
    printf("average number of try: %f\n", averageSearch());
    findMaximumTry();
    printf("total number of words added: %d\n", countOfElement);
    printf("count of empty buckets: %d\n", hashSize - countOfElement);
    return 0;
}
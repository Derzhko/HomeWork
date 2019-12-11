#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include <string.h>
#include <stdlib.h>

const int maxLength = 20;

void addToList(List *list)
{
    char *name = malloc(sizeof(char) * maxLength);
    char *phone = malloc(sizeof(char) * maxLength);
    for (int i = 0; i < maxLength; ++i)
    {
        name[i] = '\0';
        phone[i] = '\0';
    }
    printf("Insert name\n");
    fgetc(stdin);
    fgets(name, maxLength, stdin);
    printf("Insert phone\n");
    fgets(phone, maxLength, stdin);
    name[strlen(name) - 1] = '\0';
    phone[strlen(phone) - 1] = '\0';
    add(list, name, phone);
}

void findPhone(List* list)
{
    char *name = malloc(sizeof(char) * maxLength);
    char *phone;
    for (int i = 0; i < maxLength; ++i)
    {
        name[i] = '\0';
    }
    printf("Insert name\n");
    fgetc(stdin);
    fgets(name, maxLength, stdin);
    name[strlen(name) - 1] = '\0';
    phone = findByName(list, name);
    if (phone != NULL)
    {
        printf("%s's phone number is %s\n", name, phone);
    }
    else
    {
        printf("Phone number is not found\n");
    }
}

void findName(List* list)
{
    char *phone = malloc(sizeof(char) * maxLength);
    char *name;
    for (int i = 0; i < maxLength; ++i)
    {
        phone[i] = '\0';
    }
    printf("Insert phone\n");
    fgetc(stdin);
    fgets(phone, maxLength, stdin);
    phone[strlen(phone) - 1] = '\0';
    name = findByPhone(list, phone);
    if (name != NULL)
    {
        printf("%s's phone number is %s\n", name, phone);
    }
    else
    {
        printf("Member is not found\n");
    }
}

int main()
{
    FILE *file;
    file = fopen("../phones.txt", "a+");
    if (file == NULL)
    {
        printf("File is close");
        return 0;
    }
    List *list = createList();
    fieldListByFile(file, list);
    while (true)
    {
        int value = 0;
        printf("0 - exit\n");
        printf("1 - add an entry (name and phone number)\n");
        printf("2 - find phone by name\n");
        printf("3 - find the name on the phone\n");
        printf("4 - save current data to a file\n");
        scanf("%d", &value);
        if (value < 0 && value > 4)
        {
            continue;
        }
        switch (value)
        {
            case 1 :
            {
                addToList(list);
                break;
            }
            case 2 :
            {
                findPhone(list);
                break;
            }
            case 3 :
            {
                findName(list);
                break;
            }
            case 4 :
            {
                fieldFileByList(file, list);
                break;
            }
            case 0 :
            {
                fclose(file);
                return 0;
            }
        }
    }
}
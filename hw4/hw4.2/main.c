#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.c"

void addToList(List *list)
{
    //fclose(file);
    //file = fopen("../phones.txt", "a+");
    char name[maxLength];
    char phone[maxLength];
    printf("Insert name\n");
    fgets(name, maxLength, stdin);
    printf("Insert phone\n");
    fgets(phone, maxLength, stdin);
    add(list, name, phone);
    //fputs(name, file);
    //fputc('\n', file);
    //fputs(phone, file);
    //fputc('\n', file);
}

void findPhone(FILE *file)
{
    fclose(file);
    file = fopen("../phones.txt", "a+");
    char name[maxLength];
    char phone[maxLength];
    printf("Insert name\n");
    scanf("%s", name);
    char helper[maxLength];
    fgets(helper, maxLength, file);
    while (strncmp(helper, name, strlen(helper) - 1) != 0 && !feof(file))
    {
        fgets(phone, maxLength, file);
        fgets(helper, maxLength, file);
    }
    if (strncmp(helper, name, strlen(helper) - 1) == 0)
    {
        fgets(phone, maxLength, file);
        printf("%s's phone number is %s\n", name, phone);
    }
    else
    {
        printf("Phone number is not found\n");
    }
}

void findTheName(FILE *file)
{
    fclose(file);
    file = fopen("../phones.txt", "a+");
    char name[maxLength];
    char phone[maxLength];
    printf("Insert phone\n");
    scanf("%s", phone);
    char helper[maxLength];
    fgets(name, maxLength, file);
    fgets(helper, maxLength, file);
    while (strncmp(helper, phone, strlen(helper) - 1) != 0 && !feof(file))
    {
        fgets(name, maxLength, file);
        fgets(helper, maxLength, file);
    }
    if (strncmp(helper, phone, strlen(helper) - 1) == 0)
    {
        char name2[maxLength];
        strncpy(name2, name, strlen(name) - 1);
        printf("%s's phone number is %s\n", name2, phone);
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
    char name[maxLength];
    char phone[maxLength];
    for (int i = 0; i < maxLength; ++i)
    {
        name[i] = '\0';
        phone[i] = '\0';
    }
    if (file == NULL)
    {
        printf("File is close");
        return 0;
    }
    List *list = createList();
    while (fgets(name, maxLength, file) != NULL)
    {
        fgets(phone, maxLength, file);
        add(list, name, phone);
    }

    return 0;
}
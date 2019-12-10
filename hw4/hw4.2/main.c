#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int maxLength = 50;

void add(FILE *file)
{
    fclose(file);
    file = fopen("../phones.txt", "a+");
    char name[maxLength];
    char phone[maxLength];
    printf("Insert name\n");
    scanf("%s", name);
    printf("Insert phone\n");
    scanf("%s", phone);
    fputs(name, file);
    fputc('\n', file);
    fputs(phone, file);
    fputc('\n', file);
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
    if (file == NULL)
    {
        printf("File is close");
        return 0;
    }
    while (true)
    {
        int value = 0;
        printf("0 - exit\n");
        printf("1 - add an entry (name and phone number)\n");
        printf("2 - find phone by name\n");
        printf("3 - find the name on the phone\n");
        printf("4 - save current data to a file\n");
        scanf("%d", &value);
        switch (value)
        {
            case 1 :
            {
                add(file);
                break;
            }
            case 2 :
            {
                findPhone(file);
                break;
            }
            case 3 :
            {
                findTheName(file);
                break;
            }
            case 4 :
            {
                fclose(file);
                file = fopen("../phones.txt", "a+");
                break;
            }
            case 0 :
            {
                fclose(file);
                return 0;
            }
        }
    }
    return 0;
}
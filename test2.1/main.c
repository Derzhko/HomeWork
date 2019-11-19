#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int maxLength = 100;

typedef struct Date Date;

bool isNumber(char num)
{
    return (int)num >= (int)'0' && (int)num <= (int)'9';
}

struct Date
{
    int day;
    int month;
    int year;
};

void findingAMinimumDate(Date *minimumDate, Date *otherDate)
{
    if (minimumDate->year > otherDate->year)
    {
        minimumDate->year = otherDate->year;
        minimumDate->month = otherDate->month;
        minimumDate->day = otherDate->day;
    }
    else if (minimumDate->year == otherDate->year)
    {
        if (minimumDate->month > otherDate->month)
        {
            minimumDate->month = otherDate->month;
            minimumDate->day = otherDate->day;
        }
        else if (minimumDate->month == otherDate->month)
        {
            if (minimumDate->day > otherDate->day)
            {
                minimumDate->day = otherDate->day;
            }
        }
    }
}


int main() {
    char set[maxLength];
    Date minimumDate;
    minimumDate.day = 31;
    minimumDate.month = 12;
    minimumDate.year = 9999;
    for (int i = 0; i < maxLength; ++i)
    {
        set[i] = '\0';
    }
    FILE *myFile = fopen("../test2.txt", "r");
    if (myFile == NULL)
    {
        printf("File is not open\n");
        return 0;
    }
    while (!feof(myFile))
    {
        fgets(set, maxLength, myFile);
        int stringLength = strlen(set);
        for (int i = 1; i < stringLength - 10; ++i)
        {
            if ((set[i - 1] == ' ') && (set[i + 10] == ' ' || set[i + 10] == '\n'))
            {
                if (isNumber(set[i]) && isNumber(set[i + 1]))
                {
                    if (set[i + 2] == '.')
                    {
                        if (isNumber(set[i + 3]) && isNumber(set[i + 4]))
                        {
                            if (set[i + 5] == '.')
                            {
                                if (isNumber(set[i + 6]) && isNumber(set[i + 7]) && isNumber(set[i + 8]) && isNumber(set[i + 9]))
                                {
                                    Date newDate;
                                    newDate.day = ((int) set[i] - (int) '0') * 10 + (int) set[i + 1] - (int) '0';
                                    newDate.month = ((int) set[i + 3] - (int) '0') * 10 + (int) set[i + 4] - (int) '0';
                                    newDate.year = ((int) set[i + 6] - (int) '0') * 1000 +
                                                   ((int) set[i + 7] - (int) '0') * 100 +
                                                   ((int) set[i + 8] - (int) '0') * 10 + (int) set[i + 9] - (int) '0';
                                    findingAMinimumDate(&minimumDate, &newDate);
                                    i += 10;
                                }
                            }
                        }
                    }
                }
            } else if (i - 1 == 0 && set[i + 9] == ' ')
            {
                --i;
                if (isNumber(set[i]) && isNumber(set[i + 1]))
                {
                    if (set[i + 2] == '.')
                    {
                        if (isNumber(set[i + 3]) && isNumber(set[i + 4]))
                        {
                            if (set[i + 5] == '.')
                            {
                                if (isNumber(set[i + 6]) && isNumber(set[i + 7]) && isNumber(set[i + 8]) && isNumber(set[i + 9]))
                                {
                                    Date newDate;
                                    newDate.day = ((int) set[i] - (int) '0') * 10 + (int) set[i + 1] - (int) '0';
                                    newDate.month = ((int) set[i + 3] - (int) '0') * 10 + (int) set[i + 4] - (int) '0';
                                    newDate.year = ((int) set[i + 6] - (int) '0') * 1000 +
                                                   ((int) set[i + 7] - (int) '0') * 100 +
                                                   ((int) set[i + 8] - (int) '0') * 10 + (int) set[i + 9] - (int) '0';
                                    findingAMinimumDate(&minimumDate, &newDate);
                                    i += 11;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(myFile);
    printf("Minimum Date is %d.%d.%d", minimumDate.day, minimumDate.month, minimumDate.year);
    return 0;
}
#ifndef HW4_2_LIST_H
#define HW4_2_LIST_H

#include <stdio.h>

typedef struct List List;
typedef struct ListElement ListElement;

void add (List *list, char name[], char phone[]);
List* createList();
char* findByPhone(List* list, char *phone);
char* findByName(List* list, char *name);
void fieldListByFile(FILE *file, List* list);
void fieldFileByList(FILE *file, List* list);
void deleteList(List* list);
#endif //HW4_2_LIST_H
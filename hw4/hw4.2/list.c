#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int length = 20;

struct ListElement
{
    char *name;
    char *phone;
    ListElement *next;
};

struct List
{
    ListElement *head;
    ListElement *tail;
    ListElement *pointElement;
};

List* createList()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->pointElement = NULL;
    return list;
}

ListElement* createListElement(char *name, char *phone)
{
    ListElement *listElement = malloc(sizeof(ListElement));
    listElement->phone = malloc(sizeof(char) * length);
    listElement->name = malloc(sizeof(char) * length);
    for (int i = 0; i < length; ++i)
    {
        listElement->name[i] = name[i];
        listElement->phone[i] = phone[i];
    }
    listElement->next = NULL;
    return listElement;
}

void add(List* list, char *name, char *phone)
{
    ListElement* newElement = createListElement(name, phone);
    if (list->head == NULL)
    {
        list->head = newElement;
        list->tail = newElement;
        return;
    }
    list->tail->next = newElement;
    list->tail = newElement;
}

char* findByPhone(List *list, char *phone)
{
    ListElement *element = list->head;
    while (element != NULL)
    {
        if (strcmp(element->phone, phone) == 0)
        {
            return element->name;
        }
        element = element->next;
    }
    return NULL;
}

char* findByName(List *list, char *name)
{
    ListElement *element = list->head;
    while (element != NULL)
    {
        if (strcmp(element->name, name) == 0)
        {
            return element->phone;
        }
        element = element->next;
    }
    return NULL;
}


void fieldListByFile(FILE *file, List *list)
{
    char *name = malloc(sizeof(char) * length);
    char *phone = malloc(sizeof(char) * length);
    for (int i = 0; i < length; ++i)
    {
        name[i] = '\0';
        phone[i] = '\0';
    }
    while (fgets(name, length, file) != NULL)
    {
        fgets(phone, length, file);
        name[strlen(name) - 1] = '\0';
        phone[strlen(phone) - 1] = '\0';
        add(list, name, phone);
    }
    list->pointElement = list->tail;
    free(name);
    free(phone);
}

void fieldFileByList(FILE *file, List *list)
{
    ListElement *element;
    if (list->pointElement == NULL)
    {
        element = list->head;
    }
    else
    {
        element = list->pointElement->next;
    }
    while (element != NULL)
    {
        fputc('\n', file);
        fputs(element->name, file);
        fputc('\n', file);
        fputs(element->phone, file);
        element = element->next;
    }
    list->pointElement = list->tail;
}

void deleteListElement(ListElement* element)
{
    if (element == NULL)
    {
        return;
    }
    deleteListElement(element->next);
    free(element->name);
    free(element->phone);
    free(element);
}

void deleteList(List* list)
{
    deleteListElement(list->head);
    free(list);
}
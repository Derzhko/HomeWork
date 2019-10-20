//
// Created by Администратор on 20.10.2019.
//

#include "CircularList.h"
#include <stdlib.h>

struct ListElement
{
    ListElement* next;
};

struct CircularList
{
    ListElement* first;
    ListElement* last;
};

CircularList* createList()
{
    CircularList* newList = malloc(sizeof(CircularList));
    newList->first = NULL;
    newList->last = NULL;
    return newList;
}

void add(CircularList* list)
{
    ListElement* newElement = malloc(sizeof(ListElement));
    if (list->first == NULL)
    {
        list->first = newElement;
        list->last = list->first;
    }
    else
    {
        list->last->next = newElement;
        newElement->next = list->first;
        list->last = newElement;
    }
}

void delete(int position, CircularList* list)
{
    ListElement* previousElement = list->first;
    ListElement* deletedElement = NULL;
    for (int i = 1; i < position - 1; ++i)
    {
        previousElement = previousElement->next;
    }
    deletedElement = previousElement->next;
    previousElement->next = deletedElement->next;
    free(deletedElement);
}
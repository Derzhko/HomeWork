#include "CircularList.h"
#include <stdlib.h>
#include <stdio.h>

struct ListElement
{
    int position;
    ListElement* next;
};

struct List
{
    ListElement* first;
    ListElement* last;
    int size;
};

List* createList(int size)
{
    List* newList = malloc(sizeof(List));
    newList->first = NULL;
    newList->last = NULL;
    newList->size = 0;
    for (int i = 0; i < size; ++i)
    {
        add(newList);
    }
    return newList;
}

int size(List* list)
{
    return list->size;
}

void add(List* list)
{
    ListElement* newElement = malloc(sizeof(ListElement));
    ++list->size;
    if (list->first == NULL)
    {
        newElement->position = 1;
        newElement->next = NULL;
        list->first = newElement;
        list->last = list->first;
    }
    else
    {
        ++list->last->position;
        newElement->position = list->last->position;
        list->last->next = newElement;
        newElement->next = list->first;
        list->last = newElement;
    }
}

void delete(int position, List* list)
{
    if (position == 1)
    {
        list->first = list->first->next;
        free(list->last->next);
        list->last->next = list->first;
    }
    else
    {
        ListElement *previousElement = list->first;
        ListElement *deletedElement = NULL;
        for (int i = 1; i < position - 1; ++i)
        {
            previousElement = previousElement->next;
        }
        if (position == size(list))
        {
            list->last = previousElement;
        }
        deletedElement = previousElement->next;
        previousElement->next = deletedElement->next;
        free(deletedElement);
    }
    --list->size;
}

int getValue(int position, List* list)
{
    ListElement* element = list->first;
    for (int i = 1; i < position; ++i)
    {
        element = element->next;
    }
    return element->position;
}

void deleteListElement(ListElement* element, ListElement* listLast)
{
    if (element == listLast)
    {
        free(element);
        return;
    }
    deleteListElement(element->next, listLast);
    free(element);
}

void deleteList(List* list)
{
    deleteListElement(list->first, list->last);
    free(list);
}
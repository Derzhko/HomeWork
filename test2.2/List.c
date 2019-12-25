#include "List.h"
#include <stdlib.h>
#include <stdio.h>

struct ListElement
{
    int value;
    ListElement* next;
};

struct List
{
    ListElement* first;
};

List* createList(int size)
{
    List* newList = malloc(sizeof(List));
    newList->first = NULL;
    return newList;
}

void add(int value, List* list)
{
    ListElement* newElement = malloc(sizeof(ListElement));
    newElement->next = NULL;
    newElement->value = value;
    if (list->first == NULL)
    {
        list->first = newElement;
    }
    else
    {
        ListElement* index = list->first;
        while (index->next != NULL)
        {
            index = index->next;
        }
        index->next = newElement;
    }
}

void delete(int position, List* list)
{
    if (position == 1)
    {
        ListElement* deletedElement = malloc(sizeof(ListElement));
        deletedElement = list->first;
        list->first = deletedElement->next;
        free(deletedElement);
    }
    else
    {
        ListElement *previousElement = list->first;
        ListElement *deletedElement = NULL;
        for (int i = 1; i < position - 1; ++i)
        {
            previousElement = previousElement->next;
        }
        deletedElement = previousElement->next;
        previousElement->next = deletedElement->next;
        free(deletedElement);
    }
}

int getValue(int position, List* list)
{
    ListElement* element = list->first;
    for (int i = 1; i < position; ++i)
    {
        element = element->next;
    }
    return element->value;
}

void implementationInsertionSort(ListElement* element)
{
    if (element->next == NULL)
    {
        return;
    }
    implementationInsertionSort(element->next);
    if (element->value > element->next->value)
    {
        int helper = element->value;
        element->value = element->next->value;
        element->next->value = helper;
        implementationInsertionSort(element->next);
    }
}

void insertionSort(List* list)
{
    if (list->first == NULL || list->first->next == NULL)
    {
        return;
    }
    implementationInsertionSort(list->first);
}

void printValue(List* list)
{
    printf("\n");
    ListElement* newElement = list->first;
    while(newElement != NULL)
    {
        printf("%d ", newElement->value);
        newElement = newElement->next;
    }
    printf("\n");
}

void deleteListElement(ListElement* element)
{
    if (element == NULL)
    {
        return;
    }
    deleteListElement(element->next);
    free(element);
}

void deleteList(List* list)
{
    deleteListElement(list->first);
    free(list);
}
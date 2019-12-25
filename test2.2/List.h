#ifndef LIST_H
#define LIST_H

typedef struct List List;
typedef struct ListElement ListElement;

List* createList();

void add(int value, List* list);

void delete(int position, List* list);

int size(List* list);

int getValue(int position, List* list);

void insertionSort(List* list);

void printValue(List* list);

void deleteList(List* list);

#endif //LIST_H

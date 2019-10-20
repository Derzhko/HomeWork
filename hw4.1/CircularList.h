//
// Created by Администратор on 20.10.2019.
//

#ifndef HW4_1_LIST_H
#define HW4_1_LIST_H

typedef struct List List;
typedef struct ListElement ListElement;

List* createList();

void add(List* list);

void delete(int position, List* list);

#endif //HW4_1_LIST_H

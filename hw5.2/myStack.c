//
// Created by alxderzhko on 01.10.2019.
//

#include <stdlib.h>
#include "stack.h"

struct StackElement
{
    int value;
    struct StackElement* next;
};

struct Stack
{
    struct StackElement* first;
};

Stack* createStack()
{
    Stack* stck1 = malloc(sizeof(Stack));
    stck1->first = NULL;
    return stck1;
}

bool isEmpty(Stack *stack)
{
    return stack->first == NULL;
}

bool push(int value, Stack *stack)
{
    StackElement *stackElement = malloc(sizeof(StackElement));
    stackElement->value = value;
    stackElement->next = stack->first;
    stack->first = stackElement;
    return true;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }

    int poppedValue = stack->first->value;
    stack->first = stack->first->next;
    return poppedValue;
}

int lookStackElement(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return (int)'\0';
    }
    return stack->first->value;
}
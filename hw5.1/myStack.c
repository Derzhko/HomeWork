#include <stdlib.h>
#include "stack.h"

struct StackElement
{
    char value;
    struct StackElement* next;
};

struct Stack
{
    struct StackElement* first;
};

Stack* createStack()
{
    Stack* stack = malloc(sizeof(Stack));
    stack->first = NULL;
    return stack;
}

bool isEmpty(Stack *stack)
{
    return stack->first == NULL;
}

bool push(char value, Stack *stack)
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
        return '\0';
    }

    int poppedValue = stack->first->value;
    stack->first = stack->first->next;
    free(stack->first);
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
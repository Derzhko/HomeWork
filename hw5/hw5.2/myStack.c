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
    Stack* stack = malloc(sizeof(Stack));
    stack->first = NULL;
    return stack;
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
        return '\0';
    }

    int poppedValue = stack->first->value;
    StackElement *poppedElement = stack->first;
    stack->first = stack->first->next;
    free(poppedElement);
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

void deleteStackElement(StackElement* element)
{
    if (element == NULL)
    {
        return;
    }
    deleteStackElement(element->next);
    free(element);
}

void deleteStack(Stack* stack)
{
    deleteStackElement(stack->first);
    free(stack);
}
#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

struct Stack;
struct StackElement;

typedef struct StackElement StackElement;
typedef struct Stack Stack;

struct Stack* createStack();
bool isEmpty(struct Stack* stack);
bool push(int value, struct Stack *stack);
int pop(struct Stack *stack);
int lookStackElement(struct Stack *stack);

#endif //STACK_H
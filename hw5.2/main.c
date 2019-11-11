#include <stdio.h>
#include "stack.h"
#include <string.h>

const int maxLength = 20;

int main() {
    char postfixSet[maxLength];
    for (int i = 0; i < maxLength; ++i)
    {
        postfixSet[i] = '\0';
    }
    Stack *myStack = createStack();
    printf("Insert your postfix string\n");
    scanf("%s", postfixSet);
    int stringLength = strlen(postfixSet);
    for (int i = 0; i < stringLength; ++i)
    {
        switch (postfixSet[i])
        {
            case '+':
            {
                int secondOperand = pop(myStack);
                int firstOperand = pop(myStack);
                push(firstOperand + secondOperand, myStack);
                break;
            }
            case '-':
            {
                int secondOperand = pop(myStack);
                int firstOperand = pop(myStack);
                push(firstOperand - secondOperand, myStack);
                break;
            }
            case '*':
            {
                int secondOperand = pop(myStack);
                int firstOperand = pop(myStack);
                push(firstOperand * secondOperand, myStack);
                break;
            }
            case '/':
            {
                int secondOperand = pop(myStack);
                int firstOperand = pop(myStack);
                push((int)(firstOperand / secondOperand), myStack);
                break;
            }
            default :
            {
                push(postfixSet[i] - (int)'0', myStack);
                break;
            }
        }
    }
    printf("Result = %d", pop(myStack));
    return 0;
}
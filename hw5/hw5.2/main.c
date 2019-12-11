#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <stdbool.h>

const int maxLength = 20;

bool isDigit(char number)
{
    return number >= '0' && number <= '9';
}

void toCount(int firstOperand, int secondOperand, char operation, Stack *myStack)
{
    switch (operation)
    {
        case '+':
        {
            push(firstOperand + secondOperand, myStack);
            break;
        }
        case '-':
        {
            push(firstOperand - secondOperand, myStack);
            break;
        }
        case '*':
        {
            push(firstOperand * secondOperand, myStack);
            break;
        }
        case '/':
        {
            push(firstOperand / secondOperand, myStack);
            break;
        }
    }
}

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
        if (isDigit(postfixSet[i]))
        {
            push(postfixSet[i] - (int)'0', myStack);
        }
        else
        {
            int secondOperand = pop(myStack);
            int firstOperand = pop(myStack);
            toCount(firstOperand, secondOperand, postfixSet[i], myStack);
        }
    }
    printf("Result = %d", pop(myStack));
    return 0;
}
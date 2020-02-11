#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <stdbool.h>

const int maxLength = 20;

bool isDigit(char number)
{
    return number >= '0' && number <= '9';
}

bool isValidString(char* postfixSet, int stringLength)
{
    int countOfDigit = 0;
    int countOfOperation = 0;
    for (int i = 0; i < stringLength; ++i)
    {
        if (isDigit(postfixSet[i]))
        {
            ++countOfDigit;
        }
        else
        {
            ++countOfOperation;
        }
    }
    return countOfDigit - 1 == countOfOperation;
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

int main()
{
    char postfixSet[maxLength];
    for (int i = 0; i < maxLength; ++i)
    {
        postfixSet[i] = '\0';
    }
    Stack *myStack = createStack();
    printf("Insert your postfix string\n");
    fgets(postfixSet, maxLength, stdin);
    postfixSet[strlen(postfixSet) - 1] = '\0';
    int stringLength = strlen(postfixSet);
    if (!isValidString(postfixSet, stringLength))
    {
        printf("Error: the string is invalid");
        deleteStack(myStack);
        return 0;
    }
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
    deleteStack(myStack);
    return 0;
}
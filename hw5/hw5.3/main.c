#include <stdio.h>
#include <string.h>
#include "stack.h"

const int maxLength = 20;

void addToPostfixSet(char postfixSet[], char value, int *stringTale)
{
    postfixSet[*stringTale] = value;
    ++*stringTale;
}

void conversionToPostfix(char infixSet[], char postfixSet[])
{
    Stack *myStack = createStack();
    int stringLength = strlen(infixSet);
    int stringTale = 0;
    for (int i = 0; i < stringLength; ++i)
    {
        switch (infixSet[i])
        {
            case '(':
            {
                push((int)'(', myStack);
                break;
            }
            case ')':
            {
                while ((char)lookStackElement(myStack) != '(')
                {
                    addToPostfixSet(postfixSet, (char)pop(myStack), &stringTale);
                }
                pop(myStack);
                break;
            }
            case '+':
            {
                if (!isEmpty(myStack) && (char)lookStackElement(myStack) != '(')
                {
                    addToPostfixSet(postfixSet, (char)pop(myStack), &stringTale);
                }
                push((int)'+', myStack);
                break;
            }
            case '-':
            {
                if (!isEmpty(myStack) && (char)lookStackElement(myStack) != '(')
                {
                    addToPostfixSet(postfixSet, (char)pop(myStack), &stringTale);
                }
                push((int)'-', myStack);
                break;
            }
            case '*':
            {
                if ((char)lookStackElement(myStack) == '*' || (char)lookStackElement(myStack) == '/')
                {
                    addToPostfixSet(postfixSet, (char)pop(myStack), &stringTale);
                }
                push((int)'*', myStack);
                break;
            }
            case '/':
            {
                if ((char)lookStackElement(myStack) == '*' || (char)lookStackElement(myStack) == '/')
                {
                    addToPostfixSet(postfixSet, (char)pop(myStack), &stringTale);
                }
                push((int)'/', myStack);
                break;
            }
            case ' ':
            {
                break;
            }
            default:
            {
                addToPostfixSet(postfixSet, infixSet[i], &stringTale);
                break;
            }
        }
    }
    while (!isEmpty(myStack))
    {
        addToPostfixSet(postfixSet, (char)pop(myStack), &stringTale);
    }

}

int evaluator(char postfixSet[])
{
    Stack *myStack = createStack();
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
    return pop(myStack);
}

int main() {
    char infixSet[maxLength];
    char postfixSet[maxLength];
    for (int i = 0; i < maxLength; ++i)
    {
        infixSet[i] = '\0';
        postfixSet[i] = '\0';
    }
    printf("Insert your infix string\n");
    scanf("%s", infixSet);
    conversionToPostfix(infixSet, postfixSet);
    printf("Result = %d", evaluator(postfixSet));
    return 0;
}
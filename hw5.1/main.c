#include <stdio.h>
#include "stack.h"
#include <string.h>

const int maxLength = 20;

void addToPostfixSet(char postfixSet[], char value, int *stringTale)
{
    postfixSet[*stringTale] = value;
    ++*stringTale;
}

int main() {
    char infixSet[maxLength];
    char postfixSet[maxLength];
    Stack *myStack = createStack();
    for (int i = 0; i < maxLength; ++i)
    {
        infixSet[i] = '\0';
        postfixSet[i] = '\0';
    }
    printf("Insert your infix string\n");
    scanf("%s", infixSet);
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
    printf("Postfix string %s", postfixSet);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

long factorial(long number)
{
    if (number == 0)
    {
        return 1;
    }
    number *= factorial(number - 1);
    return number;
}

int findingCatalansNumber(int order)
{
    long factorialOfOrder = factorial(order);
    int number = (factorial(2 * order) / factorialOfOrder) / factorialOfOrder / (order + 1);
    return number;
}

int main()
{
    int order = 0;
    printf("Insert order\n");
    scanf("%d", &order);
    int catalansNumber = findingCatalansNumber(order);
    printf("Result Catalan's Number: %d", catalansNumber);
    return 0;
}
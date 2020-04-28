#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "complexNumber.h"

int main()
{
    ComplexNumber* myNumber1 = NULL;
    ComplexNumber* myNumber2 = NULL;
    int real = 0;
    int imaginary = 0;
    int number = 0;
    while (true)
    {
        printf("1: addition\n");
        printf("2: subtraction\n");
        printf("3: multiplication\n");
        printf("4: division\n");
        printf("0: exit\n");
        scanf("%d", &number);
        switch (number)
        {
            case 1:
            {
                printf("insert first complex number\n");
                scanf("%d %d", &real, &imaginary);
                myNumber1 = createNumber(real, imaginary);
                printf("insert second complex number\n");
                scanf("%d %d", &real, &imaginary);
                myNumber2 = createNumber(real, imaginary);
                ComplexNumber* sum = addition(myNumber1, myNumber2);
                printf("sum is %d+%di\n", getRealPart(sum), getImaginaryPart(sum));
                free(sum);
                free(myNumber1);
                free(myNumber2);
                break;
            }
            case 2:
            {
                printf("insert first complex number\n");
                scanf("%d %d", &real, &imaginary);
                myNumber1 = createNumber(real, imaginary);
                printf("insert second complex number\n");
                scanf("%d %d", &real, &imaginary);
                myNumber2 = createNumber(real, imaginary);
                ComplexNumber* difference = subtraction(myNumber1, myNumber2);
                printf("difference is %d+%di\n", getRealPart(difference), getImaginaryPart(difference));
                free(difference);
                free(myNumber1);
                free(myNumber2);
                break;
            }
            case 3:
            {
                printf("insert first complex number\n");
                scanf("%d %d", &real, &imaginary);
                myNumber1 = createNumber(real, imaginary);
                printf("insert second complex number\n");
                scanf("%d %d", &real, &imaginary);
                myNumber2 = createNumber(real, imaginary);
                ComplexNumber* result = multiplication(myNumber1, myNumber2);
                printf("result is %d+%di\n", getRealPart(result), getImaginaryPart(result));
                free(result);
                free(myNumber1);
                free(myNumber2);
                break;
            }
            case 4:
            {
                printf("insert first complex number\n");
                scanf("%d %d", &real, &imaginary);
                myNumber1 = createNumber(real, imaginary);
                printf("insert second complex number\n");
                scanf("%d %d", &real, &imaginary);
                myNumber2 = createNumber(real, imaginary);
                ComplexNumber* result = division(myNumber1, myNumber2);
                printf("result is %d+%di\n", getRealPart(result), getImaginaryPart(result));
                free(result);
                free(myNumber1);
                free(myNumber2);
                break;
            }
            case 0:
            {
                return 0;
            }
        }
    }
}
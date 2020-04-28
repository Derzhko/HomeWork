#include "complexNumber.h"
#include <stdlib.h>

struct ComplexNumber
{
    int real;
    int imaginary;
};

ComplexNumber* createNumber(int real, int imaginary)
{
    ComplexNumber* newNumber = malloc(sizeof(ComplexNumber));
    newNumber->real = real;
    newNumber->imaginary = imaginary;
    return newNumber;
}

int getRealPart(ComplexNumber* number)
{
    return number->real;
}

int getImaginaryPart(ComplexNumber* number)
{
    return number->imaginary;
}


ComplexNumber* addition(ComplexNumber* number1, ComplexNumber* number2)
{
    ComplexNumber* sum = createNumber(0, 0);
    sum->real = number1->real + number2->real;
    sum->imaginary = number1->imaginary + number2->imaginary;
    return sum;
}


ComplexNumber* subtraction(ComplexNumber* number1, ComplexNumber* number2)
{
    ComplexNumber* difference = createNumber(0, 0);
    difference->real = number1->real - number2->real;
    difference->imaginary = number1->imaginary - number2->imaginary;
    return difference;
}

ComplexNumber* multiplication(ComplexNumber* number1, ComplexNumber* number2)
{
    ComplexNumber* result = createNumber(0, 0);
    result->real = (number1->real) * (number2->real) - (number2->imaginary) * (number2->imaginary);
    result->imaginary = (number1->real) * (number2->imaginary) + (number1->imaginary * (number2->real));
    return result;
}

ComplexNumber* division(ComplexNumber* number1, ComplexNumber* number2)
{
    ComplexNumber* result = createNumber(0,0);
    int modul = (number2->real) * (number2->real) + (number2->imaginary) * (number2->imaginary);
    result->real = ((number1->real) * (number2->real) + (number2->imaginary) * (number2->imaginary)) / modul;
    result->imaginary = ((number1->imaginary) * (number2->real) - (number1->real) * (number2->imaginary)) / modul;
    return result;
}


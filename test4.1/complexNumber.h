#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

typedef struct ComplexNumber ComplexNumber;

ComplexNumber* createNumber(int real, int imaginary);
int getRealPart(ComplexNumber* number);
int getImaginaryPart(ComplexNumber* number);

ComplexNumber* addition(ComplexNumber* number1, ComplexNumber* number2);
ComplexNumber* subtraction(ComplexNumber* number1, ComplexNumber* number2);
ComplexNumber* multiplication(ComplexNumber* number1, ComplexNumber* number2);
ComplexNumber* division(ComplexNumber* number1, ComplexNumber* number2);


#endif //COMPLEXNUMBER_H

#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdbool.h>

typedef struct String String;

String* createString();
void deleteString(String* string);
int lengthOfString(String* string);
String* clone(String* string);
String* concat(String* string1, String* string2);
bool isEqual(String* string1, String* string2);
bool isEmpty(String* string);
String* cutOut(String* inputString, int headIndex, int taleIndex);
char* getS(String* string);

#endif //MYSTRING_H
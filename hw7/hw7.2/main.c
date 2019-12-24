#include <stdio.h>
#include "myString.h"

int main()
{
    String* string1 = createString("Hello");
    printf("%s\n",  getS(string1));
    String* string2 = createString(" World");
    string1 = concat(string1, string2);
    printf("%s\n", getS(string1));
    printf(isEmpty(string2) ? "empty" : "nonEmpty");
    deleteString(string2);
    string2 = createString("");
    printf(isEmpty(string2) ? "empty" : "nonEmpty");
    deleteString(string2);
    string2 = clone(string1);
    printf("%s\n", getS(string2));
    printf(isEqual(string1, string2) ? "true\n" : "false\n");
    deleteString(string2);
    string2 = cutOut(string1, 0, lengthOfString(string1) / 2);
    printf("%s\n", getS(string2));
    printf(isEqual(string1, string2) ? "true\n" : "false\n");
    deleteString(string1);
    deleteString(string2);
    return 0;
}
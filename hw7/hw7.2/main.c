#include <stdio.h>
#include "myString.h"

int main()
{
    String* string1 = createString("Hello");
    printf("%s\n",  getS(string1));
    String* string2 = createString(" World");
    printf("%s\n", concat(string1, string2));
    return 0;
}
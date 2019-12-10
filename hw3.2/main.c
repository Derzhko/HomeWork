#include <stdio.h>
#include <stdbool.h>

int main()
{

    FILE *Kojima = fopen("../kojimageniy.txt", "r");
    if (Kojima == NULL)
    {
        printf("File is not open");
        return 0;
    }
    int numberOfLines = 0;
    char charInFile = '\0';
    bool isFirstNonSpaceChar = false;
    do
    {
        charInFile = fgetc(Kojima);
        if (charInFile != '\0' && charInFile != '\t' && charInFile != ' ' && charInFile != '\n')
        {
            isFirstNonSpaceChar = true;
        }
        if (charInFile == '\n' && isFirstNonSpaceChar)
        {
            numberOfLines++;
            isFirstNonSpaceChar = false;
        }
    }
    while (charInFile != EOF);
    printf("number of non-empty lines in file: %d", numberOfLines);
    return 0;
}
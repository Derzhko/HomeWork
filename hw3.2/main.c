#include <stdio.h>
#include <stdbool.h>

const int maxLength = 120;

int main()
{

    FILE *Kojima = fopen("./kojimageniy.txt", "r");
    if (Kojima == NULL)
    {
        printf("File is not open");
        return 0;
    }
    int numberOfLines = 0;
    char line[maxLength];
    while (fgets(line, maxLength, Kojima) != NULL)
    {
        for (int i = 0; line[i] != '\n'; ++i)
        {
            if (line[i] != '\0' && line[i] != '\t' && line[i] != ' ' )
            {
                ++numberOfLines;
                break;
            }
        }
    }
    printf("number of non-empty lines in file: %d", numberOfLines);
    return 0;
}
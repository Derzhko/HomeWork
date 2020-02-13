#include <stdio.h>

int authorDefinition(int *adjacencyMatrix, int student)
{
    if (adjacencyMatrix[student - 1] == 1 || adjacencyMatrix[student - 1] == 2 || adjacencyMatrix[student - 1] == 3)
    {
        return adjacencyMatrix[student - 1];
    }
    if (adjacencyMatrix[student - 1] != -1)
    {
        adjacencyMatrix[student - 1] = authorDefinition(adjacencyMatrix, adjacencyMatrix[student - 1]);
        return adjacencyMatrix[student - 1];
    }
    return -1;
}

int main()
{
    int numbersOfStudents = 0;
    printf("Insert number of students\n");
    scanf("%d", &numbersOfStudents);
    int adjacencyMatrix[numbersOfStudents];
    for (int i = 0; i < numbersOfStudents; ++i)
    {
        adjacencyMatrix[i] = 0;
    }
    printf("Insert the number of student and the number of author\n");
    for (int i = numbersOfStudents; i > 0; --i)
    {
        int student = 0;
        int author = 0;
        scanf("%d %d", &student, &author);
        adjacencyMatrix[student - 1] = author;
    }
    for (int i = numbersOfStudents; i > 3; --i)
    {
        authorDefinition(adjacencyMatrix, i);
    }
    printf("Table of students and authors\n");
    for (int i = 0; i < numbersOfStudents; ++i)
    {
        printf("%d - %d\n", i + 1, adjacencyMatrix[i]);
    }
    return 0;
}
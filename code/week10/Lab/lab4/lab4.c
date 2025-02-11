#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personal
{
    char name[10];
    int age;
    char hobby[10];
} personal[100];

struct nameAge
{
    char name[10];
    int age;
} nameAge[100];

struct nameHobby
{
    char name[10];
    char hobby[10];
} nameHobby[100];

int main()
{
    FILE *file;
    int dataCount = 0;
    file = fopen("personal.txt", "r");
    if (file == NULL)
    {
        printf("Input File Could Not Be Opened.");
        exit(1);
    }
    else
    {
        int i = 0;
        while (fscanf(file, "%s %d %s", personal[i].name, &personal[i].age, personal[i].hobby) != EOF)
        {
            i++;
            dataCount++;
        }
        fclose(file);
    }

    for (int i = 0; i < dataCount; i++)
    {
        strcpy(nameAge[i].name, personal[i].name);
        nameAge[i].age = personal[i].age;
        strcpy(nameHobby[i].name, personal[i].name);
        strcpy(nameHobby[i].hobby, personal[i].hobby);
    }

    FILE *ageFile = fopen("age.txt", "w");
    FILE *hobbyFile = fopen("hobby.txt", "w");
    if (ageFile == NULL || hobbyFile == NULL)
    {
        printf("Input File Could Not Be Opened.");
        exit(1);
    }
    else
    {
        fprintf(ageFile, "Name   Age\n");
        fprintf(hobbyFile, "Name   Hobby\n");
        for (int i = 0; i < dataCount; i++)
        {
            fprintf(ageFile, "%-6s %d\n", nameAge[i].name, nameAge[i].age);
            fprintf(hobbyFile, "%-6s %s\n", nameHobby[i].name, nameHobby[i].hobby);
        }
        fclose(ageFile);
        fclose(hobbyFile);
    }
    return 0;
}

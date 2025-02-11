#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personal
{
    char name[10];
    int age;
    char hobby[10];
} personal[20];

void printData(FILE *file, int count, struct personal personal[]);
void groupByAge(int count, struct personal personal[]);
void groupByHobby(int count, struct personal personal[]);

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

    file = fopen("hobby.txt", "w");
    if (file == NULL)
    {
        printf("Output File Could Not Be Opened.");
        exit(1);
    }
    else
    {
        groupByHobby(dataCount, personal);
        printData(file, dataCount, personal);
        fclose(file);
    }

    file = fopen("age.txt", "w");
    if (file == NULL)
    {
        printf("Output File Could Not Be Opened.");
        exit(1);
    }
    else
    {
        groupByAge(dataCount, personal);
        printData(file, dataCount, personal);
        fclose(file);
    }
    return 0;
}

void printData(FILE *file, int count, struct personal personal[])
{
    fprintf(file, "Name      Age     Hobby");
    for (int j = 0; j < count && personal[j].age != 0; j++)
    {
        fprintf(file, "\n%-10s%-8d%-10s", personal[j].name, personal[j].age, personal[j].hobby);
    }
}

void groupByHobby(int count, struct personal personal[])
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (strcmp(personal[j].hobby, personal[j + 1].hobby) > 0)
            {
                struct personal temp = personal[j];
                personal[j] = personal[j + 1];
                personal[j + 1] = temp;
            }
        }
    }
}

void groupByAge(int count, struct personal personal[])
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (personal[j].age > personal[j + 1].age)
            {
                struct personal temp = personal[j];
                personal[j] = personal[j + 1];
                personal[j + 1] = temp;
            }
        }
    }
}
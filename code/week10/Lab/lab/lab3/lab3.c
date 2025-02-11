#include <stdio.h>
#include <stdlib.h>

struct personal
{
    char name[10];
    int age;
    char hobby[10];
} personal[20];

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

    // Decompose data by age.
    struct personal age1019[dataCount], age2029[dataCount], age3039[dataCount], age4049[dataCount];
    int cursor1019 = 0, cursor2029 = 0, cursor3039 = 0, cursor4049 = 0;

    for (int i = 0; i < dataCount; i++)
    {
        if (personal[i].age >= 10 && personal[i].age < 20)
        {
            age1019[cursor1019] = personal[i];
            cursor1019++;
        }
        else if (personal[i].age >= 20 && personal[i].age < 30)
        {
            age2029[cursor2029] = personal[i];
            cursor2029++;
        }
        else if (personal[i].age >= 30 && personal[i].age < 40)
        {
            age3039[cursor3039] = personal[i];
            cursor3039++;
        }
        else if (personal[i].age >= 40 && personal[i].age < 50)
        {
            age4049[cursor4049] = personal[i];
            cursor4049++;
        }
    }

    // Generate a struct arrary for each age range.
    file = fopen("output.txt", "w");
    if (file == NULL)
    {
        printf("Output File Could Not Be Opened.");
        exit(1);
    }
    else
    {
        fprintf(file, "Age from 10 to 19\n");
        fprintf(file, "-------------------\n");
        for (int i = 0; i < cursor1019; i++)
        {
            fprintf(file, "%-5s %-5d %s\n", age1019[i].name, age1019[i].age, age1019[i].hobby);
        }

        fprintf(file, "\nAge from 20 to 29\n");
        fprintf(file, "-------------------\n");
        for (int i = 0; i < cursor2029; i++)
        {
            fprintf(file, "%-5s %-5d %s\n", age2029[i].name, age2029[i].age, age2029[i].hobby);
        }

        fprintf(file, "\nAge from 30 to 39\n");
        fprintf(file, "-------------------\n");
        for (int i = 0; i < cursor3039; i++)
        {
            fprintf(file, "%-5s %-5d %s\n", age3039[i].name, age3039[i].age, age3039[i].hobby);
        }

        fprintf(file, "\nAge from 40 to 49\n");
        fprintf(file, "-------------------\n");
        for (int i = 0; i < cursor4049; i++)
        {
            fprintf(file, "%-5s %-5d %s\n", age4049[i].name, age4049[i].age, age4049[i].hobby);
        }

        fclose(file);
    }
    return 0;
}

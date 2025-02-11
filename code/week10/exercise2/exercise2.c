#include <stdio.h>
#include <stdlib.h>
struct CAR
{
    char name[20];
    int year;
    double price;
} car[4] = {
    {"Avante", 2007, 13000.00},
    {"Sonata", 2008, 18000.00},
    {"SM7", 2009, 22000.00},
    {"Equus", 2010, 35000.00}};

void main()
{
    FILE *file;
    file = fopen("cars.txt", "w");
    if (file == NULL)
    {
        printf("Output File Could Not Be Opened.");
        exit(1);
    }
    else
    {
        fprintf(file, "---------------------------------\n");
        fprintf(file, "|Name     |Year       |Price    |\n");
        fprintf(file, "---------------------------------\n");
        for (int i = 0; i < 4; i++)
        {
            fprintf(file, "|%-8s | %10d| %8.2f|\n", car[i].name, car[i].year, car[i].price);
        }
        fprintf(file, "---------------------------------\n");
        fclose(file);
    }

    file = fopen("cars.txt", "r");
    char line[100];
    if (file == NULL)
    {
        printf("Input File Could Not Be Opened.");
        exit(1);
    }
    else
    {
        while (fgets(line, sizeof(line), file))
        {
            printf("%s", line);
        }
    }
}
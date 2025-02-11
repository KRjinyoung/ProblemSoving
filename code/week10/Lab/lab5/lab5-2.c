#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct salary
{
    char name[20];
    int age;
    double salary;
} salary_v1[100], salary_v3[100];

int main()
{
    FILE *file_v1, *file_v3;
    int dataCount_v1 = 0, dataCount_v3 = 0;

    file_v1 = fopen("salary_v1.txt", "r");
    if (file_v1 == NULL)
    {
        printf("Input File Could Not Be Opened.\n");
        exit(1);
    }
    else
    {

        while (fscanf(file_v1, "%s %d %lf", salary_v1[dataCount_v1].name, &salary_v1[dataCount_v1].age, &salary_v1[dataCount_v1].salary) != EOF)
        {
            dataCount_v1++;
        }
        fclose(file_v1);
    }

    file_v3 = fopen("salary_v3.txt", "r");
    if (file_v3 == NULL)
    {
        printf("Input File Could Not Be Opened.\n");
        exit(1);
    }
    else
    {

        while (fscanf(file_v3, "%s %d %lf", salary_v3[dataCount_v3].name, &salary_v3[dataCount_v3].age, &salary_v3[dataCount_v3].salary) != EOF)
        {
            dataCount_v3++;
        }
        fclose(file_v3);
    }

    for (int i = 0; i < dataCount_v1; i++)
    {
        for (int j = 0; j < dataCount_v3; j++)
        {
            if (strcmp(salary_v1[i].name, salary_v3[j].name) == 0)
            {
                if (salary_v1[i].salary != salary_v3[j].salary)
                {
                    printf("%-6s %-5d %8.1lf  →  %8.1lf\n", salary_v1[i].name, salary_v1[i].age, salary_v1[i].salary, salary_v3[j].salary);
                }
            }
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct salary
{
    char name[20];
    int age;
    double salary;
} salary[100];

int main()
{
    FILE *file;
    int dataCount = 0;

    file = fopen("salary_v1.txt", "r");
    if (file == NULL)
    {
        printf("Input File Could Not Be Opened.\n");
        exit(1);
    }
    else
    {
        while (fscanf(file, "%s %d %lf", salary[dataCount].name, &salary[dataCount].age, &salary[dataCount].salary) != EOF)
        {
            dataCount++;
        }
        fclose(file);
    }

    file = fopen("salary_v2.txt", "w");
    if (file == NULL)
    {
        printf("Output File Could Not Be Opened.\n");
        exit(1);
    }
    else
    {
        for (int i = 0; i < dataCount; i++)
        {
            if (salary[i].age >= 40 && salary[i].age < 50)
            {
                salary[i].salary *= 1.1;
            }
            fprintf(file, "%12s %5d %12.1lf\n", salary[i].name, salary[i].age, salary[i].salary);
        }
        fclose(file);
    }

    file = fopen("salary_v2.txt", "r");
    if (file == NULL)
    {
        printf("Input File Could Not Be Opened.\n");
        exit(1);
    }
    else
    {
        int j = 0;
        while (fscanf(file, "%s %d %lf", salary[j].name, &salary[j].age, &salary[j].salary) != EOF)
        {
            j++;
        }
        fclose(file);
    }

    file = fopen("salary_v3.txt", "w");
    if (file == NULL)
    {
        printf("Output File Could Not Be Opened.\n");
        exit(1);
    }
    else
    {

        for (int i = 0; i < dataCount; i++)
        {
            if (salary[i].age >= 30 && salary[i].age < 40)
            {
                salary[i].salary *= 1.2;
            }
            fprintf(file, "%12s %5d %12.1lf\n", salary[i].name, salary[i].age, salary[i].salary);
        }
        fclose(file);
    }

    return 0;
}

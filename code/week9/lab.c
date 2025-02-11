/* 직원들의 정보를저장중
만약에 사용자로부터 입력받을때
constrain1 : RRN은 유니크해야함
constrain2 : bonus < salary> */
#include <stdio.h>
#include <stdlib.h>

struct emp
{
    char RRN[13];
    char name[20];
    float salary;
    float bonus;
} employee[20] = {
    {"123456789012", "Alice Smith", 55000.0, 5000.0},
    {"234567890123", "Bob Johnson", 60000.0, 4000.0},
    {"234567890123", "Carol Williams", 72000.0, 4500.0},
    {"456789012345", "David Brown", 50000.0, 300000.0},
    {"567890123456", "Eve Davis", 80000.0, 700000.0},
    {"678901234567", "Frank Miller", 56000.0, 3500.0},
    {"789012345678", "Grace Wilson", 48000.0, 2500.0},
    {"890123456789", "Hank Martinez", 75000.0, 6500.0},
    {"901234567890", "Ivy Taylor", 53000.0, 3200.0}},
  new_employee[20];

int isUnique(struct emp *employee); // bool

int main()
{
    for (int i = 0; i < 20; i++)
    {
        if (isUnique(&employee) && employee[i].bonus < employee[i].salary)
        {
            new_employee[i].RRN = employee[i].RRN;
            new_employee[i].name = employee[i].name;
            new_employee[i].salary = employee[i].salary;
            new_employee[i].bonus = employee[i].bonus;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        printf("%s %s %f %f", new_employee->RRN, new_employee->name, new_employee->salary, new_employee->bonus);
    }
}

int isUnique(struct emp *employee)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (i != j && employee[i].RRN == employee[j].RRN)
            {
                return 0;
            }
        }
    }
    return 1;
}
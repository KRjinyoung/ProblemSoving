#include <stdio.h>

struct emp
{
    char name[20];
    int age;
    float salary;
    char hobby[3][20];
} employee[300] = {
    {"Alice", 30, 50000.50, {"Reading", "Traveling", "Painting"}},
    {"Bob", 25, 45000.00, {"Cycling", "Cooking", "Hiking"}},
    {"Charlie", 28, 60000.75, {"Photography", "Gaming", "Music"}},
    {"Diana", 22, 52000.20, {"Dancing", "Yoga", "Gardening"}},
    {"Eve", 35, 70000.00, {"Writing", "Swimming", "Knitting"}}};

void sortBySalary(struct emp emp[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (emp[j].salary < emp[j + 1].salary)
            {
                struct emp temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int count = 5;
    sortBySalary(employee, count);
    printf("급여로 정렬된 직원 목록 (내림차순):\n");
    for (int i = 0; i < count; i++)
    {
        printf("이름: %s, 나이: %d, 급여: %.2f\n", employee[i].name, employee[i].age, employee[i].salary);
    }

    return 0;
}
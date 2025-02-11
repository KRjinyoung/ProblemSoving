#include <stdio.h>

struct Employee
{
    int id;
    char name[20];
    double payRate;
    double hoursWorked;
} E[6] = {
    {3462, "Jones", 4.62, 40.0},
    {6793, "Robbins", 5.83, 38.5},
    {6985, "Smith", 5.22, 45.5},
    {7834, "Swain", 6.89, 40.0},
    {8867, "Timmins", 6.43, 35.5},
    {9002, "Williams", 4.75, 42.0}};

int main()
{
    for (int i = 0; i < 6; i++)
    {                                                      // Changed from 5 to 6 to include all employees
        double totalPay = E[i].payRate * E[i].hoursWorked; // Calculate total pay
        printf("%d %s %.2lf %.2lf\n", E[i].id, E[i].name, totalPay, E[i].hoursWorked);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

struct
{
    char name[20];
    int age;
    float salary;
    char hobby[3][20];
} employee[300];

int main()
{
    employee = {
        {"Kim", 25, 200, "basketball"}
    }
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 1000

// Structure definition
struct Employee {
    char RRN[13];   // Unique RRN
    char name[20];
    float salary;
    float bonus;     // Constraint: bonus < salary
};

// Function to check RRN uniqueness
int is_unique_rrn(struct Employee employees[], int count, const char rrn[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].RRN, rrn) == 0) {
            return 0; // RRN is not unique
        }
    }
    return 1; // RRN is unique
}

// Function to check if bonus is less than salary
int is_bonus_valid(float salary, float bonus) {
    if (bonus < salary) {
        return 1; // Valid
    }
    else {
        return 0; // Invalid
    }
}

// Function to insert employee data
void insert_employee(struct Employee employees[], int* count, const char rrn[], const char name[], float salary, float bonus) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Cannot insert more employees. Limit reached.\n");
        return;
    }

    if (!is_unique_rrn(employees, *count, rrn)) {
        printf("Error: RRN '%s' is not unique.\n", rrn);
        return;
    }

    if (!is_bonus_valid(salary, bonus)) {
        printf("Error: Bonus (%.2f) must be less than Salary (%.2f).\n", bonus, salary);
        return;
    }

    // Insert the new employee
    strcpy(employees[*count].RRN, rrn);
    strcpy(employees[*count].name, name);
    employees[*count].salary = salary;
    employees[*count].bonus = bonus;
    (*count)++;

    printf("Employee '%s' added successfully.\n", name);
}

// Function to display employees
void display_employees(struct Employee employees[], int count) {
    printf("\nList of Employees:\n");
    for (int i = 0; i < count; i++) {
        printf("RRN: %s, Name: %s, Salary: %.2f, Bonus: %.2f\n",
            employees[i].RRN, employees[i].name, employees[i].salary, employees[i].bonus);
    }
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;

    // Sample valid data
    insert_employee(employees, &employee_count, "123456789012", "John Doe", 50000, 5000);
    insert_employee(employees, &employee_count, "987654321012", "Jane Smith", 60000, 3000);

    // Test constraint violation - duplicate RRN
    insert_employee(employees, &employee_count, "123456789012", "Sam Brown", 40000, 2000);

    // Test constraint violation - bonus >= salary
    insert_employee(employees, &employee_count, "456789012345", "Mike Davis", 30000, 40000);

    // Display all valid employees
    display_employees(employees, employee_count);

    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_DESIGNATION 50

typedef struct {
    int emp_id;
    char name[MAX_NAME];
    char designation[MAX_DESIGNATION];
    float basic_salary;
    float hra;
    float da;
} Employee;

void display_employee_info(Employee employees[], int n) {
    for (int i = 0; i < n; i++) {
        float gross_salary = employees[i].basic_salary + (employees[i].basic_salary * employees[i].hra / 100) + (employees[i].basic_salary * employees[i].da / 100);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basic_salary);
        printf("HRA %%: %.2f\n", employees[i].hra);
        printf("DA %%: %.2f\n", employees[i].da);
        printf("Gross Salary: %.2f\n\n", gross_salary);
    }
}

int main() {
    int n;
    printf("Enter no.of employees: ");
    scanf("%d", &n);

    Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("Enter employee %d information:\n", i + 1);
        scanf("%s", employees[i].name);
        scanf("%s", employees[i].designation);
        scanf("%f", &employees[i].basic_salary);
        scanf("%f", &employees[i].hra);
        scanf("%f", &employees[i].da);
    }

    printf("Employee Information:\n\n");
    display_employee_info(employees, n);

    return 0;
}
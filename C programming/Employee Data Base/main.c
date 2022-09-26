#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"
#include "Employee_Database.h"

#define STARTAT "\n\n\n\n\n\n\t\t\t"
#define TABS    "\n\t\t\t"

extern uint16 current_number_of_employees;
extern uint16 max_number_of_employees;

typedef enum
{
    MODIFY_MAX_NUMBER = 1,
    NEW,
    DISPLAY,
    DELETE,
    MODIFY_SALARY,
    DISPLAY_ALL,
    EXIT
} option_e;

void menu()
{
    system("cls");
    printf(STARTAT); printf("1. Modify the maximum number of employees.");
    printf(TABS); printf("2. Enter a new employee.");
    printf(TABS); printf("3. Display an employee.");
    printf(TABS); printf("4. Delete an employee.");
    printf(TABS); printf("5. Modify the salary of an employee.");
    printf(TABS); printf("6. Display all the employees.");
    printf(TABS); printf("7. Exit.");
    printf("\t\t\t\t\t"); printf("The number of employees %d of %d.", current_number_of_employees, max_number_of_employees);
    printf(TABS); printf("Enter a number from (1:7) > ");
}

void modifyMaxNumber(void)
{
    uint16 temp;
    system("cls");
    printf(STARTAT); printf("Take care the current number of employees is %u.", current_number_of_employees);
    printf(TABS); printf("Please enter a number greater than that : ");
    scanf("%hu", &temp);

    while(temp < current_number_of_employees)
    {
        system("cls");
        printf(STARTAT); printf("Please take care the current number of employees is %u.", current_number_of_employees);
        printf(TABS); printf("Please enter a number greater than that : ");
        scanf("%hu", &temp);
    }

    max_number_of_employees = temp;
    printf(TABS), printf("Updated.");
    printf(TABS), system("pause");
}

int main()
{
    int choice;
    uint8 id;
    uint16 temp;

    printf(STARTAT), printf("Enter the maximum number of the employees in the data base: ");
    scanf("%hu", &temp);

    while(temp < 0)
    {
        system("cls");
        printf(STARTAT), printf("Enter a positive number: ");
        scanf("%hu", &temp);
    }

    max_number_of_employees = temp;
    printf(TABS), printf("Updated.");
    printf(TABS), system("pause");


    while(1)
    {
        menu();
        scanf("%d", &choice);

        switch(choice)
        {
        case MODIFY_MAX_NUMBER:
            modifyMaxNumber();
            break;

        case NEW:
            system("cls");
            EMP_AddEmployee( );
            break;

        case DISPLAY:
            system("cls");
            printf(STARTAT); printf("Please enter the id of the employee: ");
            scanf("%hu", &id);
            system("cls");
            EMP_DisplayEmployee(id);
            break;

        case DELETE:
            system("cls");
            printf(STARTAT); printf("Please enter the id of the employee: ");
            scanf("%hu", &id);
            system("cls");
            EMP_DeleteEmployee ( id );
            break;

        case MODIFY_SALARY:
            system("cls");
            printf(STARTAT); printf("Please enter the id of the employee: ");
            scanf("%hu", &id);
            system("cls");
            EMP_modifySalary( id );
            break;

        case DISPLAY_ALL:
            print_all();
            break;

        case EXIT:
            return 0;

        default:
            return 0;
            break;

        }
    }
    return 0;
}

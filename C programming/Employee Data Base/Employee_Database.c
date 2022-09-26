/* Ahmed Mohammed Hussanein Ali
	Employee Database
	*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Employee_Database.h"
#include "Platform_Types.h"

uint16 max_number_of_employees;
uint16 current_number_of_employees = 0;
struct SEmployee *Ehead = NULL;

// Function to get the employee data from user.
void get_employee(struct SEmployee * employee)
{
	char temp[40];

    fflush(stdin), fflush(stdout);
	printf("Enter Employee ID: ");
	gets(temp);
	employee->EData.ID = atoi(temp);
	while(EMP_IsIdExist(employee->EData.ID))
    {
        printf("The id you entered is already exist.\n");
        printf("Please enter another one : ");
        gets(temp);
        employee->EData.ID = atoi(temp);
    }

	printf("Enter Employee Name: ");
	gets(employee->EData.name);

	printf("Enter Employee Age: ");
	gets(temp);
	employee->EData.age = atoi(temp);

	printf("Enter Employee Salary: ");
	gets(temp);
	employee->EData.base_salary = atoi(temp);

	printf("Enter Employee Bonus: ");
	gets(temp);
	employee->EData.bonus = atoi(temp);

	employee->EData.net_salary = (employee->EData.base_salary + employee->EData.bonus) * 0.82;
}

// Function to print a single employee.
void print_employee(struct SEmployee * employee)
{
	printf("Employee ID: %d\n", employee->EData.ID);
	printf("Employee Name: %s\n", employee->EData.name);
	printf("Employee Age: %d\n", employee->EData.age);
	printf("Employee Salary: %d\n", employee->EData.base_salary);
	printf("Employee Bonus: %d\n", employee->EData.bonus);
	printf("Employee Net Salary: %f\n", employee->EData.net_salary);
}

// Function to print all employee.
void print_all( void )
{
	struct SEmployee *temp = Ehead;
	while (temp)
	{
		printf("======================================\n");
		print_employee( temp );
		printf("======================================\n");
		temp = temp->Enext;
	}
}

void EMP_AddEmployee ( void )
{
	/* create new employee */
	struct SEmployee *newEmployee = (struct SEmployee *) malloc ( sizeof( struct SEmployee ) );
	struct SEmployee *navigator = Ehead;

	/* check if no space in list */
	if (current_number_of_employees == max_number_of_employees)
		printf("Sorry! there is no space in the list.\n");

	else
	{
		/* check if no space in heap */
		if (NULL == newEmployee)
			printf("Sorry! there is no space in memory.\n");

		else
		{
			/* if the list is empty */
			if (NULL == Ehead)
			{
				Ehead = newEmployee;
			}
			/* if the list is not empty */
			else
			{
				while (navigator->Enext != NULL)
					navigator = navigator->Enext;

				navigator->Enext = newEmployee;
			}
			current_number_of_employees++;
			get_employee(newEmployee);
			newEmployee->Enext = NULL;
			printf("The new employee is added successfully.\n");
		}
	}
}

bool EMP_IsListFull ( void )
{
    if( current_number_of_employees < max_number_of_employees )
        return FALSE;
    else if( NULL == Ehead && max_number_of_employees != 0)
        return FALSE;
    else
        return TRUE;
}

uint16 EMP_GetNumberOfEmployees ( void )
{
	return current_number_of_employees;
}

void EMP_DeleteEmployee ( uint8 id )
{
	struct SEmployee *selected = Ehead;
	struct SEmployee *previous = NULL;

	/* check if list is empty */
	if (NULL == Ehead)
	{
		printf("\nSorry! The Database is empty.\n");
	}
	/* if the list is not empty */
	else
	{
		while (NULL != selected)
		{
			if (selected->EData.ID == id)
			{
				if(NULL == previous)
				{
					Ehead = selected->Enext;
				}

				else
				{
					previous->Enext = selected->Enext;
				}

				free(selected);

				current_number_of_employees--;
				printf("\nThe employee has ID %d is deleted successfully.\n", id);
				break;
			}

			previous = selected;
			selected = selected->Enext;
		}
		if (NULL == selected)
        {
            printf("The ID you entered doesn't exist.\n");
        }
	}
}

void EMP_DisplayEmployee(uint8 id)
{
	struct SEmployee *selected = NULL;

	/* check if list is empty */
	if (NULL == Ehead)
	{
		printf("\nSorry! The Database is empty.\n");
	}
	/* if the list is not empty */
	else
	{
		while (NULL != selected)
		{
			if (selected->EData.ID == id)
			{
				print_employee(selected);
				break;
			}

			selected = selected->Enext;
		}
		if (NULL == selected)
        {
            printf("The ID you entered doesn't exist.\n");
        }
	}
}

void EMP_modifySalary(uint8 id)
{
    struct SEmployee *selected = NULL;

	/* check if list is empty */
	if (NULL == Ehead)
	{
		printf("\nSorry! The Database is empty.\n");
	}
	/* if the list is not empty */
	else
	{
		while (NULL != selected)
		{
			if (selected->EData.ID == id)
			{
				printf("Enter Employee New Salary: ");
				scanf("%u", selected->EData.base_salary);
				printf("Updated.");
				break;
			}

			selected = selected->Enext;
		}

		if (NULL == selected)
        {
            printf("The ID you entered doesn't exist.\n");
        }
	}
}

bool EMP_IsIdExist ( uint8 id )
{
	struct SEmployee *selected = NULL;

	/* check if list is empty */
	if (NULL == Ehead)
	{
		return FALSE;
	}
	/* if the list is not empty */
	else
	{
		while (NULL != selected)
		{
			if (selected->EData.ID == id)
			{
				return TRUE;
			}

			selected = selected->Enext;
		}
	}

    return FALSE;
}

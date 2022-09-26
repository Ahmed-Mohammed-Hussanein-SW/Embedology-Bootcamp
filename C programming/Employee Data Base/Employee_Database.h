/* Ahmed Mohammed Hussanein Ali
	Employee Database
	*/

#ifndef EMPLOYEE_DATABAASE_H_
#define EMPLOYEE_DATABAASE_H_

#include "Platform_Types.h"

/* types definintion */
typedef struct
{
	char name[40];
	uint8 ID;
	uint8 age;
	uint16 base_salary;
	uint16 bonus;
	float32 net_salary;
} SData;

struct SEmployee
{
	SData EData;
	struct SEmployee *Enext;
};



/* APIs */
void print_employee(struct SEmployee *);
void print_all( void );

void EMP_AddEmployee ( void );
bool EMP_IsListFull ( void );
uint16 EMP_GetNumberOfEmployees ( void );
void EMP_DeleteEmployee ( uint8 id );
void EMP_DisplayEmployee(uint8 id);
void EMP_modifySalary(uint8 id);
bool EMP_IsIdExist ( uint8 id );


#endif

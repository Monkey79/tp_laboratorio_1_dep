/*
 * utn_array_employees.h
 *
 *  Created on: 22 abr. 2020
 *  Author: mdangelo
 */

#ifndef UTN_CUSTOM_LIBS_UTN_ARRAY_EMPLOYEES_H_
#define UTN_CUSTOM_LIBS_UTN_ARRAY_EMPLOYEES_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;

int arrEmpLib_initEmployees(Employee *list,int len);
int arrEmpLib_addEmployee(Employee *list, int len, int id, char name[], char lastName[], float salary, int sector);
int arrEmpLib_updateEmployee(Employee *list, int len, Employee empl);
int arrEmpLib_findEmployeeById(Employee *list, int len, int id);
int arrEmpLib_removeEmployee(Employee *list, int len, int id);
int arrEmpLib_sortEmployees(Employee *list, int len, int order);
int arrEmpLib_printEmployees(Employee* list, int len);
void arrEmpLib_CalcSalaryAverage(Employee *employees, int len);
int arrEmpLib_canOperate(Employee *employees, int len);


#endif /* UTN_CUSTOM_LIBS_UTN_ARRAY_EMPLOYEES_H_ */

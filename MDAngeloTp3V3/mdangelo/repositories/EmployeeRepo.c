/*
 * EmployeeRepo.c
 * Created on: 14 jun. 2020
 * Author: mdangelo
 */
#include "../repositories/EmployeeRepo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "../utils/Commons.h"

#define NULL_POINTER_EXCEPTION "NULL Pointer Exception EmployeeRepo..\n"
#define NO_MEMORY_ERROR "No memory..\n"

Employee* er_newEmployee() {
	Employee *empAux = NULL;
	empAux = (Employee*) malloc(sizeof(Employee));
	if (empAux != NULL) {
		empAux->empId = 0;
		empAux->empWrkHrs = 0;
		empAux->emplSalary = 0;
	}
	return empAux;
}
Employee* er_newEmployeePrms(char *empIdStr, char *empNameStr, char *empWorkedHrs, char *empSalary) {
	Employee *empAux = NULL;
	empAux = (Employee*) malloc(sizeof(Employee));
	if (empAux != NULL) {
		empAux->empId = atoi(empIdStr);
		strncpy(empAux->empName, empNameStr, sizeof(empAux->empName));
		empAux->empWrkHrs = atoi(empWorkedHrs);
		empAux->emplSalary = atoi(empSalary);
	}else{
		printf(NO_MEMORY_ERROR);
	}
	return empAux;
}
Employee* er_newEmployeePrmsDataType(int empId, char *empNameStr,int empWorkedHrs, int empSalary){
	Employee *empAux = NULL;
	empAux = (Employee*) malloc(sizeof(Employee));
	if (empAux != NULL) {
		empAux->empId = empId;
		strncpy(empAux->empName, empNameStr, sizeof(empAux->empName));
		empAux->empWrkHrs = empWorkedHrs;
		empAux->emplSalary = empSalary;
	}else{
		printf(NO_MEMORY_ERROR);
	}
	return empAux;
}
int er_setEmpId(Employee *pEmp, int id) {
	int success = TRUE;
	if (pEmp != NULL)
		pEmp->empId = id;
	else {
		printf(NULL_POINTER_EXCEPTION);
		success = FALSE;
	}
	return success;
}
int er_getEmpId(Employee *pEmp, int *id) {
	int success = TRUE;
	if (pEmp != NULL)
		*id = pEmp->empId;
	else {
		printf(NULL_POINTER_EXCEPTION);
		success = FALSE;
	}
	return success;
}

int er_setEmpName(Employee *pEmp, char *empName) {
	int success = TRUE;
	if (pEmp != NULL)
		strncpy(pEmp->empName, empName, sizeof(pEmp->empName));
	else {
		printf(NULL_POINTER_EXCEPTION);
		success = FALSE;
	}
	return success;
}
int er_getEmpName(Employee *pEmp, char *empName) {
	int success = TRUE;
	if (pEmp != NULL)
		strncpy(empName, pEmp->empName, sizeof(pEmp->empName));
	else {
		printf(NULL_POINTER_EXCEPTION);
		success = FALSE;
	}
	return success;
}

int er_setEmpWrkHrs(Employee *pEmp, int workedHrs) {
	int success = TRUE;
	if (pEmp != NULL)
		pEmp->empWrkHrs = workedHrs;
	else {
		printf(NULL_POINTER_EXCEPTION);
		success = FALSE;
	}
	return success;
}
int er_getEmpWrkHrs(Employee *pEmp, int *workedHrs) {
	int success = TRUE;
	if (pEmp != NULL)
		*workedHrs = pEmp->empWrkHrs;
	else {
		printf(NULL_POINTER_EXCEPTION);
		success = FALSE;
	}
	return success;
}

int er_setEmpSalary(Employee *pEmp, int salary) {
	int success = TRUE;
	if (pEmp != NULL)
		pEmp->emplSalary = salary;
	else {
		printf(NULL_POINTER_EXCEPTION);
		success = FALSE;
	}
	return success;
}
int er_getEmpSalary(Employee *pEmp, int *salary) {
	int success = TRUE;
	if (pEmp != NULL)
		*salary = pEmp->empWrkHrs;
	else {
		printf(NULL_POINTER_EXCEPTION);
		success = FALSE;
	}
	return success;
}


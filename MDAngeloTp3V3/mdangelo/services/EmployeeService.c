/*
 * EmployeeService.c
 * Created on: 17 jun. 2020
 * Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "EmployeeService.h"

/***********Private Function***************/
int _isValidEmplId(int empId, LinkedList *linkedlist);

int es_createEmployee(LinkedList* linkedlist){
	int success = TRUE;
	int empId;
	char empName[128];
	int empSalary;
	int empWrkHrs;

	printf("-Ingrese nombre del empleado: ");
	__fpurge(stdin);
	scanf("%s",empName);
	do{
		printf("-Ingrese cant de horas trabajadas [0,+]: ");
		__fpurge(stdin);
		scanf("%d",&empWrkHrs);
	}while(empWrkHrs<0);
	do{
		printf("-Ingrese salario del empleado [0,+]; ");
		__fpurge(stdin);
		scanf("%d",&empSalary);
	}while(empSalary<0);

	Employee* lastEmp = ll_get(linkedlist, ll_len(linkedlist)-1);
	empId = lastEmp->empId+1;
	Employee* newEmp = er_newEmployeePrmsDataType(empId, empName, empWrkHrs, empSalary);

	return ll_add(linkedlist, newEmp);
}
int es_updateEmployee(LinkedList* linkedlist){
	int success =TRUE;
	int empId = 0;
	int result = 0;
	Employee *empUpd = NULL;
	do{
		printf("--De los siguientes empleados elija uno para actualizar [0=EXIT]--\n");
		es_showAllEmployees(linkedlist);
		scanf("%d",&empId);
		empUpd = es_getEmployeeById(empId, linkedlist);
	}while(empUpd==NULL && empId>0);
	if(empId>0){
		printf("-Ingrese nuevo nombre del empleado (antes %s): ",empUpd->empName);
		__fpurge(stdin);
		scanf("%s", empUpd->empName);
		printf("-Ingrese nueva cantidad de horas trabajadas (antes %d)",empUpd->empWrkHrs);
		__fpurge(stdin);
		scanf("%d",&empUpd->empWrkHrs);
		printf("-Ingrese nuevo salario (antes %d)",empUpd->emplSalary);
		__fpurge(stdin);
		scanf("%d",&empUpd->emplSalary);

		int index = ll_indexOf(linkedlist, empUpd);
		result=ll_set(linkedlist, index, empUpd);
		if(result==0)success = TRUE;
	}else{
		printf("--Actualizacion CANCELADA--\n");
		success = FALSE;
	}
	return success;
}
int es_deleteEmployee(LinkedList* linkedlist){
	int success =TRUE;
	int empId = 0;
	int result = 0;
	Employee *empDel = NULL;
	do{
		printf("--De los siguientes empleados elija uno para eliminar [0=EXIT]--\n");
		es_showAllEmployees(linkedlist);
		scanf("%d",&empId);
		empDel = es_getEmployeeById(empId, linkedlist);
	}while(empDel==NULL && empId>0);
	if(empDel!=NULL){
		int index = ll_indexOf(linkedlist, empDel);
		result=ll_remove(linkedlist, index);
		if(result==0)success = TRUE;
	}else{
		printf("--Eliminacion CANCELADA--\n");
		success = FALSE;
	}
	return success;
}

int es_sortEmployeesBySalary(Employee* currentEmp, Employee* nextEmp) {
	return (currentEmp->emplSalary>nextEmp->emplSalary);
}
int es_sortEmployeesByWrkdHrs(Employee* currentEmp, Employee* nextEmp) {
	return (currentEmp->empWrkHrs>nextEmp->empWrkHrs);
}

void es_showAllEmployees(LinkedList *linkedlist){
	Employee *empl = NULL;
	int len = ll_len(linkedlist);
	printf("*****************************Employees***********************************\n");
	printf("Emp_Id");
	printf("%20s","Emp_Name");
	printf("%20s","Emp_Wrkd-Hrs");
	printf("%20s\n","Emp_Salary");
	printf("*************************************************************************\n");
	for(int i=0;i<len;i++){
		empl = (Employee*)ll_get(linkedlist, i);
		printf("%d",empl->empId);
		printf("%24s", empl->empName);
		printf("%20d", empl->empWrkHrs);
		printf("%20d\n", empl->emplSalary);
	}
	printf("*************************************************************************\n");
}

Employee* es_getEmployeeById(int empId, LinkedList *linkedlist){
	int notValid=TRUE;
	int len = ll_len(linkedlist);
	Employee *emp = NULL;
	for(int i=0;i<len && notValid;i++){
		emp = (Employee*)ll_get(linkedlist, i);
		notValid = (emp->empId != empId);
	}
	return (!notValid)?emp:NULL;
}
/***********Private Function***************/

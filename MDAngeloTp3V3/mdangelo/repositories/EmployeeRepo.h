/*
 * EmployeeRepo.h
 * Created on: 14 jun. 2020
 * Author: mdangelo
 */

#ifndef MDANGELO_REPOSITORIES_EMPLOYEEREPO_H_
#define MDANGELO_REPOSITORIES_EMPLOYEEREPO_H_


#include "../entities/MainEntities.h"

Employee* er_newEmployee();
Employee* er_newEmployeePrms(char *empIdStr, char *empNameStr, char *empWorkedHrs, char *empSalary);
Employee* er_newEmployeePrmsDataType(int empId, char *empNameStr,int empWorkedHrs, int empSalary);

void er_deleteEmployee();

int er_setEmpId(Employee* pEmp,int id);
int er_getEmpId(Employee* pEmp,int* id);

int er_setEmpName(Employee* pEmp,char* empName);
int er_getEmpName(Employee* pEmp,char* empName);

int er_setEmpWrkHrs(Employee* pEmp,int workedHrs);
int er_getEmpWrkHrs(Employee* pEmp,int* workedHrs);

int er_setEmpSalary(Employee* pEmp,int salary);
int er_getEmpSalary(Employee* pEmp,int* salary);


#endif /* MDANGELO_REPOSITORIES_EMPLOYEEREPO_H_ */

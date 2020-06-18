/*
 * EmployeeService.c
 * Created on: 17 jun. 2020
 * Author: mdangelo
 */

#ifndef MDANGELO_SERVICES_EMPLOYEESERVICE_H_
#define MDANGELO_SERVICES_EMPLOYEESERVICE_H_

#include "../entities/MainEntities.h"
#include "../../LinkedList.h"
#include "../utils/Commons.h"
#include "../repositories/EmployeeRepo.h"

int es_createEmployee(LinkedList* linkedlist);
int es_updateEmployee(LinkedList* linkedlist);
int es_deleteEmployee(LinkedList* linkedlist);

void es_showAllEmployees(LinkedList *linkedlist);
int es_sortEmployeesBySalary(Employee* currentEmp, Employee* nextEmp);
int es_sortEmployeesByWrkdHrs(Employee* currentEmp, Employee* nextEmp);

Employee* es_getEmployeeById(int empId, LinkedList *linkedlist);

#endif /* MDANGELO_SERVICES_EMPLOYEESERVICE_H_ */

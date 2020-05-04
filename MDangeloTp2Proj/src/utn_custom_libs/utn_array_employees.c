/*
 * utn_array_employees.c
 *  Created on: 22 abr. 2020
 *  Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "utn_array_employees.h"

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0

#define ASC 1
#define DSC 0

int _getFreeEmplIndx(Employee *list, int len);
void _sortASC(Employee *list, int len);
void _sortDSC(Employee *list, int len);
void _swapEmployee(Employee *empl1, Employee *empl2);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int arrEmpLib_initEmployees(Employee *list, int len) {
	int iStatus = OK;
	for (int i = 0; i < len - 1; i++) {
		(*(list + i)).id = 0;
		(*(list + i)).isEmpty = TRUE;
	}
	return iStatus;
}

/** \brief add in a existing list of employees the values received as parameters
 in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 * free space] - (0) if Ok
 */
int arrEmpLib_addEmployee(Employee *list, int len, int id, char name[], char lastName[], float salary, int sector) {
	int status = OK;
	int i = _getFreeEmplIndx(list, len);

	Employee empl;
	empl.id = id;
	strcpy(empl.name, name);
	strcpy(empl.lastName, lastName);
	empl.salary = salary;
	empl.sector = sector;
	empl.isEmpty = FALSE;

	if (i != -1) {
		(*(list + i)) = empl;
	} else {
		printf("=Error: There is no more empty employee=\n");
		status = ERROR;
	}
	return status;
}

int arrEmpLib_updateEmployee(Employee *list, int len, Employee empl) {
	int status = OK;
	int i = arrEmpLib_findEmployeeById(list, len, empl.id);

	if(i!=-1){
		(*(list + i)) = empl;
	}else {
		printf("=Error: There is no employee whit id=%d=\n",empl.id);
		status = ERROR;
	}
	return status;
}

/** \brief find an Employee by Id en returns the index position in array.
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 * pointer received or employee not found]
 */
int arrEmpLib_findEmployeeById(Employee *list, int len, int id) {
	int bNotFind = TRUE;
	int i = 0;
	do {
		bNotFind = ((*(list + i)).id != id);
		i++;
	} while (bNotFind && i < len);
	return (bNotFind) ? -1 : (i - 1);
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 * find a employee] - (0) if Ok
 */
int arrEmpLib_removeEmployee(Employee *list, int len, int id) {
	int status = OK;
	int i = arrEmpLib_findEmployeeById(list, len, id);
	if (i != -1) {
		(*(list + i)).isEmpty = TRUE;
		(*(list + i)).id = 0;
	} else {
		printf("=Error: Not employee founded with id %d=\n", id);
		status = ERROR;
	}
	return status;
}

/** \brief Sort the elements in the array of employees, the argument order
 * indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int arrEmpLib_sortEmployees(Employee *list, int len, int order) {
	int status = OK;
	if (order == ASC) {
		_sortASC(list, len);
	} else if (order == DSC) {
		_sortDSC(list, len);
	} else
		status = ERROR;
	return status;
}

/** \brief print the content of employees array
 *  \param list Employee*
 *  \param length int
 *  \return int
 */
int arrEmpLib_printEmployees(Employee *list, int len) {
	printf("===============================================\n");
	printf("Id\t");
	printf("Name\t");
	printf("Lastname\t");
	printf("Salary\t");
	printf("Sector\n");
	for (int i = 0; i < len - 1; i++) {
		if (!(*(list + i)).isEmpty) {
			printf("%d\t", (*(list + i)).id);
			printf("%s\t", (*(list + i)).name);
			printf("%s\t\t", (*(list + i)).lastName);
			printf("%.2f\t", (*(list + i)).salary);
			printf("%d\n", (*(list + i)).sector);
		}
	}
	return 0;
}

void arrEmpLib_CalcSalaryAverage(Employee *employees, int len) {
	float salaryAcum = 0.0;
	int salaryCont = 0;
	float salaryAvrg = 0.0;
	int maxSalaryAvrgCont = 0;

	for (int i = 0; i < len - 1; i++) {
		if (!(*(employees + i)).isEmpty) {
			salaryAcum += (*(employees + i)).salary;
			salaryCont++;
		}
	}
	salaryAvrg = (float) salaryAcum / salaryCont;
	for (int e = 0; e < len - 1; e++) {
		if (!(*(employees + e)).isEmpty && (*(employees + e)).salary > salaryAvrg) {
			maxSalaryAvrgCont++;
		}
	}
	printf("Total de todos los salarios de los empleados: %.2f\n", salaryAcum);
	printf("Promedio de todos los salarios de los empleados: %.2f\n", salaryAvrg);
	printf("Cantidad de empleados que superan ese promedio: %d\n", maxSalaryAvrgCont);
}

int arrEmpLib_canOperate(Employee *employees, int len) {
	int isEmpty = TRUE;
	int i = 0;
	do {
		isEmpty = (*(employees + i)).isEmpty;
		i++;
	} while (isEmpty && i < len);
	return (!isEmpty);
}

/****************Private*************************/
void _swapEmployee(Employee *empl1, Employee *empl2){
	Employee empAux = *empl1;
	*empl1 = *empl2;
	*empl2 = empAux;
}
void _sortASC(Employee *list, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int e = i + 1; e < len - 1; e++) {
			if (strcmp((*(list + i)).lastName, (*(list + e)).lastName) > 0) {
				_swapEmployee((list + i),(list + e));
			} else if (strcmp((*(list + i)).lastName, (*(list + e)).lastName) == 0) {
				if ((*(list + i)).sector > (*(list + e)).sector) {
					_swapEmployee((list + i),(list + e));
				}
			}

		}
	}
}
void _sortDSC(Employee *list, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int e = i + 1; e < len - 1; e++) {
			if (strcmp((*(list + i)).lastName, (*(list + e)).lastName) < 0) {
				_swapEmployee((list + e),(list + i));
			} else if (strcmp((*(list + i)).lastName, (*(list + e)).lastName) == 0) {
				if ((*(list + i)).sector < (*(list + e)).sector) {
					_swapEmployee((list + e),(list + i));
				}
			}

		}
	}
}

int _getFreeEmplIndx(Employee *list, int len) {
	int i = 0;
	int bNoLibre = TRUE;
	int empIndx = -1;
	do {
		bNoLibre = (*(list + i)).isEmpty == FALSE;
		i++;
	} while (bNoLibre && i < len);
	empIndx = (bNoLibre) ? empIndx : (i - 1);
	return empIndx;
}

int _getLastId(Employee *list, int len) {
	int id = 0;
	for (int i = 0; i < len - 1; i++) {
		if ((*(list + i)).isEmpty == FALSE && (*(list + i)).id >= id) {
			id = (*(list + i)).id;
		}
	}
	return id;
}


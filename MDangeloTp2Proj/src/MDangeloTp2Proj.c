/*
 ============================================================================
 Name        : MDangeloTp2Proj.c
 Author      : mdangelo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "utn_custom_libs/utn_abm_tp2.h"

#define TOP 3 //1000

#define TEST_MODE 1
#define OK 1
#define FALSE 0

int main(void) {
	int id = 0;
	int ptSelected = 0;
	int status;
	Employee employees[TOP];

	if (!TEST_MODE) {
		status = abmLib_InitializeEmployees(employees, TOP);
	}else{
		printf("==TEST MODE OFF==\n");
		Employee emp1 = {1,"marcos","zapato",22.22,1,FALSE};
		Employee emp2 = {2,"adriana","asturia",33.33,2, FALSE};
		employees[0] = emp1;
		employees[1] = emp2;
		id = 3;
		status = OK;
	}

	if (status) {
		do {
			abmLib_BuildShowMenu(&ptSelected);
			abmLib_ExecuteOptSelected(ptSelected, employees, TOP, &id);
		} while (ptSelected >= 1 && ptSelected < 6);
	}
	return EXIT_SUCCESS;
}

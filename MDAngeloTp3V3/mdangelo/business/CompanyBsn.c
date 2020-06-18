/*
 * CompanyBsn.c
 * Created on: 14 jun. 2020
 * Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "../utils/MenuMng.h"
#include "../utils/Commons.h"
#include "CompanyBsn.h"

/******Private Functions************/
void _checkUserSelection(int iUsrSelect, LinkedList* linkedlist);
/***********************************/

void coBsn_startApp(LinkedList* linkedlist){
	int usrSelct = 0;
	do{
		mm_showMenuOptionAndGetUsrSelection(&usrSelct);
		_checkUserSelection(usrSelct, linkedlist);
	}while(usrSelct>=1 && usrSelct<=9);
}

void coBsn_chargeLinkedListFromFileTextMode(LinkedList* linkedlist) {
	char filePath[] = "./mdangelo/assets/txtfile1.csv";
	int len = ll_len(linkedlist);
	FILE *pFile = fmng_openFileByMode(filePath, "r");
	if(len>=1){
		ll_clear(linkedlist);
	}
	fmng_chargeLinkedListFromTxtFile(pFile,linkedlist);
	fmng_closeFile(pFile);
}
void coBsn_chargeLinkedListFromFileBinaryMode(LinkedList *linkedlist){
	char filePath[] = "./mdangelo/assets/binfile1.dat";
	FILE *pFile = fmng_openFileByMode(filePath, "rb");
	int len = ll_len(linkedlist);
	if(len>=1){
		ll_clear(linkedlist);
	}
	fmng_chargeLinkedListFromBinaryFile(pFile,linkedlist);
	fmng_closeFile(pFile);
}
void coBsn_crateTextFileFromnLinkeList(LinkedList* linkedlist){
	char filePath[] = "./mdangelo/assets/txtfile1.csv";
	FILE *pFile = NULL;
	int len = ll_len(linkedlist);
	if(len>=1){
		pFile = fmng_openFileByMode(filePath, "w");
		fmng_writeTextFileFromLinkedList(pFile, linkedlist);
		fmng_closeFile(pFile);
	}else{
		printf("--NO hay empleados cargados para generar dicho archivo--\n");
	}
}

void coBsn_createBinaryFileFromLinkedList(LinkedList* linkedlist){
	char filePath[] = "./mdangelo/assets/binfile1.dat";
	int len = ll_len(linkedlist);
	if(len>=1){
		FILE *pFile = fmng_openFileByMode(filePath, "wb");
		fmng_writeBinaryFileFromLinkedList(pFile,linkedlist);
		fmng_closeFile(pFile);
	}else{
		printf("--NO hay empleados cargados para generar dicho archivo--\n");
	}
}
void coBsn_createEmployee(LinkedList* linkedlist){
	int status = TRUE;
	status = es_createEmployee(linkedlist);
	if(!status) printf("--Empleado creado con exito--\n");
}
void coBsn_updateEmployee(LinkedList* linkedlist){
	int status = FALSE;
	int len = ll_len(linkedlist);
	if(len>=1){
		status = es_updateEmployee(linkedlist);
		if(status) printf("--Empleado actualizado con exito--\n");
	}else{
		printf("-Error: NO hay empleados para actualizar--\n");
	}
}
void coBsn_deleteEmployee(LinkedList* linkedlist){
	int status = FALSE;
	int len = ll_len(linkedlist);
	if(len>=1){
		status = es_deleteEmployee(linkedlist);
		if(status) printf("--Empleado eliminado con exito--\n");
	}else{
		printf("-Error: NO hay empleados para eliminar--\n");
	}
}
void coBsn_sortAllEmployees(LinkedList* linkedlist){
	int len = ll_len(linkedlist);
	int reslt = 0;
	if(len>=1){
		//ll_sort(linkedlist,es_sortEmployeesBySalary,1); //1=Asc 0=Dsc
		reslt = ll_sort(linkedlist,es_sortEmployeesByWrkdHrs,1); //1=Asc 0=Dsc
		if(!reslt)printf("--Ordenamiento exitoso, liste todos los empleados para ver el resultado--\n");
	}else{
		printf("-Error: NO hay empleados para eliminar--\n");
	}
}

void coBsn_showAllEmployees(LinkedList *linkedlist){
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
/**************Private Functions********************************/
void _checkUserSelection(int iUsrSelect, LinkedList* linkedlist) {
	printf("---Us_Selection %d\n", iUsrSelect);
	switch (iUsrSelect) {
		case LOAD_TXT_FILE:
			coBsn_chargeLinkedListFromFileTextMode(linkedlist);
			break;
		case LOAD_BYN_FILE:
			coBsn_chargeLinkedListFromFileBinaryMode(linkedlist);
			break;
		case CREATE_EMPL:
			coBsn_createEmployee(linkedlist);
			break;
		case UPDATE_EMPL:
			coBsn_updateEmployee(linkedlist);
			break;
		case DELETE_EMPL:
			coBsn_deleteEmployee(linkedlist);
			break;
		case LIST_EMPLYS:
			coBsn_showAllEmployees(linkedlist);
			break;
		case SORT_EMPLYS:
			coBsn_sortAllEmployees(linkedlist);
			break;
		case SAVE_TO_TXT_FILE:
			coBsn_crateTextFileFromnLinkeList(linkedlist);
			break;
		case SAVE_TO_BYN_FILE:
			coBsn_createBinaryFileFromLinkedList(linkedlist);
			break;
		case EXIT:
			exit(EXIT_SUCCESS);
			break;
	}
}

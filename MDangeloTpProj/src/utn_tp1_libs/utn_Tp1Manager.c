/*
 * utn_Tp1Manager.c
 * Created on: 13 abr. 2020
 * Author: mdangelo
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "utn_Tp1Manager.h"
#include "../utn_commons/utn_commons.h"
#include "../utn_commons/utn_math.h"

#define ITEM_1 "1=Ingresar 1er operando (A=%d)\n"
#define ITEM_2 "2=Ingresar 2do operando (B=%d)\n"
#define ITEM_3 "3=Calcular todas las operaciones\n"
#define ITEM_4 "4=Informar resultados\n"
#define ITEM_5 "5=Salir\n"

void _buildMenu(int *pOptSlct, int *pINum1, int *pINum2);
void _checkOptSelected(int iOptSlct,int *pINum1, int *pINum2, int *pResults);
void _calculateAllOPerations(int iNum1, int iNum2, int *pResults);
void _showAllResults(int iNum1, int iNum2, int *pResults);

#define TOP 7
void utnStartTP1Mng(void){
	int iNum1 = 0;
	int iNum2 = 0;
	int iOptSlctd = 0;

	int results[TOP];

	do{
		_buildMenu(&iOptSlctd, &iNum1, &iNum2);
		_checkOptSelected(iOptSlctd, &iNum1, &iNum2, results);
		printf("\n");
	}while(iOptSlctd != 5);
}

void _buildMenu(int *pOptSlct, int *pINum1, int *pINum2){
	printf("\n");
	printf("============MENU===========\n");
	printf(ITEM_1,*pINum1);
	printf(ITEM_2,*pINum2);
	printf(ITEM_3);
	printf(ITEM_4);
	printf(ITEM_5);
	printf("============================\n");
	scanf("%d",pOptSlct);
	__fpurge(stdin);
}

void _checkOptSelected(int iOptSlct,int *pINum1, int *pINum2, int *pResults) {
	switch (iOptSlct) {
		case 1:
			printf("--1-Ingresar 1do operandos--\n");
			*pINum1 = utnGetPositiveInteger(0);
			break;
		case 2:
			printf("--2-Ingresar 2do operando--\n");
			*pINum2 = utnGetPositiveInteger(0);
			break;
		case 3:
			printf("--3-Calcular operaciones--\n");
			_calculateAllOPerations(*pINum1, *pINum2, pResults);
			break;
		case 4:
			printf("--4-INFORMAR RESULTADOS--\n");
			_showAllResults(*pINum1, *pINum2, pResults);
			break;
		case 5:
			printf("--5 SALIR--\n");
			break;
		default:
			break;
	}
}

void _showOptionInvalidMssg(void){
	printf("Error: Opcion invalida, vuela a intenar [1,5]\n");
}

void _calculateAllOPerations(int iNum1, int iNum2, int *pResults){
	*(pResults+0) = utn_Addition(iNum1, iNum2);
	*(pResults+1) = utn_Subtraction(iNum1, iNum2);
	*(pResults+2) = utn_Multiplication(iNum1, iNum2);
	*(pResults+3) = utn_Division(iNum1, iNum2);
	*(pResults+4) = utn_Factorial(iNum1);
	*(pResults+5) = utn_Factorial(iNum2);
}

void _showAllResults(int iNum1, int iNum2, int *pResults){
	printf("El resultado de %d+%d es: %d \n*",iNum1, iNum2, *(pResults+0));
	printf("El resultado de %d-%d es: %d \n*",iNum1, iNum2, *(pResults+1));
	printf("El resultado de %d*%d es: %d \n*",iNum1, iNum2, *(pResults+2));
	printf("El resultado de %d/%d es: %d \n*",iNum1, iNum2, *(pResults+3));
	printf("El factorial de %d es: %d \n*",iNum1, *(pResults+4));
	printf("El factorial de %d es: %d \n*",iNum2, *(pResults+5));
}


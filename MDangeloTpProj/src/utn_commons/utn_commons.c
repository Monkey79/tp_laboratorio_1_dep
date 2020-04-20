/*
 * utn_commons.c
 *
 *  Created on: 13 abr. 2020
 *  Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "utn_commons.h"

int utnGetPositiveInteger(int iFrom) {
	int iNum=0;
	do{
		printf("Ingrese valor desde %d en adelante: ", iFrom);
		scanf("%d",&iNum);
		__fpurge(stdin);
	}while(iNum<iFrom);
	return iNum;
}
float utnGetPositiveFloat2D(float fFrom) {
	float fNum=0.0;
	do{
		printf("Ingrese valor desde %f en adelante: ", fFrom);
		scanf("%f",&fNum);
		__fpurge(stdin);
	}while(fNum<fFrom);
	return fNum;
}
void utnInitializeIntArray(int *pIntArr, int iTop, int iEmptyValue){
	for(int i=0; i< iTop-1; i++){
		*(pIntArr+i)=iEmptyValue;
	}
}

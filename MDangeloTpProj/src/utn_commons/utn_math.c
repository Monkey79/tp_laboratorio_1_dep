/*
 * utn_math.c
 * Created on: 12 abr. 2020
 * Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn_math.h"

#define DIVISION_ZERO_MSSG "Division by zero not Allowed\n"


int utn_Addition(int iNum1, int iNum2){
	return (iNum1+iNum2);
}
int utn_Subtraction(int iNum1, int iNum2){
	return (iNum1 - iNum2);
}
int utn_Multiplication(int iNum1, int iNum2){
	return (iNum1*iNum2);
}
int utn_Division(int iNum1, int iNum2){
	float reslt = 0;
	if(iNum2==0){
		printf("======ATTENTION=======\n");
		printf(DIVISION_ZERO_MSSG);
		printf("======================\n");
	}else{
		reslt = iNum1/iNum2;
	}
	return reslt;
}
int utn_Factorial(int iFact) {
	int iNum=1;
	for (int i=iFact; i > 0; i--) {
		iNum = iNum * i;
	}
	return iNum;
}



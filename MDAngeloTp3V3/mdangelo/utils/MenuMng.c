/*
 * MenuMng.c
 *  Created on: 17 jun. 2020
 *  Author: monkey
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "MenuMng.h"

#define ITEM_1 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
#define ITEM_2 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
#define ITEM_3 "\t3. Alta de empleado\n"
#define ITEM_4 "\t4. Modificar datos de empleado\n"
#define ITEM_5 "\t5. Baja de empleado\n"
#define ITEM_6 "\t6. Listar empleados\n"
#define ITEM_7 "\t7. Ordenar empleados\n"
#define ITEM_8 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
#define ITEM_9 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
#define ITEM_10 "10. Salir\n"

void mm_showMenuOptionAndGetUsrSelection(int *pUsrSlct) {
	printf(ITEM_1);
	printf(ITEM_2);
	printf(ITEM_3);
	printf(ITEM_4);
	printf(ITEM_5);
	printf(ITEM_6);
	printf(ITEM_7);
	printf(ITEM_8);
	printf(ITEM_9);
	printf(ITEM_10);
	__fpurge(stdin);
	scanf("%d", pUsrSlct);
}


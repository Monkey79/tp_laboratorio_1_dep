/*
 * EmplFileMng.c
 *  Created on: 10 jun. 2020
 *  Author: mdangelo
 */

#include "Commons.h"
#include "EmplFileMng.h"

#define NUM_FIELD_TXT 4
#define FILE_ERROR_MSSG "El archivo NO pudo abrirse..!"
#define FILE_ERROR_READ_MSSG "Hubo un error de lecutura del archivo de empleados"
#define FILE_ERROR_WRITE_MSSG "Hubo un error de escritura del archivo de empleados"

#define PATTERN_PARSER "%[^,],%[^,],%[^,],%[^\n]\n"

FILE* fmng_openFileByMode(char *pFilePath,char *pFileMode){
	FILE *pFile = NULL;

	if((pFile = fopen(pFilePath, pFileMode))==NULL){
		printf(FILE_ERROR_MSSG);
		exit(EXIT_FAILURE);
	}
	return pFile;
}
int fmng_chargeLinkedListFromTxtFile(FILE *pFile,LinkedList *linkedlist){
	int numAux = 0;
	int success = TRUE;

	char empIdDto[6];
	char empNameDto[128];
	char empWrkHrsDto[6];
	char emplSalaryDto[6];

	Employee *employee = NULL;

	numAux = fscanf(pFile,PATTERN_PARSER,empIdDto,empNameDto,empWrkHrsDto,emplSalaryDto);
	do{
		numAux = fscanf(pFile,PATTERN_PARSER,empIdDto,empNameDto,empWrkHrsDto,emplSalaryDto);
		if(numAux!=NUM_FIELD_TXT){
			printf(FILE_ERROR_READ_MSSG);
			success = FALSE;
		}
		employee = er_newEmployeePrms(empIdDto,empNameDto,empWrkHrsDto,emplSalaryDto);
		if(employee!=NULL)ll_add(linkedlist, employee);
	}while(!feof(pFile) && success);

	return success;
}
int fmng_writeTextFileFromLinkedList(FILE* pFile, LinkedList* linkedlist){
	int success=TRUE;
	int len = ll_len(linkedlist);
	int cantAux = 0;
	char buffer[100];
	Employee* empl=NULL;

	//int  [−32,767, +32,767]

	//id:int -> unsigned int (no negativos) [0,65.535] -> max 5 caract (1byte cada uno)
	//name->char[128]
	//hrs_trabajadas:int-> [0,65.535] -> max 5 caract (1byte cada uno)
	//salarios:int-> [0,65.535] -> max 5 caract (1byte cada uno)
	//=> total: registry[133]

	char registry[133]={0};
	cantAux = fprintf(pFile,"%s","id,nombre,horasTrabajadas,sueldo\n");
	for(int i=0;i<len && success;i++){
		empl = (Employee*) ll_get(linkedlist, i);
		sprintf(buffer,"%d",empl->empId);
		strcat(registry,buffer);
		strcat(registry,",");

		strcat(registry,empl->empName);
		strcat(registry,",");

		sprintf(buffer,"%d",empl->empWrkHrs);
		strcat(registry,buffer);
		strcat(registry,",");

		sprintf(buffer,"%d",empl->emplSalary);
		strcat(registry,buffer);
		strcat(registry,"\n");

		cantAux = fprintf(pFile,"%s",registry);
		if (cantAux < 1) {
			printf("--Error escribir archivo--\n");
			success = FALSE;
		}
		registry[0]=0;
	}
	return success;
}
int fmng_writeBinaryFileFromLinkedList(FILE *pFile,LinkedList *linkedlist){
	int success = TRUE;
	int e=0;
	int len=ll_len(linkedlist);
	Employee* empl = NULL;

	for(int i=0;i<len && success;i++){
		empl = (Employee*) ll_get(linkedlist, i);
		e =fwrite(empl,sizeof(Employee),1,pFile);
		if(e!=1){
			printf(FILE_ERROR_WRITE_MSSG);
			success=FALSE;
		}
	}
	return success;
}
int fmng_chargeLinkedListFromBinaryFile(FILE *pFile,LinkedList *linkedlist){
	int success=TRUE;
	int e=0;
	Employee* empl = NULL;
	while(!feof(pFile)){
		empl = er_newEmployee();
		if(empl!=NULL){
			e = fread(empl,sizeof(Employee),1,pFile);
			if(e==1){
				ll_add(linkedlist, empl);
			}
		}
	}
	return success;
}
int fmng_closeFile(FILE* pFile){
	return fclose(pFile);
}



/*
 * CompanyBsn.h
 *  Created on: 14 jun. 2020
 *  Author: monkey
 */

#ifndef MDANGELO_BUSINESS_COMPANYBSN_H_
#define MDANGELO_BUSINESS_COMPANYBSN_H_

#include "../entities/MainEntities.h"
#include "../utils/EmplFileMng.h"
#include "../services/EmployeeService.h"

void coBsn_startApp(LinkedList* linkedlist);

void coBsn_chargeLinkedListFromFileTextMode(LinkedList *linkedlist);
void coBsn_chargeLinkedListFromFileBinaryMode(LinkedList *linkedlist);

void coBsn_createBinaryFileFromLinkedList(LinkedList *linkedlist);
void coBsn_crateTextFileFromnLinkeList(LinkedList* linkedlist);

void coBsn_createEmployee(LinkedList* linkedlist);
void coBsn_updateEmployee(LinkedList* linkedlist);
void coBsn_deleteEmployee(LinkedList* linkedlist);
void coBsn_sortAllEmployees(LinkedList* linkedlist);

void coBsn_showAllEmployees(LinkedList *linkedlist);

#endif /* MDANGELO_BUSINESS_COMPANYBSN_H_ */

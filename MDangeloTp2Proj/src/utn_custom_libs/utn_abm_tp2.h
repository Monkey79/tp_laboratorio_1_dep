/*
 * utn_abm_tp2.h
 *  Created on: 23 abr. 2020
 *  Author: mdangelo
 */

#ifndef UTN_CUSTOM_LIBS_UTN_ABM_TP2_H_
#define UTN_CUSTOM_LIBS_UTN_ABM_TP2_H_
#include "utn_array_employees.h"


int abmLib_InitializeEmployees(Employee *employees, int len);
void abmLib_BuildShowMenu(int *pOptSlct);
void abmLib_ExecuteOptSelected(int ptSelected, Employee *employees, int len, int *id);

#endif /* UTN_CUSTOM_LIBS_UTN_ABM_TP2_H_ */

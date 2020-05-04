/*
 * utn_commons.h
 *
 *  Created on: 13 abr. 2020
 *  Author: mdangelo
 */

#ifndef UTN_COMMONS_UTN_COMMONS_H_
#define UTN_COMMONS_UTN_COMMONS_H_

//get positive ingeger from a given value only
int cmmLib_GetPositiveInteger(int iFrom);
//get positive float value from a given value (with 2 decimal)
float cmmLib_GetPositiveFloat2D(float fFrom);
void cmmLib_InitializeIntArray(int *pIntArr, int iTop, int iEmptyValue);


#endif /* UTN_COMMONS_UTN_COMMONS_H_ */

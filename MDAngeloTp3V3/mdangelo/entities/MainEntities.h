/*
 * MainEntities.h
 * Created on: 9 jun. 2020
 * Author: mdangelo
 */

#ifndef MDANGELO_ENTITIES_MAINENTITIES_H_
#define MDANGELO_ENTITIES_MAINENTITIES_H_

typedef struct {
    int empId;
    char empName[128];
    int empWrkHrs;
    int emplSalary;
}Employee;

typedef struct {
    char empIdDto[6];
    char empNameDto[128];
    char empWrkHrsDto[6];
    char emplSalaryDto[6];
}EmployeeDto;


#endif /* MDANGELO_ENTITIES_MAINENTITIES_H_ */

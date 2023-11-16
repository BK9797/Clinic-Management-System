/*
 ============================================================================
 Name        : clinic.h
 Author      : BISHOY KAMEL
 Version     :
 Copyright   : Your copyright notice
 Description : header file for the project
 ============================================================================
 */

#ifndef CLINIC_H_
#define CLINIC_H_

/*******************************************************************************
*                              Functions Prototypes                            *
*******************************************************************************/

// welcome screen
void welcome();

// the two modes
void modes();

// add patient information
void Add();

// edit patient information
void Edit();

// reserve slot with the doctor
void Reserve();

// cancel reservations with id
void Cancel();

// view patient information using id
void view_Record();

// view all reservations
void view_Reservations();


#endif /* CLINIC_H_ */

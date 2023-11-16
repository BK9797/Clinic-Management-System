/*
 ============================================================================
 Name        : clinic.c
 Author      : BISHOY KAMEL
 Version     :
 Copyright   : Your copyright notice
 Description : source file for the project
 ============================================================================
 */

/*******************************************************************************
*                                  Inclusions                                  *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clinic.h"

/*******************************************************************************
*                              Global Variables	                               *
*******************************************************************************/

static int password=1234;

#define max_name_char 20
#define max_slots 5

/* define the boolean data type */
typedef enum {
	False=0, True=1
}bool;

/* structure for patient data */
typedef struct patient
{
    char name[max_name_char];
    int id;
    int age;
    struct patient* next;
}patient;

/* structure for reservation slots */
typedef struct slot {
    int slot;
    int id;
    struct slot* next;
}slot;

/* global pointer to structure to make the linked-list */
patient *patientList = NULL;
slot *reservationList = NULL;

/*******************************************************************************
*                             Functions definition                             *
*******************************************************************************/

void welcome()
{
    printf("###############################################################\n");
    printf("###############################################################\n");
    printf("##          Welcome to our clinic management system          ##\n");
    printf("###############################################################\n");
    printf("###############################################################\n");

}

void modes()
{
    int Mode,n,trials=3,i;
    printf("Please choose one of the two modes: \n");
    printf("1) Admin mode\n");
    printf("2) User mode\n\n");
    printf("Enter 1 for Admin Mode  or  Enter 2 for User Mode:\n");
    scanf("%d",&Mode);
    printf("###############################################################\n");
    printf("###############################################################\n\n");

    while(1)
    {
    	if(Mode==1)
    	    {
    	        for(i=0;i<3;i++)
    	        {
    	        	printf("Please Enter Password: ");
    	        	scanf("%d",&password);
    	        	printf("\n");
    	        if(password==1234)
    	        {
    	        	printf("1) Add new patient record\n");
    			    printf("2) Edit patient record\n");
    	        	printf("3) Reserve a slot with the doctor\n");
    	        	printf("4) Cancel reservation\n");
    	            scanf("%d",&n);
    	            printf("\n");

    	            switch(n)
    	            {
    	                case 1: Add();  break;
    	                case 2: Edit();  break;
    	                case 3: Reserve();  break;
    	                case 4: Cancel();  break;
    	                default: printf("You may have some errors while using the program ,Loading...\n\n");
    	            }
    	            printf("\n");
    	            modes();
    	        }

    	        else
    	        {
    	            trials--;
    	            printf("You have %d trials left...\n",trials);
    	        }
    	        }
    	        printf("\nLoading,the system is updating...\n\n");
    	    }

    	    else if(Mode==2)
    	    {
    	        printf("1) View patient record\n");
    	        printf("2) View today's reservations\n");;
    	        scanf("%d",&n);
    	        printf("\n");
    	        switch(n)
    	        {
    	            case 1: view_Record();  break;
    	            case 2: view_Reservations();  break;
    	            default: printf("You may have some errors while using the program ,Loading...\n\n");
				}
    	        printf("\n");
    	        modes();
    	    }

    	    else
    	    {
    	        printf("You may have some errors while using the program ,Loading...\n\n");
    	        printf("\n");
    	        modes();
    	    }
    }
}

void Add()
{
	patient *newpatient = (patient*) malloc(sizeof(patient));
	printf("Enter patient ID: ");
	scanf("%d", &newpatient->id);
	patient *current = patientList;

	while (current != NULL)
	{
		if (current->id == newpatient->id)
		{
			printf("Patient with ID %d already exists.\n", newpatient->id);
			free(newpatient);
			return;
		}
			current = current->next;
	}

	printf("Enter new patient information: \n");
	printf("Name: ");
	scanf("%s",&newpatient->name);
	printf("Age: ");
	scanf("%d",&newpatient->age);

	newpatient->next = patientList;
	patientList=newpatient;
	printf("Patient record added successfully.\n");
}

void Edit()
{
	int id;
	printf("Enter patient ID: ");
	scanf("%d", &id);
	patient *currentpatient = patientList;

	while (currentpatient != NULL)
	{
		if (currentpatient->id == id)
		{
			printf("Your patient information is: \n");
			printf("Name: %s\n",currentpatient->name);
			printf("ID: %d\n",currentpatient->id);
			printf("Age: %d\n",currentpatient->age);
			printf("\n");
			printf("Enter patient edited information:\n");
			printf("Name: ");
			scanf("%s",&currentpatient->name);
			printf("Age: ");
			scanf("%d",&currentpatient->age);
			return;
		}

	    currentpatient = currentpatient->next;
	}

		printf("Patient not found.\n");
}

void Reserve()
{
    int n,id;
    bool found = False, slot1, slot2, slot3, slot4, slot5;
    printf("Reserve a slot with the doctor: \n");
    printf("#### Available slots ####\n");

    slot *checkSlot = reservationList;
    slot1 = slot2 = slot3 = slot4 = slot5 = True;
    while (checkSlot != NULL)
    {
    	if (checkSlot->slot != 1 && slot1)
    	{
    		slot1 = True;
    	}
    	else
    	{
    		slot1 = False;
    	}

    	if (checkSlot->slot != 2 && slot2)
    	{
    		slot2 = True;
    	}
    	else
    	{
    		slot2 = False;
    	}

    	if (checkSlot->slot != 3 && slot3)
    	{
    		slot3 = True;
    	}
    	else
    	{
    		slot3 = False;
    	}

    	if (checkSlot->slot != 4 && slot4)
    	{
    		slot4 = True;
    	}
    	else
    	{
    		slot4 = False;
    	}

    	if (checkSlot->slot != 5 && slot5)
    	{
    		slot5 = True;
    	}
    	else
    	{
    		slot5 = False;
    	}

    	checkSlot = checkSlot->next;
    }

    if (slot1)
    {
    	printf("1) 2 pm to 2:30 pm\n");
    }
    if (slot2)
    {
    	printf("2) 2:30 pm to 3 pm\n");
    }
    if (slot3)
    {
    	printf("3) 3 pm to 3:30 pm\n");
    }
    if (slot4)
    {
    	printf("4) 4 pm to 4:30 pm\n");
    }
    if (slot5)
    {
    	printf("5) 4:30 pm to 5 pm\n");
    }

    printf("Enter patient ID: \n");
    scanf("%d", &id);

	patient *current = patientList;
	while (current != NULL)
	{
		if (current->id == id)
	    {
			found = True;
			break;
		}

		current = current->next;
	}

	if (!found)
	{
		printf("Patient with ID %d not found.\n",id);
		return;
	}

	printf("Enter slot number: \n");
	scanf("%d",&n);

	if(n<1 || n>max_slots)
	{
		printf("You may have some errors while using the program ,Loading...\n\n");
		return;
    }

	slot *currentReservation = reservationList;
	while (currentReservation != NULL)
	{
		if (currentReservation->slot == n)
		{
			printf("Slot is already reserved.\n");
			return;
		}

		currentReservation = currentReservation->next;
	}

	slot *newReservation = (slot*) malloc(sizeof(slot));

	newReservation->slot = n;
	newReservation->id = id;
	newReservation->next = reservationList;
	reservationList = newReservation;
	printf("Slot reserved successfully.\n");
}

void Cancel()
{
	int id;
	printf("Enter patient ID: ");
	scanf("%d", &id);
	slot *currentReservation = reservationList;
	slot *pastReservation = NULL;

	while (currentReservation != NULL)
	{
		if (currentReservation->id == id)
		{
			reservationList = currentReservation->next;
		}
		else
		{
			pastReservation->next = currentReservation->next;
		}

		free(currentReservation);
		printf("Reservation cancelled.\n");
		return;

		pastReservation = currentReservation;
		currentReservation = currentReservation->next;

		printf("No reservation found for the given patient ID.\n");
	}
}

void view_Record()
{
	int id;
	printf("Enter patient ID: ");
	scanf("%d", &id);
	patient *currentpatient = patientList;

	while (currentpatient != NULL)
	{
		if (currentpatient->id == id)
		{
			printf("Your patient information is: \n");
			printf("Name: %s\n",currentpatient->name);
			printf("ID: %d\n",currentpatient->id);
			printf("Age: %d\n",currentpatient->age);
			return;
		}
	    currentpatient = currentpatient->next;
	}
		printf("Patient not found.\n");
}

void view_Reservations()
{
	if(reservationList == NULL)
	{
		printf("No reservations yet.\n");
		return;
	}

	slot *currentReservation = reservationList;

	while (currentReservation != NULL)
	{
		printf("Slot : %d\n",currentReservation->slot);
		printf("Patient ID: %d\n",currentReservation->id);

		currentReservation = currentReservation->next;
	}
}

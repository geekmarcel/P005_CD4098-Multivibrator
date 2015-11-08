/*--------------------------------------------------------------------------------------------------------------------------------------------------------
 * Project: 		CD4098 Library
 * Hardware:		Arduino UNO
 * Micro:			ATMEGA328P
 * IDE:				Atmel Studio 6.2
 *
 * Name:			cd4098.c
 * Purpose: 		CMOS CD4098 Library functions
 * Date:			18-10-2015
 * Author:			Marcel van der Ven
 *
 * Hardware setup:		
 *
 * Note(s):
 *--------------------------------------------------------------------------------------------------------------------------------------------------------*/

/************************************************************************/
/* Defines				                                                                  */
/************************************************************************/
#define F_CPU	16000000UL

/************************************************************************/
/* Includes				                                                                  */
/************************************************************************/
#include "cd4098.h"
#include "common.h"
#include "util/delay.h"


/************************************************************************/
/* Structures				                                                                  */
/************************************************************************/
struct CD4098
{
	volatile BYTE* dataOutputPortRegister;
	volatile BYTE* dataInputPortRegister;
	BYTE trPlusPin;
	
	/* Specifies if the structure is initialized with the register addresses and pin numbers */
	BOOL isInitialized;
} cd4098;

/************************************************************************/
/* Functions				                                                                  */
/************************************************************************/

/***************************************************************************
*  Function:		InitializeCD4098(volatile BYTE* dataOutputPortRegister,
*									 volatile BYTE* dataInputPortRegister,
*									 BYTE trPlusPin)
*  Description:		Initializes the registers.
*  Receives:		BYTE* dataOutputPortRegister	:	pointer to the data output register
*					BYTE* dataInputPortRegister		:	pointer to the data input register
*					BYTE trPlusPin					:	pin number to which the TR pin is connected.
*  Returns:			Nothing
***************************************************************************/
void InitializeCD4098(volatile BYTE* dataOutputPortRegister,
					  volatile BYTE* dataInputPortRegister,
					  BYTE trPlusPin)
{
	cd4098.dataOutputPortRegister = dataOutputPortRegister;
	cd4098.dataInputPortRegister = dataInputPortRegister;
	cd4098.trPlusPin = trPlusPin;

	/* Initialization finished, set flag to TRUE */	
	cd4098.isInitialized = TRUE;
}

/***************************************************************************
*  Function:		SetPulseHigh(void)
*  Description:		Sets the output high.
*  Receives:		Nothing
*  Returns:			Nothing
***************************************************************************/
void SetPulseHigh(void)
{
	if(cd4098.isInitialized == TRUE)
	{
		SET_BIT(cd4098.dataOutputPortRegister, cd4098.dataInputPortRegister, cd4098.trPlusPin);
	}
}

/***************************************************************************
*  Function:		SetPulseLow(void)
*  Description:		Sets the output low.
*  Receives:		Nothing
*  Returns:			Nothing
***************************************************************************/
void SetPulseLow(void)
{
	if(cd4098.isInitialized == TRUE)
	{
		CLEAR_BIT(cd4098.dataOutputPortRegister, cd4098.dataInputPortRegister, cd4098.trPlusPin);
	}
}	
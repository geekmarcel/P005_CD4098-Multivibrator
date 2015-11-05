/*--------------------------------------------------------------------------------------------------------------------------------------------------------
 * Project: 		CD4098 library
 * Hardware:		Arduino UNO
 * Micro:			ATMEGA328P
 * IDE:			Atmel Studio 6.2
 *
 * Name:    		cd4098.h
 * Purpose: 		CD4098 CMOS IC Header file for library
 * Date:			18-10-2015
 * Author:		Marcel van der Ven
 *
 * Hardware setup:	
 *
 * Note(s):
 *--------------------------------------------------------------------------------------------------------------------------------------------------------*/


#ifndef CD4098_H_
#define CD4098_H_

/************************************************************************/
/* Includes				                                                                  */
/************************************************************************/
#include "common.h"


/************************************************************************/
/* Enumerations			                                                                  */
/************************************************************************/


/************************************************************************/
/* Structures				                                                                  */
/************************************************************************/


/************************************************************************/
/* Function prototypes		                                                                  */
/************************************************************************/
void InitializeCD4098(volatile BYTE* dataOutputPortRegister,
					  volatile BYTE* dataInputPortRegister,
					  BYTE trPlusPin);
void SetPulseHigh(void);
void SetPulseLow(void);




#endif /* CD4098_H_ */
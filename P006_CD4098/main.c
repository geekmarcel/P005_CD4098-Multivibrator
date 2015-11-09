/*--------------------------------------------------------------------------------------------------------------------------------------------------------
* Project: 		Post 6 CD4098
* Hardware:		Arduino UNO
* Micro:		ATMEGA328P
* IDE:			Atmel Studio 6.2
*
* Name:    		main.c
* Purpose: 		CD4098 Example
* Date:			18-10-2015
* Author:		Marcel van der Ven
*
* Hardware setup:	PORTB1		Trigger Pulse signal (pin 4 on CD4098)
*
* Note(s):
*--------------------------------------------------------------------------------------------------------------------------------------------------------*/

/************************************************************************/
/* Defines				                                                */
/************************************************************************/
#define F_CPU	16000000UL

/************************************************************************/
/* Includes				                                                */
/************************************************************************/
#include <avr/io.h>
#include "util/delay.h"
#include "common.h"
#include "cd4098.h"

/***************************************************************************
*  Function:		Setup()
*  Description:		Setup PORTB.
*  Receives:		Nothing
*  Returns:			Nothing
***************************************************************************/
void Setup()
{
	/* Setup Port B */
	/* Pin 1 output, other pins input  */
	DDRB = 0b00000001;
}

/***************************************************************************
*  Function:		Main(void)
*  Description:		Main function of the program.
*  Receives:		Nothing
*  Returns:			Optionally the exit code.
***************************************************************************/
int main(void)
{
	/* Setup and initialization */
	Setup();
	InitializeCD4098(&PORTB,&PINB,PORTB0);
	
	SetPulseLow();
	_delay_ms(10000);
	
    while(1)
    {
		/* Set pulse high for 500 milliseconds */
		SetPulseHigh();		
		_delay_ms(500);
		
		/* Set pulse low for 2,5 seconds */
		SetPulseLow();
		_delay_ms(2500);
    }
}
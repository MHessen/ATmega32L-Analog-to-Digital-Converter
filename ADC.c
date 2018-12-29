/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Engineer:Mohammed Hussein
 */

#include "Types.h"
#include "Registers.h"
#include "DIO.h"
#include "ADC.h"
#define SetBit(Register,Pin) Register|=(1<<Pin)
#define ClrBit(Register,Pin) Register&=(~(1<<Pin))
#define get_bit(Register,Pin) ((Register >> Pin) & 1)

void ADC_Init (void)
{/*Analog to digital Converter Initialization*/
	/*
	//ADMUX
	ClrBit (ADMUX,0);
	ClrBit (ADMUX,1);
	ClrBit (ADMUX,2);
	ClrBit (ADMUX,3);
	ClrBit (ADMUX,4);
	SetBit (ADMUX,5);
	SetBit (ADMUX,6);
	ClrBit (ADMUX,7);
	*/

	/*---------------------------------------------------------------------*/
	/* Analog Channel Selection & Gain */
	ADMUX &= ~( (1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4) ) ;
	/* Left Adjust Result */
	ADMUX |= (1<<ADLAR);
	/* Reference Selection */
	ADMUX |= (1<<REFS0);
	ADMUX &= ~(1<<REFS1);
	/*_____________________________________________________________________*/

	/*
	//ADCSRA
	ClrBit (ADCSRA,0);
	ClrBit (ADCSRA,1);
	ClrBit (ADCSRA,2);
	ClrBit (ADCSRA,3);
	ClrBit (ADCSRA,4);
	ClrBit (ADCSRA,5);
	ClrBit (ADCSRA,6);
	SetBit (ADCSRA,7);
	*/

	/*-----------------------------------------------------------------------*/
	/* PreScale */
	ADCSRA &= ( (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2) );
	/* ADC Enable */
	ADCSRA |= (1<<ADEN) ;
	/*_______________________________________________________________________*/

}

u8 ADC_u8ReadOut(void)
{/*ADC Reading the Converted Value*/

	//Start Conversion
	/*SetBit(ADCSRA,6);*/
	ADCSRA |= (1<<ADSC);

	while (get_bit(ADCSRA,ADIF)== 0)
	{
		//Stuck Here polling up on the Peripheral Interrupt Flag Till Bit Value become "1".
	}

	/*SetBit(ADCSRA,4);*/
	/*ADIF is cleared by writing a logical one to the flag*/
	ADCSRA |= (1<<ADIF);

	return ADCH ;
}

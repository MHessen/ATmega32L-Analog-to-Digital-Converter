/*
 * main.c
 *
 * Author: Engr.Mohammed Hessen
 */
#include "Types.h"
#include "ADC.h"
#include "Registers.h"
#include "DIO.h"

int main (void)
{
	u8 digital_out , analog_in ;

	ADC_Init();

	while (1)
	{
		digital_out = ADC_u8ReadOut();
		analog_in = (digital_out*5) / 256;
		/*---------------------------------------------------------------------------------------*/
		/*_______________________________________________________________________________________*/
		/* ##..Clarification ABOUT " analog_in = (didital_out * 500)/256; "..##
		 * ______________________________________________________________________________________
		 * -> digital_out : The Digital Equivalent Value returned from function
		 * 					ADC_u8ReadOut Describing the Analog input value.
		 * 					---------------------------------------------------------------------
		 * -> analog_in   : Analog voltage input TO BE READ.
		 * 					---------------------------------------------------------------------
		 * -> Formula     : (digital_out*5) / 256 ..... Referring to DataSheet it's clear to find
		 * 					" Analog Voltage = Digital Equivalent * ADC_Step "
		 * 					.. ADC_Step = (Reference Voltage) / ( 2^(Num.Of Bits Used) )
		 * 					Reference Voltage = 5v .
		 * 					Num.Of Bits Used = 8 Bit, 2^8 = 256 .
		 * 					FINALLY....
		 * 					Analog Voltage = ( Digital-out-from-conversion * 5 ) / ( 256 ).
		 *					---------------------------------------------------------------------
		 */
	}

	return 0;
}

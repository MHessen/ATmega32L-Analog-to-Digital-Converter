/*
 * ADC.h
 *
 * Author: Engineer:Mohammed Hessen
 */

#ifndef ADC_H_
#define ADC_H_

/*---------------------------------ADC Register----------------------------------------*/

enum ADMUX_Reg  { MUX0 , MUX1 , MUX2 , MUX3 , MUX4 , ADLAR , REFS0 , REFS1 } ;
enum ADCSRA_Reg { ADPS0 , ADPS1 , ADPS2 , ADIE , ADIF , ADATE , ADSC , ADEN } ;
enum SFIOR_Reg  { PSR10 , PSR2 , PUD , ACME , RESERVED , ADTS0 , ADTS1 , ADTS2 } ;

/*_____________________________________________________________________________________*/

void ADC_Init (void);
u8 ADC_u8ReadOut(void);

#endif /* ADC_H_ */

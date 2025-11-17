/*
 * DRIVER_ADC.c
 *
 *  Created on: Jan 3, 2020
 *      Author: GJF-Trabajo
 */

#include "Defines.h"

uint32_t	ADC_Cuentas[2];
uint32_t	Medicion[2];

/*****************************************************************************
** Function name:		ADC_Init
**
** Descriptions:		Inicializamos el conversor analogico digital
**
** parameters:			void
** Returned value:		void
**
*****************************************************************************/
void ADC_Inicializar(void)
{
	SYSCON->PDRUNCFG &= ~(1 << 4);				// Enciendo el modulo del ADC que esta apagado por default
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 24);		// 24 = ADC

	SWM0->PINENABLE0 &= ~(1 << 14);				// ADC_0 enabled on pin PIO0_7
	SWM0->PINENABLE0 &= ~(1 << 15);				// ADC_1 enabled on pin PIO0_6

	ADC0->CTRL 	= (1)							// CLKDIV se recomienda el minimo si no hay una necesidad de velocidad
				| (0 << 8)						// ASYNCMODE
				| (0 << 10)						// LPWRMODE
				| (0 << 30);					// CALMODE

	// A/D Conversion Sequence A Control Register

	ADC0->SEQ_CTRL[0] 	= (0)					// CANAL, lo voy a seleccionar en el momento de disparar la conversion
						| (0 << 12)				// TRIGGER
						//	Input 	Source 					Description
						//	0 								- No hardware trigger.
						//	1 		PININT0_IRQ 			GPIO_INT interrupt 0.
						//	2 		PININT1_IRQ 			GPIO_INT interrupt 1.
						//	3 		SCT0_OUT3 				SCT output 3.
						//	4 		SCT0_OUT4 				SCT output 4.
						//	5 		T0_MAT3 				CTIMER match 3.
						//	6 		CMP0_OUT_ADC 			Analog comparator output.
						//	7 		GPIO_INT_BMAT 			GPIO_INT bmatch.
						//	8 		ARM_TXEV 				ARM core TXEV event.
						| (1 << 18)				// TRIGPOL					0=FLANCO NEGATIVO DE LOS TRIGGERS 1=FLANCO POSITIVO DE LOS TRIGGERS
						| (0 << 19)				// SYNCBYPASS
						| (0 << 26)				// START OF CONVERSION		1=SOC 0=STOP
						| (0 << 29)				// SINGLESTEP
						| (0 << 30)				// MODE						0
						| (1 << 31);			// SEQA_ENA					0=SECUENCIA A DESHABILITADA 1=HABILITADA

	ADC0->INTEN = (1 << 0);						// Sequence A interrupt enable

	NVIC->ISER[0] = (1 << 16); 					/* enable interrupt ISE_ADC_SEQA*/

}

void ADC_Disparo(uint8_t Canal)
{
	ADC0->SEQ_CTRL[0] 	&= ~(0xfff);			// Limpio los bits de seleccion del canal
	ADC0->SEQ_CTRL[0] 	|= (1 << Canal)			// Seleccion del canal
						| (1 << 26);			// START OF CONVERSION		1=SOC 0=STOP
}

void ADC_SEQA_IRQHandler(void)
{

	uint32_t	Temporal = ADC0->SEQ_GDAT[0];
	uint32_t 	Canal = (Temporal >> 26) & 0x0f;
	uint32_t	Valor_Temporal;

//	Temporal = Temporal >> 4;
//	Temporal &= 0xfff;
	if(Canal > 1)
		return;

	Valor_Temporal = (Temporal >> 4) & 0xfff;

	ADC_Cuentas[Canal] = Valor_Temporal;

	Valor_Temporal = (Valor_Temporal * 3300) / 4096;

	//Valor_Temporal = (Valor_Temporal * 1000) / 33;

	Medicion[Canal] = Valor_Temporal;
	//printf("ADC Canal %d= %d\r\n", Canal, Temporal);
}

/*
 * DRIVER_ADC.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Gustavo Fresno
 */

#ifndef DRIVER_ADC_DRIVER_ADC_H_
#define DRIVER_ADC_DRIVER_ADC_H_

#define 	CANTIDAD_CANALES_ADC	2

void ADC_Inicializar(void);
void ADC_Disparo(uint32_t Canal);
void ADC_Start(void);

extern "C" {
void ADC_SEQA_IRQHandler(void);
}


#endif /* DRIVER_ADC_DRIVER_ADC_H_ */

/*
 * HCSR04Driver.h
 *
 *  Created on: 6 nov. 2024
 *      Author: Gustavo Fresno
 */

#ifndef HCSR04DRIVER_H_
#define HCSR04DRIVER_H_

#define TIEMPO_PULSO_ENVIO	20

void HCSR04_Driver_Init(uint32_t portTrigger, uint32_t pinTrigger, uint32_t portEco, uint32_t pinEco, uint32_t time_msec);

void CTIMER0_HW_Inicializacion(uint16_t Tiempo);
uint32_t CTIMER0_HW_Get_TC(void);
void CTIMER0_HW_Reset_TC(void);


extern "C" {
void CTIMER0_IRQHandler (void);
}

#define PIN_TRIGGER		0,18
#define PIN_ECO			0,19

#endif /* HCSR04DRIVER_H_ */

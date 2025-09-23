/*
 * HCSR04Driver.cpp
 *
 *  Created on: 6 nov. 2024
 *      Author: Gustavo Fresno
 */

#include "Defines.h"

Gpio *trigger;
Gpio *eco;

uint32_t divisorTime = 0;
uint32_t Distancia = 0;

void HCSR04_Driver_Init(uint32_t portTrigger, uint32_t pinTrigger, uint32_t portEco, uint32_t pinEco, uint32_t time_msec)
{
	trigger = new Gpio(portTrigger, pinTrigger, 1);

	eco = new Gpio(portEco, pinEco, 0);

	divisorTime = time_msec;

	CTIMER0_HW_Inicializacion(20);
}

void CTIMER0_HW_Inicializacion(uint16_t Tiempo)
{
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 25);// 25 = CTIMER

	CTIMER0->PR = 12;

	CTIMER0->MR[0] = (Tiempo);			// Cargo tiempo en Match0

	CTIMER0->MCR |= 1 << 0;				// Habilitar interrupcion para Match0
	CTIMER0->MCR |= 1 << 1;				// Resetear Match0

	CTIMER0->TCR |= 1 << 1; 			// Fuerzo reseteo de Timer0

	CTIMER0->IR = 1;

	CTIMER0->TCR = 1; 				 	// Inicio Timer0 borrando el reset

	NVIC->ISER[0] = (1 << CTIMER0_IRQn); /* enable interrupt */
}

uint32_t CTIMER0_HW_Get_TC(void)
{
	return CTIMER0->TC;
}

void CTIMER0_HW_Reset_TC(void)
{
	CTIMER0->TC = 0;
	CTIMER0->TCR |= 1 << 1; 				// Fuerzo reseteo de Timer0
	CTIMER0->TCR = 1; 				 	// Inicio Timer0 borrando el reset
}

//----------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------
void CTIMER0_IRQHandler (void)
{
	static uint8_t		Flag_Pin = 0;
	static uint16_t		SENSOR_DISTANCIA_Estado = 0;
	static uint8_t		Deteccion_en_Curso = 0;

	CTIMER0->IR |= 1 << 0;				 // Borro flag del Match 0

	if(SENSOR_DISTANCIA_Estado < TIEMPO_PULSO_ENVIO)
	{
		trigger->Set(1);
	}

	if(SENSOR_DISTANCIA_Estado == TIEMPO_PULSO_ENVIO)
	{
		Deteccion_en_Curso = 1;
		Flag_Pin = 0;

		trigger->Set(0);
	}

	if(SENSOR_DISTANCIA_Estado > TIEMPO_PULSO_ENVIO)
	{
		if(Deteccion_en_Curso)
		{
			if(eco->Read() == 0)
			{
				if(Flag_Pin)
				{
					Distancia = SENSOR_DISTANCIA_Estado - TIEMPO_PULSO_ENVIO;
					Deteccion_en_Curso = 0;
				}
				Flag_Pin = 0;
			}
			else
			{
				Flag_Pin = 1;
			}
		}

		if(SENSOR_DISTANCIA_Estado > 3200)
		{
			SENSOR_DISTANCIA_Estado = 0;
			return;
		}
	}

	SENSOR_DISTANCIA_Estado++;
	if(SENSOR_DISTANCIA_Estado >= 0XFFFF)
		SENSOR_DISTANCIA_Estado = 0;
}



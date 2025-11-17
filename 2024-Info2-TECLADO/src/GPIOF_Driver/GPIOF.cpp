/*
 * GPIOF.cpp
 *
 *  Created on: 5 set. 2023
 *      Author: gusta
 */

#include "Defines.h"

GpioF::GpioF(uint32_t _port, uint32_t _pin, uint32_t _direccion) : Gpio(_port, _pin, _direccion)
{
	Estado_Anterior = 0;
	Contador = 0;
	Estado_Filtrado = 0;
}

void GpioF::Callback(void)
{
	Antirebote();
}

uint32_t GpioF::Read(void)
{
	return Estado_Filtrado;
}

uint32_t GpioF::Read_HW(void)
{
	return Gpio::Read();
}

void GpioF::Antirebote(void)
{
	uint8_t Estado_Actual;

	Estado_Actual = Read_HW();

	if(Estado_Actual == Estado_Anterior)
	{
		Contador++;
		if(Contador >= CANTIDAD_ESTADOS_ESTABLES)
		{
			Estado_Filtrado = Estado_Actual;
		}
	}
	else
	{
		Contador = 0;
	}

	Estado_Anterior = Estado_Actual;
}

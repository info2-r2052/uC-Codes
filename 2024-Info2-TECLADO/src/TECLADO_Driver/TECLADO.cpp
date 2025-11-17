/*
 * TECLADO.cpp
 *
 *  Created on: 25 jun. 2024
 *      Author: gusta
 */

#include "Defines.h"


Gpio Col1(PIN_COL1, GPIO_SALIDA);
Gpio Col2(PIN_COL2, GPIO_SALIDA);
Gpio Col3(PIN_COL3, GPIO_SALIDA);

Gpio Fila1(PIN_FILA1, GPIO_ENTRADA);
Gpio Fila2(PIN_FILA2, GPIO_ENTRADA);
Gpio Fila3(PIN_FILA3, GPIO_ENTRADA);

uint32_t TECLADO::Read_HW(void)
{
	//------------------------------
	// COLUMNA 1

	Col1.Set(0);
	Col2.Set(1);
	Col3.Set(1);

	if(Fila1.Read() == 0)
		return CODIGO_TECLA_1;

	if(Fila2.Read() == 0)
		return CODIGO_TECLA_2;

	if(Fila3.Read() == 0)
		return CODIGO_TECLA_3;

	//------------------------------
	// COLUMNA 2
	Col1.Set(1);
	Col2.Set(0);
	Col3.Set(1);

	if(Fila1.Read() == 0)
		return CODIGO_TECLA_4;

	if(Fila2.Read() == 0)
		return CODIGO_TECLA_5;

	if(Fila3.Read() == 0)
		return CODIGO_TECLA_6;

	//------------------------------
	// COLUMNA 3
	Col1.Set(1);
	Col2.Set(1);
	Col3.Set(0);

	if(Fila1.Read() == 0)
		return CODIGO_TECLA_7;

	if(Fila2.Read() == 0)
		return CODIGO_TECLA_8;

	if(Fila3.Read() == 0)
		return CODIGO_TECLA_9;

	return NO_TECLA;
}

uint32_t TECLADO::Read(void)
{
	int32_t temporal = Pop();
	if(temporal < 0)
		return NO_TECLA;

	return (uint32_t)temporal;
}

void TECLADO::Push(uint8_t dato){
	Buffer[in] = dato;

	in++;
	if(in >= TAMANIO_BUFFER_TECLADO)
		in = TAMANIO_BUFFER_TECLADO;
}

int32_t TECLADO::Pop(void){
	int32_t temp = -1;

	if(in != out)
	{
		temp = (int32_t)Buffer[out];

		out++;
		if(out >= TAMANIO_BUFFER_TECLADO)
			out = TAMANIO_BUFFER_TECLADO;
	}

	return temp;
}

void TECLADO::Callback( void ){
	Antirebote();
}

void TECLADO::Antirebote(void)
{
	uint32_t Codigo_Actual;

	Codigo_Actual = Read_HW();

	if(Codigo_Actual == NO_TECLA)
	{
		Contador = 0;
		Codigo_Anterior = NO_TECLA;
		return;
	}

	if(Codigo_Actual == Codigo_Anterior)
	{

		if(Contador == CANTIDAD_CODIGOS_ESTABLES)
		{
			Push(Codigo_Actual);
		}

		if(Contador >= CANTIDAD_CODIGOS_ESTABLES_REPETIDA)
		{
			Push(Codigo_Actual + CODIGO_REPETICION);
			return;
		}

		Contador++;
	}
	else
	{
		Contador = 0;
	}

	Codigo_Anterior = Codigo_Actual;
}

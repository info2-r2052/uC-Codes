/*
 * MaqEstPirometro.c
 *
 *  Created on: 26 jun. 2024
 *      Author: gusta
 */

#include "Defines.h"

uint32_t 		valorControl = VALOR_CONTROL_INICIAL;
uint8_t 		flag_Control_On = 0;
uint8_t 		MaqEstControl_Estado = 0;
uint8_t 		flag_Control_Off = 0;

Gpio	RES(1,2,GPIO_SALIDA);

extern TECLADO	Teclado;

void ControlPirometro(void)
{
	uint8_t tecla;

	MaqEst_Control();

	tecla = Teclado.Read();

	switch(tecla)
	{
	case CODIGO_TECLA_1:
		valorControl++;
		if(valorControl >= VALOR_CONTROL_MAXIMO)
			valorControl = VALOR_CONTROL_MAXIMO;
		break;
	case CODIGO_TECLA_2:
		if(valorControl > VALOR_CONTROL_MINIMO)
			valorControl--;
		break;
	case (CODIGO_TECLA_1 + CODIGO_REPETICION):
		valorControl+=10;
		if(valorControl >= VALOR_CONTROL_MAXIMO)
			valorControl = VALOR_CONTROL_MAXIMO;
		break;
	case (CODIGO_TECLA_2 + CODIGO_REPETICION):
		if(valorControl > VALOR_CONTROL_MINIMO)
			valorControl-=10;
		break;
	case CODIGO_TECLA_3:
		flag_Control_On = 1;
		break;
	case CODIGO_TECLA_4:
		flag_Control_Off = 1;
		break;
	default:
		break;
	}
}

void MaqEst_Control(void)
{
	switch(MaqEstControl_Estado)
	{
	case 0:
		MaqEstControl_Estado0();
		break;
	case 1:
		MaqEstControl_Estado1();
		break;
	case 2:
		MaqEstControl_Estado2();
		break;
	default:
		break;
	}
}

void MaqEstControl_Estado0(void)
{
	if(flag_Control_On == 1)
	{
		flag_Control_On = 0;
		MaqEstControl_Estado = 1;
	}
}

void MaqEstControl_Estado1(void)
{
	uint32_t temperatura = 123;//LeerTemperatura();

	if(temperatura < (valorControl - BANDA))
	{
		RES.Set(1);
	}

	if(temperatura >= valorControl)
	{
		RES.Set(0);
		MaqEstControl_Estado = 2;
	}

	if(flag_Control_Off == 1)
	{
		flag_Control_Off = 0;
		RES.Set(0);
		MaqEstControl_Estado = 0;
	}
}

void MaqEstControl_Estado2(void)
{
	uint32_t temperatura = 123;//LeerTemperatura();

	if(temperatura < (valorControl - BANDA))
	{
		RES.Set(1);
		MaqEstControl_Estado = 1;
	}

	if(flag_Control_Off == 1)
	{
		flag_Control_Off = 0;
		RES.Set(0);
		MaqEstControl_Estado = 0;
	}
}

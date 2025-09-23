/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "Defines.h"

void Inicializacion(void);
void Print(void);

SYSTICK Systick(3000);

GPIOPWM ledR(1, 2, 5);

TIMERSW Timer1;

extern uint32_t Distancia;

extern uint32_t	ADC_Cuentas[CANTIDAD_CANALES_ADC];
extern uint32_t	ADC_Medicion[CANTIDAD_CANALES_ADC];

void Inicializacion(void)
{
	ADC_Inicializar();

	HCSR04_Driver_Init(PIN_TRIGGER, PIN_ECO, 1);

	UART0_Init(9600);
}

int main(void) {

	Inicializacion();

	Timer1.Start(1000, 1000, Print);

    while(1) {

    }
    return 0 ;
}

void Print(void){
	uint8_t Buf[20];

	sprintf((char*)Buf, "Distancia= %d\r\n", Distancia);

	UART0_Send(Buf, 0);

	//ledR.Set(ADC_Medicion[0]/1000);
}

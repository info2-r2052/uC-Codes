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

// Variables Globales
void Led(void);

TIMER TimerLed(2000,1000,Led);

Gpio LED_ROJO(PIN_LED_ROJO, OUTPUT);
Gpio LED_AZUL(PIN_LED_AZUL, OUTPUT);
Gpio LED_VERDE(PIN_LED_VERDE, OUTPUT);

GPIOF PULSADOR(PIN_PULSADOR);

UART0	Uart0(9600);

int main(void) {

	// Inicializacion


    while(1) {

    	// Procesamiento

    	if(PULSADOR.Get() == 0)
    	{
    		LED_VERDE.Set(1);
    	}

    }
    return 0 ;
}

void Led(void){
	static uint8_t stateLed = 0;

	if(stateLed == 1){
		stateLed = 0;
	} else {
		stateLed = 1;
	}

	LED_ROJO.Set(stateLed);

	Uart0.Send((uint8_t*)"Hola", 0);
}





//

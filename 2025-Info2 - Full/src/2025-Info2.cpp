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

uint16_t Temperatura1 = 0;
uint16_t Temperatura2 =0;

uint8_t Buffer[100];

int main(void) {

	// Inicializacion
	LCD_Inicializar();

	LCD_Display((uint8_t *)"Hola", 0, 0);

    while(1) {

    	// Procesamiento

    	if(PULSADOR.Get() == 0)
    	{
    		LED_VERDE.Set(1);
    	}


    	//Serial_Analizar_RX();

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









	Temperatura1++;
	Temperatura2+=2;

	sprintf((char*)Buffer, "Temp1=%05d , Temp2=%05d\r\n", Temperatura1, Temperatura2);

	Uart0.Send((uint8_t*)Buffer, 0);

/*	Buffer[0] = (Temperatura1 >> 8) & 0xff;
	Buffer[1] = Temperatura1 & 0xff;
	Buffer[2] = (Temperatura2 >> 8) & 0xff;
	Buffer[3] = Temperatura2 & 0xff;

	Uart0.Send((uint8_t*)Buffer, 4);*/
}





//

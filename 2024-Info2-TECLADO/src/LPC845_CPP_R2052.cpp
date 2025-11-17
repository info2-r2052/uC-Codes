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

void Led(void);
void Print(void);

SYSTICK Systick(1000);

Gpio ledG(1, 0, 1);
Gpio ledB(1, 1, 1);
Gpio ledR(1, 2, 1);

GpioF	Pulsador(0, 4, 0);

TECLADO	Teclado;

int main(void) {

    while(1) {
    	Application();
    }
    return 0 ;
}




















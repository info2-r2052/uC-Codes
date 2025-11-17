#include <cr_section_macros.h>
//#include "PuertoSerie.h"
#include "UART0.h"
#include "stdio.h"

UART0	Uart0(9600);
uint8_t Buffer[100];

int main(void) {

		sprintf((char*)Buffer, "Hola Mundo");

		Uart0.Send((uint8_t*)Buffer, 0);

    while(1) {}

    return 0 ;
}

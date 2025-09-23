/*
 * Analisis_Serial.c
 *
 *  Created on: 2 set. 2025
 *      Author: gusta
 */

#define POSICION_CHECKSUM_TX	10
#define TAMANIO_TRAMA			11

#include "Defines.h"

extern UART0	Uart0;

void Serial_Transmitir_Temperatura(uint16_t temp){
	uint8_t Buf[20];
	uint8_t checksum = 0;

	sprintf((char*)Buf, ">S1:%05dC<", temp);

	for(int i = 0 ; i < POSICION_CHECKSUM_TX ; i++){
		checksum += Buf[i];
	}
	Buf[POSICION_CHECKSUM_TX] = checksum;

	Uart0.Send((uint8_t *)Buf, TAMANIO_TRAMA);
}

void Serial_Analizar_RX(){
	static uint8_t EstadoRx = 0;
	static uint8_t checksum = 0;

	int32_t dato = Uart0.PopRx();
	if(dato < 0){
		return;
	}

	switch(EstadoRx){
	case 0:
		if(dato == '>'){
			EstadoRx = 1;
			checksum = dato;
		}
		break;
	case 1:
		if(dato == 'Q'){
			EstadoRx = 2;
			checksum += dato;
		}
		else{
			EstadoRx = 0;
		}
		break;
	case 2:
		if(dato == 'S'){
			EstadoRx = 3;
			checksum += dato;
		}else{
			EstadoRx = 0;
		}
		break;
	case 3:
		if(dato == '1'){
			EstadoRx = 4;
			checksum += dato;
		}else{
			EstadoRx = 0;
		}
		break;
	case 4:
		if(dato == '?'){
			EstadoRx = 5;
			checksum += dato;
		}else{
			EstadoRx = 0;
		}
		break;
	case 5:
		if(checksum == dato){
			// La trama recibida es correcta
			Serial_Transmitir_Temperatura(10);

			EstadoRx = 0;
		}else{
			EstadoRx = 0;
		}
		break;
	}
}

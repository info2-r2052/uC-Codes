/*
 * UART2_Driver.h
 *
 *  Created on: Jul 26, 2019
 *      Author: Gustavo Fresno
 */

#ifndef DRIVER_UART_UART3_DRIVER_H_
#define DRIVER_UART_UART3_DRIVER_H_

#define		UART3_TAMANIO_COLA_RX					5
#define		UART3_TAMANIO_COLA_TX					1

typedef struct
{
	uint8_t						Datos_Validos;
	uint16_t					Tamanio;
	uint8_t						Buffer[UART3_TAMANIO_COLA_RX];
	uint16_t					Indice_in, Indice_out;
}STRUCT_RX3;

typedef struct
{
	uint8_t						Datos_Validos;
	uint16_t					Tamanio;
	uint8_t						Buffer[UART3_TAMANIO_COLA_TX];
	uint16_t					Indice_in, Indice_out;
}STRUCT_TX3;

typedef struct
{
	STRUCT_RX3					RX;
	STRUCT_TX3					TX;
}UART3_Struct;

void UART3_Init(uint32_t baudrate);
void UART3_Send(uint8_t *Datos, uint32_t Tamanio);
void UART3_PushTx(uint8_t Dato);
int32_t UART3_PopTx( void );
void UART3_PushRx(uint8_t Dato);
int32_t UART3_PopRx( void );

#endif /* DRIVER_UART_UART3_DRIVER_H_ */

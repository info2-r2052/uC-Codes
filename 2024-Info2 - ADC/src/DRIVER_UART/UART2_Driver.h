/*
 * UART2_Driver.h
 *
 *  Created on: Jul 26, 2019
 *      Author: Gustavo Fresno
 */

#ifndef DRIVER_UART_UART2_DRIVER_H_
#define DRIVER_UART_UART2_DRIVER_H_

#define		UART2_TAMANIO_COLA_RX					5
#define		UART2_TAMANIO_COLA_TX					100

typedef struct
{
	uint8_t						Datos_Validos;
	uint16_t					Tamanio;
	uint8_t						Buffer[UART2_TAMANIO_COLA_RX];
	uint16_t					Indice_in, Indice_out;
}STRUCT_RX2;

typedef struct
{
	uint8_t						Datos_Validos;
	uint16_t					Tamanio;
	uint8_t						Buffer[UART2_TAMANIO_COLA_TX];
	uint16_t					Indice_in, Indice_out;
}STRUCT_TX2;

typedef struct
{
	STRUCT_RX2					RX;
	STRUCT_TX2					TX;
}UART2_Struct;

void UART2_Init(uint32_t baudrate);
void UART2_Send(uint8_t *Datos, uint32_t Tamanio);
void UART2_PushTx(uint8_t Dato);
int32_t UART2_PopTx( void );
void UART2_PushRx(uint8_t Dato);
int32_t UART2_PopRx( void );

#endif /* DRIVER_UART_UART2_DRIVER_H_ */

/*
 * TECLADO.h
 *
 *  Created on: 25 jun. 2024
 *      Author: gusta
 */

#ifndef TECLADO_DRIVER_TECLADO_H_
#define TECLADO_DRIVER_TECLADO_H_

// La definicion de los pines es a modo de ejemplo, hay q modificar de acuerdo con el HW
#define PIN_COL1	1,1
#define PIN_COL2	1,2
#define PIN_COL3	1,3

#define PIN_FILA1	1,1
#define PIN_FILA2	1,2
#define PIN_FILA3	1,3

#define TAMANIO_BUFFER_TECLADO				10
#define CANTIDAD_CODIGOS_ESTABLES			20
#define CANTIDAD_CODIGOS_ESTABLES_REPETIDA	100
#define CODIGO_REPETICION					0x80
#define NO_TECLA							0xff

enum {
	CODIGO_TECLA_0 = 0,
	CODIGO_TECLA_1,
	CODIGO_TECLA_2,
	CODIGO_TECLA_3,
	CODIGO_TECLA_4,
	CODIGO_TECLA_5,
	CODIGO_TECLA_6,
	CODIGO_TECLA_7,
	CODIGO_TECLA_8,
	CODIGO_TECLA_9,
};

class TECLADO : public CALLBACK{
private:
	uint8_t Buffer[TAMANIO_BUFFER_TECLADO];
	uint8_t in = 0;
	uint8_t out = 0;
	uint8_t Codigo_Anterior;
	uint8_t Contador;

public:
	uint32_t Read_HW(void);
	void Antirebote(void);
	uint32_t Read(void);

	void Push(uint8_t dato);
	int32_t Pop(void);

	void Callback( void );
};

#endif /* TECLADO_DRIVER_TECLADO_H_ */

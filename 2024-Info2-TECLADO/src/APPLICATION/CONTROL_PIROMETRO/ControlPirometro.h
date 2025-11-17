/*
 * ControlPirometro.h
 *
 *  Created on: 26 jun. 2024
 *      Author: gusta
 */

#ifndef APPLICATION_MAQ_EST_PIROMETRO_MAQESTPIROMETRO_H_
#define APPLICATION_MAQ_EST_PIROMETRO_MAQESTPIROMETRO_H_

#define VALOR_CONTROL_INICIAL	50
#define VALOR_CONTROL_MAXIMO	1000
#define VALOR_CONTROL_MINIMO	20

#define BANDA					2

void ControlPirometro(void);
void MaqEst_Control(void);
void MaqEstControl_Estado0(void);
void MaqEstControl_Estado1(void);
void MaqEstControl_Estado2(void);

#endif /* APPLICATION_MAQ_EST_PIROMETRO_MAQESTPIROMETRO_H_ */

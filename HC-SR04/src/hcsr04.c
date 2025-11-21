/*
 * hcsr04.c
 *
 *  Created on: 14 nov. 2021
 *      Author: mariano
 */

#include "misc.h"

void PulsoTrigger( void )
{
	ConfigMatch( );
	TimerStart(0, 5, PulsoTrigger , SEG );
}

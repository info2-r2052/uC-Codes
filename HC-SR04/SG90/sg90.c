/*
 * esp8266.c
 *
 *  Created on: 27 oct. 2019
 *      Author: juliancho
 */


#include <misc.h>


uint32_t SG90( int16_t degrees)
{
	uint32_t pwm = 0;
	degrees += 90;		//y = x + 90

	if( degrees < 0 )
		degrees = 0;

	if( degrees > 180 )
		degrees = 180;

	pwm = MENOSnOVENTAgRADOS + degrees*GRADO;

	if( pwm < MENOSnOVENTAgRADOS )
		pwm = MENOSnOVENTAgRADOS;
	if( pwm > NOVENTAgRADOS )
		pwm = NOVENTAgRADOS;

	return pwm;
}

/*
 * DRIVER_LCD16X2.c
 *
 *  Created on: Jan 6, 2020
 *      Author: GJF-Trabajo
 */

#include "Defines.h"

Gpio PIN_LCD_RS(PIN_LCD16X2_RS, OUTPUT);
Gpio PIN_LCD_E(PIN_LCD16X2_E, OUTPUT);
Gpio PIN_LCD_D7(PIN_LCD16X2_D7, OUTPUT);
Gpio PIN_LCD_D6(PIN_LCD16X2_D6, OUTPUT);
Gpio PIN_LCD_D5(PIN_LCD16X2_D5, OUTPUT);
Gpio PIN_LCD_D4(PIN_LCD16X2_D4, OUTPUT);

void LCD_Escribir(uint8_t data , uint8_t control)
{
	int32_t q , i = 1;

	do
	{
		PIN_LCD_D7.Set(( data >> ( 3 + i * 4 ) ) & 0x01);
		PIN_LCD_D6.Set(( data >> ( 2 + i * 4 ) ) & 0x01);
		PIN_LCD_D5.Set(( data >> ( 1 + i * 4 ) ) & 0x01);
		PIN_LCD_D4.Set(( data >> ( 0 + i * 4 ) ) & 0x01);

		if( control )
			PIN_LCD_RS.Set(0);
		else
			PIN_LCD_RS.Set(1);

		PIN_LCD_E.Set(1);
		for( q = 0 ; q < 400 ; q++ );
		PIN_LCD_E.Set(0);
		for( q = 0 ; q < 14000 ; q++ );
	}
	while ( i-- );
}

#define COMANDO_POSICION_LCD	0x80

void LCD_Display( uint8_t *msg , uint8_t r , uint8_t p )
{
	unsigned char i ;

	if( r == 1)
		p = p + 0x40 ;

	LCD_Escribir( p + COMANDO_POSICION_LCD, LCD16x2_CONTROL );

	for( i = 0 ; msg[ i ] != '\0' ; i++ )
		LCD_Escribir( msg[ i ] , LCD16x2_DATA );
}


void LCD_Inicializar( void )
{

	uint32_t i, j;

	for( i = 0 ; i < 3 ; i++ )
	{
		PIN_LCD_E.Set(0);
		LCD_Delay( );
		PIN_LCD_D7.Set(0);
		PIN_LCD_D6.Set(0);
		PIN_LCD_D5.Set(1);
		PIN_LCD_D4.Set(1);

		PIN_LCD_RS.Set(0);
		PIN_LCD_E.Set(1);

		for( j = 0 ; j < 10000 ; j++ );//4500

		PIN_LCD_E.Set(0);
	}

	PIN_LCD_E.Set(0);
	LCD_Delay( );
	PIN_LCD_D7.Set(0);
	PIN_LCD_D6.Set(0);
	PIN_LCD_D5.Set(1);
	PIN_LCD_D4.Set(0);

	PIN_LCD_RS.Set(0);
	PIN_LCD_E.Set(1);

	for( j = 0 ; j < 10000 ; j++ );//4500

	PIN_LCD_E.Set(0);

	// A partir de aca pasa a 4 bits
	LCD_Escribir( 0x28 , LCD16x2_CONTROL);
	LCD_Escribir( 0x08 , LCD16x2_CONTROL);	// display OFF
	LCD_Escribir( 0x01 , LCD16x2_CONTROL);	// clear display
	LCD_Escribir( 0x06 , LCD16x2_CONTROL);	// programo el LCD para mis necesidades
	LCD_Escribir( 0x0C , LCD16x2_CONTROL);	// display ON,sin cursor y blinking OFF del cursor
}

void LCD_Delay( void )
{
  uint32_t 	i;

  for ( i = 0 ; i < 500000 ; i++ ); // 300000
}


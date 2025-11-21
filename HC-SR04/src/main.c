/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : ESTE EJEMPLO NO FUNCIONA BIEN. NO LE GUSTA EL PASAJE DE MATCH
 	 	 	 	 A MODO CAPTURA. EL PULSO DE ECO QUE CALCULA ES MUY BAJO
===============================================================================
*/

#include <misc.h>


int main(void)
{
	uint32_t tiempo;
	uint8_t buffer[40];
	Inicializar();

    while(1)
    {
    	TimerEvent( );
    	if( GetFlagProcesarPulso() )
    	{
    		SetFlagProcesarPulso( 0 );
    		tiempo = GetTiempoPulso( );
    		sprintf( ( char*)buffer, "Pulso: %d\r\n", tiempo);
    		UART1_Send( buffer, strlen(( char*)buffer) );

    	}

    }
    return 0 ;
}

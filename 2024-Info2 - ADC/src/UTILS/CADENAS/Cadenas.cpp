//******************************************************************************
// Archivo:				Cadenas.c
//
// Descripci�n:			Funciones de manejo de las cadenas
//
// Realizado por:		Ing. Fresno Gustavo
//
//******************************************************************************
#include "Defines.h"

const uint8_t 		Tabla_BIN_HEX[] = {		0x30, 	/* 0 */
                                            0x31, 	/* 1 */
                                            0x32, 	/* 2 */
                                            0x33, 	/* 3 */
                                            0x34, 	/* 4 */
                                            0x35, 	/* 5 */
                                            0x36, 	/* 6 */
                                            0x37, 	/* 7 */
                                            0x38, 	/* 8 */
                                            0x39, 	/* 9 */
                                            0x41, 	/* A */
                                            0x42, 	/* B */
                                            0x43, 	/* C */
                                            0x44, 	/* D */
                                            0x45, 	/* E */
                                            0x46}; 	/* F */

//***************************************************************************************************************************
//	Funcion que sirve para buscar un caracter dentro de una cadena
//***************************************************************************************************************************
uint32_t CADENAS_Buscar_Caracter(uint8_t* Cadena, uint8_t Caracter, uint16_t Tamanio)
{
	uint32_t	i;

	if(Tamanio)
		for(i = 0 ; (Cadena[i] != Caracter) && (i < Tamanio) ; i++);
	else
	{
		for(i = 0 ; (Cadena[i] != Caracter) && (Cadena[i] != 10) && (Cadena[i] != 13) && (i < 200) ; i++);

	 	if(Cadena[i] == 10 || Cadena[i] == 13 || i >= 200)
			return ERROR_UINT32;
	}
	return i;
}

//***************************************************************************************************************************
//	Funcion que sirve para buscar el caracter dentro de una cadena, te busca el que se repita tantas veces
//***************************************************************************************************************************
uint32_t CADENAS_Buscar_Caracter_nro(uint8_t* Cadena, uint8_t caracter, uint16_t cual, uint16_t Tamanio)
{
	uint32_t i;
	
	if(!cual)
		return ERROR_UINT32;
	
	for(i = 0; i < Tamanio ; i++)
	{
		if(Cadena[i] == caracter)
		{
			cual--;
			if(!cual)
				return i;
		}
	}

	return ERROR_UINT32;
}

//***************************************************************************************************************************
//	Es como un aoti pero tambien le indico la cantidad de caracteres que quiero usar
//***************************************************************************************************************************
uint16_t CADENAS_Atoin(uint8_t *datos, uint8_t cantidad)
{
	uint32_t	i;
	uint32_t 	dato = 0;

	if(!cantidad)
	{
		for(i = 0 ; i < 20 ; i++)
		{
			dato *= 10;

			if((datos[i] >= '0') && (datos[i] <= '9'))
				dato += (datos[i] - '0');
			else
			{
				dato /= 10;
				break;
			}
		}
	}
	else
	{
		for(i = 0 ; i < cantidad ; i++)
		{
			dato *= 10;

			if((datos[i] >= '0') && (datos[i] <= '9'))
				dato += (datos[i] - '0');
			else
				return 0xffff;
		}
	}

	return (uint16_t)dato;
}

//***************************************************************************************************************************
//	Es como un atol pero tambien le indico la cantidad de caracteres que quiero usar
//***************************************************************************************************************************
//uint32_t CADENAS_Atoln(uint8_t *datos, uint8_t cantidad)
//{
//	uint32_t	i;
//	uint32_t 	dato = 0;
//
//	if(!cantidad)
//	{
//		for(i = 0 ; i < 20 ; i++)
//		{
//			dato *= 10;
//
//			if((datos[i] >= '0') && (datos[i] <= '9'))
//				dato += (datos[i] - '0');
//			else
//			{
//				dato /= 10;
//				break;
//			}
//		}
//	}
//	else
//	{
//		for(i = 0 ; i < cantidad ; i++)
//		{
//			dato *= 10;
//
//			if((datos[i] >= '0') && (datos[i] <= '9'))
//				dato += (datos[i] - '0');
//			else
//				return ERROR_UINT32;
//		}
//	}
//
//	return dato;
//}

uint32_t CADENAS_Atoln(uint8_t *datos)
{
	uint32_t	i;
	uint32_t 	dato = 0;

	for(i = 0 ; i < 20 ; i++)
	{
		dato *= 10;

		if((datos[i] >= '0') && (datos[i] <= '9'))
			dato += (datos[i] - '0');
		else
		{
			dato /= 10;
			break;
		}
	}

	return dato;
}

//***************************************************************************************************************************
//	Funcion para convertir una cadena de caracteres Hexa a uint32_t
//***************************************************************************************************************************
uint32_t CADENAS_Hex_2_Int(uint32_t *Dato_Resultado, uint8_t *Cadena, uint32_t Tamanio)
{
	uint32_t i,j, Dato = 0;

	for(i = 0 ; i < Tamanio ; i++)
	{
		for(j = 0 ; j < 16 ; j++)
		{
			if(Cadena[i] == Tabla_BIN_HEX[j])
				break;
		}
		if(j == 16)
		{
			*Dato_Resultado = Dato;
			return i;
		}

		Dato *= 16;

		Dato += j;
	}

	*Dato_Resultado = Dato;
	return i;
}
//***************************************************************************************************************************
//	Es como un atol pero tambien le indico la cantidad de caracteres que quiero usar
//***************************************************************************************************************************
uint8_t CADENAS_Atolb(uint8_t *datos, uint8_t cantidad)
{
	uint32_t	i;
	uint8_t 	dato = 0;

	for(i = 0 ; i < cantidad ; i++)
	{
		dato *= 256;
        dato += datos[i];
	}

	return dato;
}

//***************************************************************************************************************************
//	Sirve para concatenar en una cadena datos binarios
//***************************************************************************************************************************
void CADENAS_Strcatb(uint8_t *datos, uint32_t Dato, uint8_t cantidad)
{
	uint32_t	i;

	for(i = 0 ; i < cantidad ; i++)
	{
		datos[cantidad - i - 1] = Dato % 256;
        Dato /= 256;
	}
}

//***************************************************************************************************************************
//	Sirve para copiar un string en otro y devuelve el tamaño del vector
//***************************************************************************************************************************
uint32_t CADENAS_Strcpy(uint8_t *Destino, uint8_t *Origen)
{
	uint32_t	i;

	for(i = 0 ; Origen[i] ; i++)
		Destino[i] = Origen[i];

	Destino[i] = 0;

	return i;
}

//***************************************************************************************************************************
//	Sirve para calcular el tamaño de una cadena de caracteres ascii
//***************************************************************************************************************************
uint32_t CADENAS_Strlen(uint8_t *datos)
{
	uint32_t	i;

	for(i = 0 ; i < 0xffff ; i++)
	{
		if(!datos[i])
			return i;
	}

	return i;
}

//***************************************************************************************************************************
//	Sirve para calcular el tamaño de una cadena de caracteres ascii
//***************************************************************************************************************************
void CADENAS_Display(uint8_t *datos, uint32_t Numero, uint32_t Cantidad_Digitos)
{
	uint32_t	i, Temporal;

	for(i = 0 ; i < Cantidad_Digitos ; i++)
	{
		Temporal = (Numero % 10) + '0';
		datos[Cantidad_Digitos - i - 1] = Temporal;
		Numero/=10;
	}
	datos[i] = 0;

	return;
}

//***************************************************************************************************************************
//	Funcion para buscar una cadena dentro de otra
//***************************************************************************************************************************
int32_t CADENAS_Buscar_Cadena(uint8_t *str1, uint8_t *str2, uint32_t Tamanio)
{
	uint32_t i = 0;
	uint32_t j = 0;
 	uint32_t posicion = 0;

	while(i < Tamanio) //str1[i] != 0 &&
	{
		if(str1[i] == str2[j] || str2[j] == '*' || (str2[j-1] == '*' && str2[j] == '.'))
		{
			if(!j)
				posicion = i;
			
			if(str2[j-1] == '*' && str2[j] == '.')
			{
				if(str1[i+1] == 0)
					return posicion;	
			}
			else
			{
				j++;

				if(str2[j] == 0)
					return posicion;	
			}
		}
		else
			j = 0;

		i++;
	}

	return -1;
}

//***************************************************************************************************************************
//	Funcion para buscar una cadena dentro de otra
//***************************************************************************************************************************
int32_t CADENAS_Buscar_Cadena_Tamanio(uint8_t *str1, uint8_t *str2, uint32_t Tamanio_1)
{
	uint32_t i = 0;
	uint32_t j = 0;
	uint32_t posicion=0;
    
//    if(Tamanio_1 < Tamanio_2)
//	    return -1;

	while(i < Tamanio_1)
	{
		if(str1[i] == str2[j] || str2[j] == '*' || (str2[j-1] == '*' && str2[j] == '.' && j>0))
		{
			if(!j)	//Donde comienza a coincidir la cadena
			{
				posicion = i;
			}
			
			//Si la cadena que busco es *.
			if(str2[j-1] == '*' && str2[j] == '.' && j>0)
			{
				if(str1[i+1] == 0)
				{
					return posicion;
				}
			}
			else
			{
				j++;

				//Llego al final del 2do string y encontr� coincidencias
				if(str2[j] == 0)
				{
					return posicion;	
				}
			}
			
		}
		else
		{
			//Si encontr� alguna coincidencia y luego se corto
			//vuelvo a evaluar desde ahi.
			if(j!=0)
			{
				//Paso a evaluar desde la �ltima coincidencia registrada
				i=posicion;
			}
			
			//No coinciden, as� que vuelvo a reiniciar la busqueda
			j = 0;
		}
		
		i++;
		
	}

	return -1;
}

//***************************************************************************************************************************
//	Funcion para buscar una cadena dentro de otra
//***************************************************************************************************************************
uint32_t CADENAS_Buscar_Cantidad_Caracter(uint8_t *Cadena, uint8_t caracter, uint8_t cual, uint32_t Tamanio)
{
	uint32_t i;
	
	if(!cual)
		return ERROR_UINT32;
	
	for(i = 0; i < Tamanio ; i++)
	{
		if(Cadena[i] == caracter)
		{
			cual--;
			if(!cual)
				return i;
		}
	}

	return ERROR_UINT32;
}

//***************************************************************************************************************************
//	Funciones de conversi�n Big Endian y Little Endian
//***************************************************************************************************************************
uint16_t LE2BE_16bits (uint16_t i)
{
    return ((i>>8)&0xff)+((i << 8)&0xff00);
}

uint32_t LE2BE_32bits (uint32_t i)
{
    return((i&0xff)<<24)+((i&0xff00)<<8)+((i&0xff0000)>>8)+((i>>24)&0xff);
}

uint16_t BE2LE_16bits (uint16_t i)
{
    return ((i>>8)&0xff)+((i << 8)&0xff00);
}

uint32_t BE2LE_32bits (uint32_t i)
{
    return((i&0xff)<<24)+((i&0xff00)<<8)+((i&0xff0000)>>8)+((i>>24)&0xff);
}

uint8_t CADENAS_Byte_Inversion(uint8_t	origen)
{
	uint32_t 	i;
	uint8_t		destino = 0;

	for( i = 0 ; i < 8 ; i++)
	{
		if(origen & (0x01 << i))
			destino |= ((uint8_t)0x80 >> i);
	}

	return destino;
}

//*************************************************************************************
//	Funcion para generar un codigo CRC
//*************************************************************************************
uint8_t CRC_Check_8_bit(uint8_t *p_buffer, uint32_t cantidad)
{
	uint8_t 	aux, j;
	uint8_t 	crc = 0;
	uint32_t 	i;

	for(i = 0 ; i < cantidad ; i++)
	{
		for(j = 0 ; j < 8 ; j++)
		{
			aux = *(p_buffer+i)>>j;		//1er bit, 2do bit..
			aux ^= crc;
			crc = crc >> 1;
			if(aux & 0x01)
			{							//Si la XOR dio 1..
				aux = crc>>2;
				if(aux & 0x01)			//Bit 5th Stage en 1
					crc &= 0xFB;		//lo complemento
				else
					crc |= 0x04;

 				aux = crc>>3;			//Bit 4th Stage en 1
				if(aux & 0x01)			//Lo complemento
					crc &= 0xF7;
				else
					crc |= 0x08;

				crc |= 0x80;			//Pongo 1 en 1st Stage
			}
			else
				crc &= 0x7F;			//Pongo 0 en 1st Stage
		}
	}
	return crc;
}

//***************************************************************************************************************************
//	Es como un aoti pero tambien le indico la cantidad de caracteres que quiero usar
//***************************************************************************************************************************
uint32_t CADENAS_Atoibn(uint8_t *datos, uint8_t cantidad, uint8_t Sentido)
{
	uint32_t	i = 0, j = 0;
	uint32_t 	dato = 0;

	if(Sentido)
		j = cantidad - 1;

	do
	{
		dato *= 256;
		dato += datos[j];

		if(Sentido)
			j--;
		else
			j++;

		i++;
	}while(i < cantidad);

	return dato;
}

void CADENAS_Reemplazar_Caracter(uint8_t *Datos, uint32_t Tamanio, uint8_t Caracter_Original, uint8_t Caracter_Nuevo)
{
	uint32_t i;

	for(i = 0 ; i < Tamanio ; i++)
	{
		if(Datos[i] == Caracter_Original)
			Datos[i] = Caracter_Nuevo;
	}
}



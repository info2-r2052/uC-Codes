//******************************************************************************
//  ETIQUETAS
//******************************************************************************
//******************************************************************************
//  VARIABLES
//******************************************************************************
//******************************************************************************
//  PROTOTIPOS DE FUNCIONES
//******************************************************************************
#ifndef CADENAS_H_
#define CADENAS_H_

uint32_t CADENAS_Buscar_Caracter(uint8_t* Cadena, uint8_t Caracter, uint16_t Tamanio);
uint32_t CADENAS_Buscar_Caracter_nro(uint8_t* Cadena, uint8_t caracter, uint16_t cual, uint16_t Tamanio);
uint16_t CADENAS_Atoin(uint8_t *datos, uint8_t cantidad);
uint32_t CADENAS_Atoln(uint8_t *datos);
uint8_t CADENAS_Atolb(uint8_t *datos, uint8_t cantidad);
void CADENAS_Strcatb(uint8_t *datos, uint32_t Dato, uint8_t cantidad);
uint32_t CADENAS_Strcpy(uint8_t *Destino, uint8_t *Origen);
int32_t CADENAS_Buscar_Cadena(uint8_t *str1, uint8_t *str2, uint32_t Tamanio);
int32_t CADENAS_Buscar_Cadena_Tamanio(uint8_t *str1, uint8_t *str2, uint32_t Tamanio_1);
uint32_t CADENAS_Buscar_Cantidad_Caracter(uint8_t *Cadena, uint8_t caracter, uint8_t cual, uint32_t Tamanio);
uint32_t CADENAS_Strlen(uint8_t *);
void CADENAS_Display(uint8_t *datos, uint32_t Numero, uint32_t Cantidad_Digitos);
uint16_t LE2BE_16bits (uint16_t i);
uint32_t LE2BE_32bits (uint32_t i);
uint16_t BE2LE_16bits (uint16_t i);
uint32_t BE2LE_32bits (uint32_t i);
uint8_t CADENAS_Byte_Inversion(uint8_t	origen);
uint8_t CRC_Check_8_bit(uint8_t *p_buffer, uint32_t cantidad);
uint32_t CADENAS_Hex_2_Int(uint32_t *Dato_Resultado, uint8_t *Cadena, uint32_t Tamanio);
uint32_t CADENAS_Atoibn(uint8_t *datos, uint8_t cantidad, uint8_t Sentido);
void CADENAS_Reemplazar_Caracter(uint8_t *Datos, uint32_t Tamanio, uint8_t Caracter_Original, uint8_t Caracter_Nuevo);

#endif

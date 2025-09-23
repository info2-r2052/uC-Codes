/*
 * TIMERSW.cpp
 *
 *  Created on: 22 ago. 2023
 *      Author: gusta
 */

#include "Defines.h"

extern std::vector<CALLBACK*> vCallBack;

TIMERSW::TIMERSW(){
	tiempo = 0;
	tiempoRecarga = 0;
	fin = 0;
	func = nullptr;
}

void TIMERSW::Start(uint32_t tiempo, uint32_t tiempoRecarga, void (*func)(void)){
	this->tiempo = tiempo;
	this->tiempoRecarga = tiempoRecarga;
	this->fin = 0;
	this->func = func;
}

void TIMERSW::Callback(void)
{
	Descontar();
}

void TIMERSW::Descontar(void){
	if(tiempo > 0){
		tiempo--;
		if(0 == tiempo){
			func();
			tiempo = tiempoRecarga;
		}
	}
}




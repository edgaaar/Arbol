#include "NodoA.h"

NodoA::NodoA(int dato)
{
	this->dato = dato;
	this->Padre = NULL;
}

NodoA::NodoA(int dato, NodoA* padre)
{
	this->dato = dato;
	this->Padre = padre;
}
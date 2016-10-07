#include <iostream>
#include <cstring>
#include <vector>

class NodoA
{
public:
	int dato;

	std::vector<NodoA*> Hijos;
	NodoA * Padre;
	NodoA(int dato);
	NodoA(int dato , NodoA* padre);
};
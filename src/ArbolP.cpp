#include "ArbolP.h"

ArbolP::ArbolP(int orig)
{
	this->Raiz = new NodoA(orig);
}

bool ArbolP::AddNodo(int ref,int aux)
{
	if(this->Raiz==NULL)
	{
		this->Raiz=new NodoA(aux);
		std::cout<<"El arbol esta vacio, no existe la referencia"<<std::endl;
		return false;
	}
	NodoA* Padre=BusqNodo(ref);
	if(Padre==NULL)
	{
		std::cout<<"No existe la referencia"<<std::endl;
		return false;
	}
	else
	{
		NodoA* hijo=new NodoA(aux,Padre);
		Padre->Hijos.push_back(hijo);
	}
	return true;
}

bool ArbolP::ElimNodo(int ref)
{
	if (this->Raiz==NULL)
	{
		std::cout<<"No existe el valor en el arbol"<<std::endl;
		return false;		
	}
	NodoA* aux=BusqNodo(ref);
	if (aux == NULL)
	{
		std::cout<<"No existe el valor en el arbol"<<std::endl;
		return false;
	}
	for (int i = 0; i < aux->Hijos.size(); ++i)
	{
		aux->Padre->Hijos.push_back(aux->Hijos[i]);
		aux->Hijos[i]=aux->Padre;
	}
	aux->Hijos.clear();
	aux->Padre=NULL;
	for (int i = 0; i < aux->Padre->Hijos.size(); ++i)
	{
		if (aux==aux->Padre->Hijos[i]){
			aux->Padre->Hijos.erase(aux->Padre->Hijos.begin()+i);
			return true;
		}
	}
	return false;
}

std::stack<NodoA*> ArbolP::Camino(NodoA* aux)
{
	std::stack<NodoA*> Camino;
	while(aux!=Raiz){
		Camino.push(aux);
		aux=aux->Padre;
	}
	return Camino;
}

NodoA* ArbolP::BusqNodo(int ref)
{
	if(Raiz==NULL)
	{
		std::cout<<"No existen elementos en el árbol"<<std::endl;
		return NULL;
	}
	else

		return BusqRec(ref,Raiz);
	
}

NodoA* ArbolP::BusqRec(int ref, NodoA* aux)
{
	NodoA* Busque=aux;
	NodoA* 	Res;
	if(Busque->dato==ref)
	{
		return Busque;
	}
	if(Busque->Hijos.empty())
	{
		return NULL;
	}
	for(int i=0; i<Busque->Hijos.size();++i){
		Res = BusqRec(ref,Busque->Hijos[i]);
		if(Res!=NULL)
			return Res;			
	}
	return NULL;
}

bool ArbolP::ExisteEl(int ref)
{
	if(BusqNodo(ref)==NULL)
	{
		std::cout<<"No existe el "<<ref<<" en el árbol"<<std::endl;
		return false;
	}
	std::cout<<"Sí existe el "<<ref<<" en el árbol"<<std::endl;
	return true;
}



void ArbolP::ImprimeArbol(NodoA* aux, std::string espacio)
{
	
	for(int i=0; i<aux->Hijos.size(); ++i)
	{
			std::cout<<espacio;
			std::cout<<aux->Hijos[i]->dato<<std::endl;

			if (aux->Hijos[i]->Hijos.size() != 0)
				ImprimeArbol(aux->Hijos[i], espacio+"└————");
			espacio.substr(6);
	}
}

void ArbolP::ImprimeArbol()
{
	NodoA* aux = Raiz;
	std::string espacio = "└————";
	std::cout<<aux->dato<<std::endl;
	ImprimeArbol(aux, espacio);
}
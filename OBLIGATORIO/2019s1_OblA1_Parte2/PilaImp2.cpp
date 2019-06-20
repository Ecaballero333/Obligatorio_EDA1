#include "PilaImp2.h"
#ifndef PILAIMP2_CPP
#define PILAIMP2_CPP

template<class T>
PilaImp2<T>::PilaImp2()
{
	this->lista = new ListaPosImp<T>();
}

template<class T>
PilaImp2<T>::PilaImp2(const Pila<T>& p)
{
	this->lista = new ListaPosImp<T>();
	*this = p;
}



template<class T>
PilaImp2<T>::PilaImp2(const PilaImp2<T>& p)
{
	this->lista = new ListaPosImp<T>();
	*this = p;
}

template<class T>
Pila<T>& PilaImp2<T>::operator=(const Pila<T>& p)
{
	Pila<T>* clon = p.Clon();
	while (!clon->EsVacia()) {
		this->lista->AgregarFin(clon->Pop());
	}
	return *this;
}

template<class T>
Pila<T>& PilaImp2<T>::operator=(const PilaImp2<T>& p)
{
	*this->lista = *p.lista;
	return *this;
}

template<class T>
PilaImp2<T>::~PilaImp2()
{
	delete this -> lista;
}

template<class T>
Pila<T>* PilaImp2<T>::CrearVacia() const
{
	return new PilaImp2();
}

template<class T>
Pila<T>* PilaImp2<T>::Clon() const
{
	Pila<T>* clon = new PilaImp2(*this);
	return clon;
}

template<class T>
void PilaImp2<T>::Push(const T & e)
{
	this->lista->AgregarPpio(e);
}

template<class T>
T & PilaImp2<T>::Top() const
{
	return this->lista->ElementoPpio();
}

template<class T>
T PilaImp2<T>::Pop()
{
	T elemento = this->lista->ElementoPpio();
	this->lista->BorrarPpio();
	return elemento;
}

template<class T>
void PilaImp2<T>::Vaciar()
{
	this->lista->Vaciar();
}

template<class T>
unsigned int PilaImp2<T>::CantidadElementos() const
{
	return this->lista->CantidadElementos();
}

template<class T>
bool PilaImp2<T>::EsVacia() const
{
	return this->lista->EsVacia();
}

template<class T>
bool PilaImp2<T>::EsLlena() const
{
	return false;
}

template<class T>
bool PilaImp2<T>::operator==(const Pila<T>& p) const
{
	Pila<T>* l1 = this->Clon();
	Pila<T>* l2 = p.Clon();
	bool sonIguales = true;
	while (!l1->EsVacia() && !l2->EsVacia() && sonIguales) {
		sonIguales = l1->Top() == l2->Top();
		l1->Pop();
		l2->Pop();
	}
	if (sonIguales) {
		sonIguales = !l1->EsVacia() && !l2->EsVacia();
	}
	delete l1;
	delete l2;
	return sonIguales;
}

template<class T>
void PilaImp2<T>::Imprimir(ostream & o) const
{
	this->lista->Imprimir(o);
}

#endif
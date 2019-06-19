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
	// TODO: insertar una instrucción return aquí
	return *this;
}

template<class T>
Pila<T>& PilaImp2<T>::operator=(const PilaImp2<T>& p)
{
	// TODO: insertar una instrucción return aquí
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
	// TODO: insertar una instrucción return aquí
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
	return false;
}

template<class T>
void PilaImp2<T>::Imprimir(ostream & o) const
{
	this->lista->Imprimir(o);
}

#endif
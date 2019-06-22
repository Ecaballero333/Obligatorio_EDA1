#include "PilaAcotadaEspecial.h"
#ifndef PilaAcotadaEspecial_CPP
#define PilaAcotadaEspecial_CPP

template<class T>
PilaAcotadaEspecial<T>::PilaAcotadaEspecial(int maxCantidadElementos)
{
	this->lista = new ListaPosImp<T>();
	this->maximaCantidadElementos = maxCantidadElementos;
}

template<class T>
PilaAcotadaEspecial<T>::PilaAcotadaEspecial(const Pila<T>& p)
{
	this->lista = new ListaPosImp<T>();
	*this = p;
}



template<class T>
PilaAcotadaEspecial<T>::PilaAcotadaEspecial(const PilaAcotadaEspecial<T>& p)
{
	this->lista = new ListaPosImp<T>();
	*this = p;
}

template<class T>
Pila<T>& PilaAcotadaEspecial<T>::operator=(const Pila<T>& p)
{
	Pila<T>* clon = p.Clon();
	while (!clon->EsVacia()) {
		this->lista->AgregarFin(clon->Pop());
	}
	return *this;
}

template<class T>
Pila<T>& PilaAcotadaEspecial<T>::operator=(const PilaAcotadaEspecial<T>& p)
{
	this->maximaCantidadElementos = p.maximaCantidadElementos;
	*this->lista = *p.lista;
	return *this;
}

template<class T>
PilaAcotadaEspecial<T>::~PilaAcotadaEspecial()
{
	delete this -> lista;
}

template<class T>
Pila<T>* PilaAcotadaEspecial<T>::CrearVacia() const
{
	return new PilaAcotadaEspecial(1);
}

template<class T>
Pila<T>* PilaAcotadaEspecial<T>::Clon() const
{
	Pila<T>* clon = new PilaAcotadaEspecial(*this);
	return clon;
}

template<class T>
void PilaAcotadaEspecial<T>::Push(const T & e)
{
	if (this->EsLlena()) {
		this->lista->BorrarFin();
	}
	this->lista->AgregarPpio(e);
}

template<class T>
T & PilaAcotadaEspecial<T>::Top() const
{
	return this->lista->ElementoPpio();
}

template<class T>
T PilaAcotadaEspecial<T>::Pop()
{
	T elemento = this->lista->ElementoPpio();
	this->lista->BorrarPpio();
	return elemento;
}

template<class T>
void PilaAcotadaEspecial<T>::Vaciar()
{
	this->lista->Vaciar();
}

template<class T>
unsigned int PilaAcotadaEspecial<T>::CantidadElementos() const
{
	return this->lista->CantidadElementos();
}

template<class T>
bool PilaAcotadaEspecial<T>::EsVacia() const
{
	return this->lista->EsVacia();
}

template<class T>
bool PilaAcotadaEspecial<T>::EsLlena() const
{
	return this->maximaCantidadElementos == this->CantidadElementos();
}

template<class T>
bool PilaAcotadaEspecial<T>::operator==(const Pila<T>& p) const
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
void PilaAcotadaEspecial<T>::Imprimir(ostream & o) const
{
	this->lista->Imprimir(o);
}

#endif
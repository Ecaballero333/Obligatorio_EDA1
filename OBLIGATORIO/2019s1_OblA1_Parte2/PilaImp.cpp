#include "PilaImp.h"

#ifndef PILAIMP_CPP
#define PILAIMP_CPP

template <class T>
inline ostream &operator<<(ostream& out, const PilaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
PilaImp<T>::PilaImp() {
	this->tope = new NodoListaT<T>();
	this->cantElementos = 0;
}

template<class T>
PilaImp<T>::PilaImp(const Pila<T>& p) {
	//this->tope = NULL;
	//this->cantElementos = 0;
	*this = p;
}

template<class T>
PilaImp<T>::PilaImp(const PilaImp<T>& p) {
	//this->cantElementos = 0;
	//this->tope = this->copiarListaRec(p.tope);
	*this = p;
}

template<class T>
Pila<T>& PilaImp<T>::operator=(const Pila<T>& p) {
	if (this != &p){
		this->Vaciar();
		Pila<T>* invertida = CrearVacia();
		Pila<T>* auxP = p.Clon();
		while (!auxP->EsVacia()) {
			invertida->Push(auxP->Top());
			auxP->Pop();
		}
		while (!invertida->EsVacia()) {
			this->Push(invertida->Top());
			invertida->Pop();
		}
		delete invertida;
		delete auxP;
	}
	return *this;
}

template<class T>
Pila<T>& PilaImp<T>::operator=(const PilaImp<T>& p) {
	if (this != &p){
		this->Vaciar();
		this->tope = this->copiarListaRec(p.tope);
	}
	return *this;
}

template<class T>
bool PilaImp<T>::operator==(const Pila<T> &p) const{
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
PilaImp<T>::~PilaImp() {
	this->Vaciar();
}

template<class T>
Pila<T>* PilaImp<T>::CrearVacia() const {
	return new PilaImp<T>();
}

template<class T>
void PilaImp<T>::Push(const T& e) {
	T aux = e;
	this->insertarPrimero(this->tope, e);
	this->cantElementos++;
}

template<class T>
T& PilaImp<T>::Top() const {
	return this->tope->dato;
}

template<class T>
T PilaImp<T>::Pop() {
	NodoListaT<T>* aux = tope;
	T retorno = tope->dato;
	tope = tope->sig;
	delete aux;
	this->cantElementos--;
	return retorno;
}

template<class T>
void PilaImp<T>::Vaciar() {
	while (!EsVacia())
		Pop();
	
}

template<class T>
unsigned int PilaImp<T>::CantidadElementos() const {
	return this->cantElementos;
}

template<class T>
bool PilaImp<T>::EsVacia() const {
	return tope == NULL;
}

template <class T>
bool PilaImp<T>::EsLlena() const{
	return false;
}

template<class T>
Pila<T>* PilaImp<T>::Clon() const {
	return new PilaImp<T>(*this);
}

template<class T>
void PilaImp<T>::Imprimir(ostream & o) const
{
	Pila<T> * p = Clon();
	while (!p->EsVacia())
	{
		o << p->Top() << " - ";
		p->Pop();
	}
	delete p;
	o << "Cantidad elementos = "<< this->cantElementos << endl;
}

template<class T>
NodoListaT<T> * PilaImp<T>::copiarListaRec(NodoListaT<T>* nodo)
{
	if (nodo == NULL)
		return NULL;
	else
	{
		NodoListaT<T>* ret = new NodoListaT<T>(nodo->dato);
		ret->sig = copiarListaRec(nodo->sig);
		this->cantElementos++;
		return ret;
	}
}

template <class T>
NodoListaT<T>* PilaImp<T>::crearNodo(T dato) {
	NodoListaT<T>* nuevo = new NodoListaT<T>(dato);
	return nuevo;
}

template <class T>
void PilaImp<T>::insertarPrimero(NodoListaT<T>*& lista, T dato) {
	NodoListaT<T>* nuevo = crearNodo(dato);
	nuevo->sig = lista;
	lista = nuevo;
}

#endif
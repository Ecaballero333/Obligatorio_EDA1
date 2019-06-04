 #include "ColaImp.h"

#ifndef COLAIMP_CPP
#define COLAIMP_CPP

template <class T>
ostream &operator<<(ostream& out, const ColaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
ColaImp<T>::ColaImp(){
	this->primero = NULL;
	this->ultimo = NULL;
	this->cantElementos = 0;
}

template <class T>
ColaImp<T>::ColaImp(const Cola<T> &c){
	this->primero = NULL;
	this->ultimo = NULL;
	this->cantElementos = 0;
	*this = c;
}

template <class T>
ColaImp<T>::ColaImp(const ColaImp<T> &c){
	this->primero = NULL;
	this->ultimo = NULL;
	this->cantElementos = 0;
	*this = c;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const Cola<T> &c){
	if (this != &c) {
		this->Vaciar();
		Cola<T>* auxC = c.Clon();
		
		while (!auxC->EsVacia()) {
			this->Encolar(auxC->Desencolar());
		}

		delete auxC;
	}
	return *this;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const ColaImp<T> &c){
	// NO IMPLEMENTADA
	return *this;
}

template <class T>
bool ColaImp<T>::operator==(const Cola<T>& c) const{
	
	bool iguales = true;
	Cola<T>* l1 = this->Clon();
	Cola<T>* l2 = p.Clon();

	while (!l1->EsVacia() && !l2->EsVacia() && iguales) {
		iguales = l1->Desencolar() == l2->Desencolar();
	}

	if (iguales) {
		iguales = !l1->EsVacia() && !l2->EsVacia();
	}

	delete l1;
	delete l2;
	return iguales;
}

template <class T>
ColaImp<T>::~ColaImp(){
	Vaciar();
}

template<class T>
Cola<T>* ColaImp<T>::CrearVacia() const {
	return new ColaImp<T>();
}

template <class T>
void ColaImp<T>::Encolar(const T &e){
	T aux = e;
	this->insertarPrimero(this->primero, e);
	this->cantElementos++;
}

template <class T>
T& ColaImp<T>::Principio()const{
	
	return *primero;
}

template <class T>
T ColaImp<T>::Desencolar(){
	NodoListaT<T>* aux = ultimo;
	T retorno = ultimo->dato;
	ultimo = ultimo->sig;
	delete aux;
	this->cantElementos--;
	return retorno;
}

template <class T>
void ColaImp<T>::Vaciar(){
	while (!EsVacia()) {
		Desencolar();
	}
}

template <class T>
unsigned int ColaImp<T>::CantidadElementos()const{

	return cantElementos;
}

template <class T>
bool ColaImp<T>::EsVacia() const{
	return (primero == NULL && ultimo == NULL);
}

template <class T>
bool ColaImp<T>::EsLlena() const{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
Cola<T>* ColaImp<T>::Clon()const{
	return new ColaImp<T>(*this);
}

template <class T>
void ColaImp<T>::Imprimir(ostream& o)const{
	Cola<T>* p = Clon();
	while (!p->EsVacia())
	{
		o << p->Principio() << " - ";
		p->Desencolar();
	}
	delete p;
	o << "Cantidad elementos = " << this->cantElementos << endl;
}

template <class T>
NodoListaT<T>* ColaImp<T>::crearNodo(T dato) {
	NodoListaT<T>* nuevo = new NodoListaT<T>(dato);
	return nuevo;
}
template <class T>
void ColaImp<T>::insertarPrimero(NodoListaT<T>*& lista, T dato) {
	NodoListaT<T>* nuevo = crearNodo(dato);
	nuevo->sig = lista;
	lista = nuevo;
}

#endif
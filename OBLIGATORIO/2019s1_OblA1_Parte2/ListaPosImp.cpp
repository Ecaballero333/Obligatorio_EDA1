#include "ListaPosImp.h"

#ifndef LISTAPOSIMP_CPP
#define LISTAPOSIMP_CPP

//Como hago una prueba?
//importa el orden de las funciones?

template <class T>
inline ostream & operator<<(ostream &out, const ListaPosImp<T> &l)
{
	l.Imprimir(out);
	return out; 
}

template <class T>
ListaPos<T>* ListaPosImp<T>::CrearVacia() const
{
	return new ListaPosImp<T>();
}

template <class T>
ListaPosImp<T>::ListaPosImp()
{
	this->tamanoVec = 1;
	this->cantElem = 0;
	this->vec = new T[this->tamanoVec]();
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPos<T> &l)
{
	this->tamanoVec = l.CantidadElementos();
	this->cantElem = l.CantidadElementos();
	this->vec = new T[l.CantidadElementos()]();
	*this = l;
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPosImp<T> &l)
{
	this->tamanoVec = l.tamanoVec;
	this->cantElem = l.cantElem;
	this->vec = l.vec;
}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPos<T> &l)
{
	if (this != &l) {
		this->Vaciar();
		for (Iterador<T> i = l.GetIterador(); !i.EsFin();) {
			this->AgregarFin(i.Elemento());
			i++;
		}
	}
	return *this;
}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPosImp<T> &l)
{
	if (this != &l) {
		this->Vaciar();
		for (int i = 0; i < l.cantElem; i++) {
			T elementoPos = l.ElementoPos(i);
			this->AgregarFin(elementoPos);
		}
	}
	return *this;
}

template <class T>
ListaPosImp<T>::~ListaPosImp()
{
	delete[] this->vec;
	this->tamanoVec = 0;
	this->cantElem = 0;
}

template <class T>
void ListaPosImp<T>::AgregarPpio(const T &e) 
{
	this->AgregarPos(e, 0);
}

template <class T>
void ListaPosImp<T>::AgregarFin(const T &e) 
{
	this->AgregarPos(e, this->cantElem);
}

template <class T>
void ListaPosImp<T>::AgregarPos(const T &e, unsigned int pos)
{
	this->agrandarSiLleno();
	if (pos >= this->cantElem) {
		this->vec[this->cantElem] = e;
	} else {		
		this->desplazar(pos);
		this->vec[pos] = e;
	}
	this->cantElem++;

}

template <class T>
void ListaPosImp<T>::BorrarPpio()
{
	BorrarPos(0);
}

template <class T>
void ListaPosImp<T>::BorrarFin()
{
	if (this->cantElem > 0) {
		this->cantElem--;
	}
}

template <class T>
void ListaPosImp<T>::BorrarPos(unsigned int pos)
{
	if (pos < this->tamanoVec) {
		for (int i = pos; i < this->cantElem - 1; i++)
		{
			this->vec[i] = this->vec[i + 1];
		}
		this->BorrarFin();
	}
}

template <class T>
void ListaPosImp<T>::Borrar(const T &e)
{
	int pos = Posicion(e);
	if(pos>0 && pos<cantElem){
		BorrarPos(pos);
	}
}

template <class T>
T& ListaPosImp<T>::ElementoPpio() const
{
	return this->vec[0];
}

template <class T>
T& ListaPosImp<T>::ElementoFin() const
{
	return this->vec[this->cantElem-1];
}

template <class T>
T& ListaPosImp<T>::ElementoPos(unsigned int pos) const
{
	return this->vec[pos];
}

template <class T>
unsigned int ListaPosImp<T>::Posicion(const T &e) const
{
	int posicion = -1;
	bool encontro = false;
	for (int i = 0; i < this->cantElem && !encontro; i++) {
		if (this->vec[i] == e) {
			encontro = true;
			posicion = i;
		}
	}
	return posicion;
}

template <class T>
bool ListaPosImp<T>::Existe(const T &e) const
{
	return Posicion(e)!=-1;
}

template <class T>
void ListaPosImp<T>::Vaciar()
{
	this->cantElem = 0;
}
template <class T>
unsigned int ListaPosImp<T>::CantidadElementos() const
{ 
	return this->cantElem; 
}

template <class T>
bool ListaPosImp<T>::EsVacia() const
{
	return this->cantElem == 0;
}

template <class T>
bool ListaPosImp<T>::EsLlena() const
{
	return this->cantElem == this->tamanoVec;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::Clon() const
{
	ListaPos<T>* clon = new ListaPosImp<T>();
	int cont = 0;
	for (Iterador<T> i = this->GetIterador(); !i.EsFin();) {
		clon->AgregarPos(i.Elemento(), cont);
		i++;
		cont++;
	}
	return clon;
}

template <class T>
Iterador<T> ListaPosImp<T>::GetIterador() const
{
	return IteradorListaPosImp<T>(*this);
}

template <class T>
void ListaPosImp<T>::Imprimir(ostream& o) const
{
	// en luegar de hacer cout << ... poner o << ...
	for (int i = 0; i < this->cantElem; i++) {
		if (i == (cantElem - 1)) {
			o << this->vec[i];
		}
		else {
			o << this->vec[i] << " ";
		}
	}
}

template<class T>
void ListaPosImp<T>::desplazar(int pos)
{
	for (int i = this->cantElem ; i > pos; i--)
	{
		this->vec[i] = this->vec[i-1];
	}
}

template<class T>
void ListaPosImp<T>::agrandarSiLleno()
{
	if (this->cantElem == this->tamanoVec) {
		this->tamanoVec++;
		T* aux = new T[this->tamanoVec]();
		for (int i = 0; i < this->tamanoVec; i++)
		{
			aux[i] = *(new T());
		}
		for (int i = 0; i < this->tamanoVec - 1; i++)
		{
			aux[i] = this->vec[i];
		}
		this->vec = aux;
		//delete[] aux;
	}
}

#endif
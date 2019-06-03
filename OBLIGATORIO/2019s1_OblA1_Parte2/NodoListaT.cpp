#include "NodoListaT.h"

template <class T>
NodoListaT<T> * NodoListaT<T>::copiarListaRec(NodoListaT<T>* nodo, int& cantElementos)
{
	if (nodo == NULL)
		return NULL;
	else
	{
		NodoListaT<T>* ret = new NodoListaT<T>();
		ret->dato = nodo->dato;
		ret->sig = copiarListaRec(nodo->sig, cantElementos++);
		return ret;
	}
}

template <class T>
NodoListaT<T>* NodoListaT<T>::crearNodo(T dato) {
	NodoListaT<T>* nuevo = new NodoListaT<T>(dato);
	return nuevo;
}

template <class T>
void NodoListaT<T>::insertarPrimero(NodoListaT<T>*& lista, T dato) {
	NodoListaT<T>* nuevo = crearNodo(dato);
	nuevo->sig = lista;
	lista = nuevo;
}

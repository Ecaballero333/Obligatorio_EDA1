#ifndef NODOLISTAT_H
#define NODOLISTAT_H

#include <iostream>
#include <assert.h>

template <class T>
class NodoListaT {

	public:
		T dato;
		NodoListaT<T> *sig;

		//PRE: Recibe una lista simplemente encadenada
		//POS : Copia una lista encadenada de T en una nueva lista encadenada de T. 
		//Setea la cantidad de elementos que copió en el segundo parametro
		static NodoListaT<T> * copiarListaRec(NodoListaT<T>* nodo, int& cantElementos);

		//PRE:
		//POS : Crea y devuelve un nuevo nodo de lista de tipo T
		static NodoListaT<T>* crearNodo(T dato);

		//PRE:
		//POS : Crea e inserta un nodo al principio de la lista
		static void insertarPrimero(NodoListaT<T>*& lista, T dato);
};
#endif
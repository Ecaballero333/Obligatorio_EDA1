#ifndef PILAACOTADAESPECIAL_H
#define PILAACOTADAESPECIAL_H

#include "Pila.h"
#include "ListaPos.h"
#include "ListaPosImp.h"
#include "Definiciones.h"

template <class T>
class PilaAcotadaEspecial : public Pila<T> {
/*
*
*Esta es una implementación especial de pila acotada. 
*Cuando se hace Push, si está llena, primero borra el elemento final y después inserta el elemento al tope.
*Es decir, siempre se puede hacer Push.
*
*/
public:
	//Constructor por defecto
	PilaAcotadaEspecial(int maxCantidadElementos);

	//Constructor copia
	PilaAcotadaEspecial(const Pila<T> &p);
	PilaAcotadaEspecial(const PilaAcotadaEspecial<T> &p);

	//Operador de asignacion
	Pila<T> &operator=(const Pila<T> &p);
	Pila<T> &operator=(const PilaAcotadaEspecial<T> &p);


	//Documentacion en la especificacion
	virtual ~PilaAcotadaEspecial();

	Pila<T> *CrearVacia() const;
	Pila<T> *Clon() const;

	void Push(const T &e);
	T& Top() const;
	T Pop();

	void Vaciar();
	unsigned int CantidadElementos() const;
	bool EsVacia() const;
	//Para esta implementación, estar llena implica que se alcanzó la máxima cantidad de elementos. 
	bool EsLlena() const;

	bool operator==(const Pila<T> &p) const;

	void Imprimir(ostream& o) const;

private:
	ListaPos<T>* lista;
	int maximaCantidadElementos;
};

#include "PilaAcotadaEspecial.cpp"

#endif
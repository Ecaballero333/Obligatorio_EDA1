#ifndef PILAIMP2_H
#define PILAIMP2_H

#include "Pila.h"
#include "ListaPos.h"
#include "ListaPosImp.h"
#include "Definiciones.h"

template <class T>
class PilaImp2 : public Pila<T> {

public:
	//Constructor por defecto
	PilaImp2();

	//Constructor copia
	PilaImp2(const Pila<T> &p);
	PilaImp2(const PilaImp2<T> &p);

	//Operador de asignacion
	Pila<T> &operator=(const Pila<T> &p);
	Pila<T> &operator=(const PilaImp2<T> &p);


	//Documentacion en la especificacion
	virtual ~PilaImp2();

	Pila<T> *CrearVacia() const;
	Pila<T> *Clon() const;

	void Push(const T &e);
	T& Top() const;
	T Pop();

	void Vaciar();
	unsigned int CantidadElementos() const;
	bool EsVacia() const;
	bool EsLlena() const;

	bool operator==(const Pila<T> &p) const;

	void Imprimir(ostream& o) const;

private:
	ListaPos<T>* lista;
};

#include "PilaImp2.cpp"

#endif
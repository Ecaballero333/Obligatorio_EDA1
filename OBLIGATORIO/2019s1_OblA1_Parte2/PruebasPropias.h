#ifndef PRUEBASPROPIAS_H
#define PRUEBASPROPIAS_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "InterfazDelSistemaImp.h"
#include "ListaPosImp.h"
#include "Asociacion.h"
#include "Pila.h"
#include "PilaImp.h"

class PruebasPropias : public Prueba  
{

public:
	PruebasPropias(ConductorPrueba* conductor);
	virtual ~PruebasPropias();
	virtual void correrPruebaConcreta();

protected:
	virtual const char* getNombre() const;


private:
	template <class T>
	void ProbarPila(Pila<T> *p);
	ManejadorImpresionPrueba mImpresion;
	void FormarRedBasica(InterfazDelSistema* interfaz);
};

#endif
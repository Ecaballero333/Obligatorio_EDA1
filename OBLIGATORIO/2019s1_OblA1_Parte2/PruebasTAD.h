#ifndef PRUEBASTAD_H
#define PRUEBASTAD_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "Cadena.h"
#include "ListaPosImp.h"

class PruebasTAD : public Prueba  
{

public:
	PruebasTAD(ConductorPrueba* conductor);
	virtual ~PruebasTAD();
	virtual void correrPruebaConcreta();

protected:
	virtual const char* getNombre() const;

private:
	ManejadorImpresionPrueba mImpresion;

	void pruebaListaPos();
};

#endif
#ifndef EJEMPLODEUSO_H
#define EJEMPLODEUSO_H


#include "Prueba.h"
#include "ConductorPrueba.h"
#include "InterfazDelSistemaImp.h"

class PruebasEjemploDeUso : public Prueba  
{

public:
	PruebasEjemploDeUso(ConductorPrueba* conductor);
	virtual ~PruebasEjemploDeUso();
	virtual void correrPruebaConcreta();

protected:
	virtual const char* getNombre()const;

private:
	ManejadorImpresionPrueba mImpresion;

	//InterfazDelSistema* interfaz;

	void PruebasOK();
	void PruebasError();
	void PruebasOKTipo1();
	void PruebasOKRmdir();
	void PruebasOKCopydir();
	void PruebasOKDelete();
	void PruebasOKAttrib();
	void PruebasOKDeleteText();
	void PruebasOKOpcional();
	

	void PruebasErrorCrearDirectorio();
	void PruebasErrorEliminarDirectorio();
	void PruebasErrorCopiarDirectorio();
	void PruebasErrorMostrarDirectorio();
	void PruebasErrorCrearArchivo();
	void PruebasErrorEliminarArchivo();
	void PruebasErrorModificarParametros();
	void PruebasErrorInsertarTexto();
	void PruebasErrorEliminarTexto();
	void PruebasErrorMostrarArchivo();
	void PruebasErrorOpcional();

	void FormarRedBasica(InterfazDelSistema* interfaz);
	
};

#endif
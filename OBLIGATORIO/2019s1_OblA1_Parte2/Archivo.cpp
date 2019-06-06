#include "Archivo.h"


#ifndef ARCHIVO_CPP
#define ARCHIVO_CPP

Archivo::Archivo(Cadena nombre)
{
	// NO IMPLEMENTADA
}

Archivo::Archivo()
{
	this->nombre = NULL;
	this->oculto = false;
	this->lineas = NULL;

}

Archivo::~Archivo()
{
	// NO IMPLEMENTADA
}

Archivo::Archivo(const Archivo &a)
{
	this->nombre = NULL;
	this->oculto = false;
	this->lineas = NULL;
	*this = a;
}

Archivo &Archivo::operator=(const Archivo &a) 
{
	if (this != &a)
	{
		// NO IMPLEMENTADA
	}
	return *this;
}

bool Archivo::operator==(const Archivo &a) const
{
	// NO IMPLEMENTADA
	return false;
}

void Archivo::ModificarVisibilidad(Cadena nuevaVisibilidad)
{

	if (nuevaVisibilidad == "+H") { // en la letra dicen que pasan -H o +H
		oculto = true;
	}
	else {
		oculto = false;
	}

}

void Archivo::InsertarTexto(unsigned int nroLinea, unsigned int posLinea, Cadena texto)
{
	// NO IMPLEMENTADA
}


bool Archivo::TieneLineas() const
{
	if (lineas->EsVacia()) {
		return false;
	}
	else {
		return true;
	}
}

void Archivo::EliminarTexto(unsigned int nroLinea, unsigned int posLinea, unsigned int k)
{
	// NO IMPLEMENTADA
}

void Archivo::MostrarContenido() const
{
	// NO IMPLEMENTADA
}

bool Archivo::EstaOculto() const
{
	return oculto;
}

Cadena Archivo::GetNombre() const
{
	return nombre;
}


#endif
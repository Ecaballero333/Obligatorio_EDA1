#include "Archivo.h"


#ifndef ARCHIVO_CPP
#define ARCHIVO_CPP

Archivo::Archivo(Cadena nombre)
{
	// NO IMPLEMENTADA
}

Archivo::Archivo()
{
	// NO IMPLEMENTADA
}

Archivo::~Archivo()
{
	// NO IMPLEMENTADA
}

Archivo::Archivo(const Archivo &a)
{
	// NO IMPLEMENTADA
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
	// NO IMPLEMENTADA
}

void Archivo::InsertarTexto(unsigned int nroLinea, unsigned int posLinea, Cadena texto)
{
	// NO IMPLEMENTADA
}


bool Archivo::TieneLineas() const
{
	// NO IMPLEMENTADA
	return false;
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
	// NO IMPLEMENTADA
	return false;
}

Cadena Archivo::GetNombre() const
{
	// NO IMPLEMENTADA
	return "";
}


#endif
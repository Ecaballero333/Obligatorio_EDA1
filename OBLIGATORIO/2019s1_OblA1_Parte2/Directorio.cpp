#include "Directorio.h"

#ifndef DIRECTORIO_CPP
#define DIRECTORIO_CPP

Directorio::Directorio()
{
	// NO IMPLEMENTADA
}

Directorio::Directorio(Cadena nombreDirectorio)
{
	// NO IMPLEMENTADA
}

Directorio::~Directorio()
{
	// NO IMPLEMENTADA
}

Directorio::Directorio(const Directorio &d)
{
	// NO IMPLEMENTADA
}

bool Directorio::operator<(const Directorio &d) const
{
	// NO IMPLEMENTADA
	return false;
}

bool Directorio::operator==(const Directorio &d) const
{
	// NO IMPLEMENTADA
	return false;
}

Directorio &Directorio::operator=(const Directorio&d) 
{
	if (this != &d) 
	{
		// NO IMPLEMENTADA
	}
	return *this;
}

void Directorio::AgregarArchivo(Cadena nombreArchivo)
{
	// NO IMPLEMENTADA
}

void Directorio::AgregarArchivo(const Archivo &archivo)
{
	// NO IMPLEMENTADA
}

void Directorio::EliminarArchivo(Cadena nombreArchivo)
{
	// NO IMPLEMENTADA
}

void Directorio::EliminarArchivos()
{
	// NO IMPLEMENTADA
}

bool Directorio::ExisteArchivo(Cadena nombreArchivo) const
{
	// NO IMPLEMENTADA
	return false;
}

bool Directorio::ContieneArchivos() const
{
	// NO IMPLEMENTADA
	return false;
}

// DESCOMENTAR FUNCION EN .cpp y .h LUEGO DE IMPLEMENTAR
//Archivo &Directorio::BuscarArchivo(Cadena nombreArchivo) const
//{
	// NO IMPLEMENTADA
//}

Cadena Directorio::GetNombre() const
{
	// NO IMPLEMENTADA
	return "";
}

void Directorio::SetNombre(Cadena nombre)
{
	// NO IMPLEMENTADA
}

void Directorio::ListarArchivos(Cadena ruta, Cadena parametro) const
{
	// NO IMPLEMENTADA
}

#endif
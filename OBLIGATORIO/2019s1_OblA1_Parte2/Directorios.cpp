#include "Directorios.h"


#ifndef DIRECTORIOS_CPP
#define DIRECTORIOS_CPP

Directorios::Directorios()
{
	Cadena* nombreDirectorioRaiz = new Cadena("/");
	this->arbolDirectorios = new NodoAG<Directorio>(*nombreDirectorioRaiz, nullptr, nullptr);
}

Directorios::~Directorios()
{
	// NO IMPLEMENTADA
}

Directorios::Directorios(const Directorios &d)
{
	// NO IMPLEMENTADA
}

Directorios &Directorios::operator=(const Directorios &d) 
{
	if (this != &d)
	{
		// NO IMPLEMENTADA
		assert(false);
	}
	return *this;
}

void Directorios::AgregarDirectorio(Cadena ruta)
{
	// NO IMPLEMENTADA
}

void Directorios::EliminarDirectorio(Cadena ruta)
{
	// NO IMPLEMENTADA
}

bool Directorios::ExisteDirectorio(Cadena ruta) const
{
	// NO IMPLEMENTADA
	return false;
}

// DESCOMENTAR FUNCION EN .cpp y .h LUEGO DE IMPLEMENTAR
//Directorio &Directorios::BuscarDirectorio(Cadena ruta) const
//{
	// NO IMPLEMENTADA
//}

void Directorios::Dir(Cadena ruta, Cadena parametro) const
{
	// NO IMPLEMENTADA
}

void Directorios::Vaciar()
{
	// NO IMPLEMENTADA
}

void Directorios::CopiarDirectorio(Cadena rutaOrigen, Cadena rutaDestino)
{
	// NO IMPLEMENTADA
}


#endif
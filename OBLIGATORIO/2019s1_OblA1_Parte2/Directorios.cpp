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
	this->Vaciar();
	delete this->arbolDirectorios;
}

Directorios::Directorios(const Directorios &d)
{
	*this = d;
}

Directorios &Directorios::operator=(const Directorios &d) 
{
	if (this != &d)
	{
		this->Vaciar();		
		this->arbolDirectorios = this->CopiarArbolDirectorios(d.arbolDirectorios);
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

NodoAG<Directorio>* Directorios::CopiarArbolDirectorios(NodoAG<Directorio>* d) {
	if (d == NULL) {
		return NULL;
	}
	else {
		NodoAG<Directorio>* aux = new NodoAG<Directorio>(d->dato,NULL,NULL);
		aux->ph = CopiarArbolDirectorios(d->ph);
		aux->sh = CopiarArbolDirectorios(d->sh);
		return aux;
	}
}


#endif
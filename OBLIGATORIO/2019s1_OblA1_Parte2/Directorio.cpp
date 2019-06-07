#include "Directorio.h"

#ifndef DIRECTORIO_CPP
#define DIRECTORIO_CPP


Directorio::Directorio()
{
	this->nombre = nullptr;
	this->archivos = new ListaOrdImp<Archivo>();
}

Directorio::Directorio(Cadena nombreDirectorio)
{
	*this->nombre = nombreDirectorio;
	this->archivos = new ListaOrdImp<Archivo>();
}

Directorio::~Directorio()
{
	this->nombre = nullptr;
	this->EliminarArchivos();
}

Directorio::Directorio(const Directorio &d)
{
	this->nombre = nullptr;
	this->archivos = nullptr;
	*this = d;
}

bool Directorio::operator<(const Directorio &d) const
{

	return *this->nombre < *d.nombre;
}

bool Directorio::operator==(const Directorio &d) const
{
	bool sonIguales = *this->nombre == *d.nombre;
	if (sonIguales) {
		//ListaOrd<Archivo>* copiaArchivosThis = this->archivos->Clon();
		//ListaOrd<Archivo>* copiaArchivosParam = d.archivos->Clon();
		Iterador<Archivo> itArchivosThis = this->archivos->GetIterador();
		Iterador<Archivo> itArchivosParam = d.archivos->GetIterador();

		while (!itArchivosThis.EsFin() && !itArchivosParam.EsFin() && sonIguales)
		{
			
			sonIguales = itArchivosThis.Elemento() == itArchivosParam.Elemento();
			itArchivosThis++;
			itArchivosParam++;
		}
		if (sonIguales) 
		{
			sonIguales = itArchivosThis.EsFin() && itArchivosParam.EsFin();
		}
		return sonIguales;

	}
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
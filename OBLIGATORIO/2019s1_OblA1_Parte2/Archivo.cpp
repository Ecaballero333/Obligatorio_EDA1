#include "Archivo.h"


#ifndef ARCHIVO_CPP
#define ARCHIVO_CPP

Archivo::Archivo(Cadena nombre)
{
	this->nombre = nombre;
	this->oculto = false;
	this->lineas = NULL;
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

	if (nuevaVisibilidad == "+H") { // en la letra dice que pasan -H o +H
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
	int n = 1;
	ListaPos<Cadena>* aux = lineas;

	while (!aux->EsVacia()) {

		cout << n <<": " << aux->ElementoPos(n-1); // empieza en 0 y n en 1
		aux->BorrarPpio();
		n++;
	}
	
	delete aux;
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
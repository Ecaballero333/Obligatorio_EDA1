#include "Archivo.h"


#ifndef ARCHIVO_CPP
#define ARCHIVO_CPP

Archivo::Archivo(Cadena nombre)
{
	this->nombre = nombre;
	this->oculto = false;
	this->lineas = nullptr;

}

Archivo::Archivo()
{
	this->nombre = nullptr;
	this->oculto = false;
	this->lineas = nullptr;


}

Archivo::~Archivo()
{
	this->nombre = nullptr;
	this->oculto = false;
	this->EliminarLineas();

}

Archivo::Archivo(const Archivo &a)
{
	this->nombre = nullptr;
	this->oculto = false;
	this->lineas = nullptr;

	*this = a;
}

Archivo &Archivo::operator=(const Archivo &a) 
{
	if (this != &a)
	{
		
		this->EliminarLineas();
		this->nombre = a.nombre;
		
		Iterador<Cadena> itLineasACopiar = a.lineas->GetIterador();
		while (!itLineasACopiar.EsFin()){
		
			Cadena cadenaCopia = itLineasACopiar.Elemento();
			this->lineas->AgregarFin(cadenaCopia);
			itLineasACopiar++;
			
		}
		
	}
	return *this;
}

bool Archivo::operator==(const Archivo &a) const
{
	bool sonIguales = this->nombre == a.nombre;
	if (sonIguales) {
		Iterador<Cadena> itCadenaThis = this->lineas->GetIterador();
		Iterador<Cadena> itCadenaParam = a.lineas->GetIterador();

		while (!itCadenaThis.EsFin() && !itCadenaParam.EsFin() && sonIguales)
		{
			sonIguales = itCadenaThis.Elemento() == itCadenaParam.Elemento();
			itCadenaThis++;
			itCadenaParam++;
		}
		if (sonIguales)
		{
			sonIguales = itCadenaThis.EsFin() && itCadenaParam.EsFin();
		}
	}

	return sonIguales;
}

bool Archivo::operator<(const Archivo &a) {
	return this->GetNombre() < a.GetNombre();
}

bool Archivo::operator<=(const Archivo &a){
	return this->GetNombre() <= a.GetNombre();
}

bool Archivo::operator>=(const Archivo &a) {
	return this->GetNombre() >= a.GetNombre();
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
	
	if (nroLinea > lineas->CantidadElementos()) {
		while (nroLinea > lineas->CantidadElementos()) {
			lineas->AgregarFin(" ");
			nroLinea++;
		}
	}
	
	Cadena nueva = lineas->ElementoPos(nroLinea-1); //nrolinea empieza en 1, lineas en 0
	
	if (nueva.Length() < posLinea) {
		while (nueva.Length() < posLinea){	
			nueva = nueva + " ";
		}
	}

	Cadena primeraMitad = nullptr;
	Cadena segundaMitad = nullptr;
	
	int n = 0;
	while (posLinea > primeraMitad.Length()) {
		primeraMitad = primeraMitad + nueva[n];
	}

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
		n++;
	}
	
	delete aux;
}

void Archivo::EliminarLineas(){

	Iterador<Cadena> itCadena= this->lineas->GetIterador();
	while (!itCadena.EsFin())
	{
		Cadena cadenaCopia = itCadena.Elemento();
		itCadena++;
		delete& cadenaCopia;
	}

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
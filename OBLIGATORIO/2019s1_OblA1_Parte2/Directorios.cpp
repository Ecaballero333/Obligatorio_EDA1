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
	NodoLista<char*>* listaRuta = rutaALista(&ruta);
	const char* nombreRaiz = "/";
	NodoLista<char*>* directorioRaiz = new NodoLista<char*>(&"/", nullptr, nullptr);
	NodoAG<Directorio>* directorio = buscarRuta(this->arbolDirectorios,listaRuta);

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

NodoLista<char*>* Directorios::rutaALista(Cadena* ruta) {
	char* copiaS = ruta->GetNewCharPtr();
	NodoLista<char*>* lista = nullptr;
	char * token = strtok(copiaS, "/");
	while (token != NULL) {		
		this->AgregarNombreDirectorioAlFinal(lista, token);
		token = strtok(NULL, "/");
	}
	delete[] copiaS;
	return lista;
}

void Directorios::AgregarNombreDirectorioAlFinal(NodoLista<char*>*& lista, char* nombreDirectorio) {
	NodoLista<char*>* nuevo = new NodoLista<char*>(nombreDirectorio,nullptr, nullptr);
	if (lista == nullptr) {
		lista = nuevo;
	}
	else {
		NodoLista<char*>* copiaLista = lista;
		while (copiaLista->sig != NULL) {
			copiaLista = copiaLista->sig;
		}
		copiaLista->sig = nuevo;
	}
}

NodoAG<Directorio>* Directorios::buscarRuta(NodoAG<Directorio>*& r, NodoLista<char*>* listaRuta){
	if (r == nullptr) {
		return r;
	}
	else {
		if (r->dato.GetNombre() == listaRuta->dato) {
			if (listaRuta->sig == nullptr) {
				return r;
			}
			else {
				return buscarRuta(r->ph, listaRuta->sig);
			}
		}
		return buscarRuta(r->sh, listaRuta);
	}
}


#endif
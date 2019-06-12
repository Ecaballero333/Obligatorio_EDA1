#include "Directorios.h"
#pragma warning(disable : 4996)

#ifndef DIRECTORIOS_CPP
#define DIRECTORIOS_CPP

Directorios::Directorios()
{
	Cadena* nombreDirectorioRaiz = new Cadena("/");
	Directorio* directorioRaiz = new Directorio(*nombreDirectorioRaiz);
	this->arbolDirectorios = new NodoAG<Directorio>(*directorioRaiz, nullptr, nullptr);
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

TipoError Directorios::AgregarDirectorio(Cadena ruta)
{
	TipoError retorno = NO_HAY_ERROR;
	NodoLista<Cadena>* listaRuta = rutaALista(&ruta);
	Cadena nombreDirectorioACrear = obtenerYBorrarUltimaCadena(listaRuta);
	NodoAG<Directorio>* nodoDirectorio = buscarRuta(this->arbolDirectorios,listaRuta);
	if (nodoDirectorio != NULL) {
		if (!this->ExisteHijoEnRuta(nodoDirectorio, nombreDirectorioACrear)) {
			Directorio* nuevoDirectorio = new Directorio(nombreDirectorioACrear);
			NodoAG<Directorio>* nuevoNodoDirectorio = new NodoAG<Directorio>(*nuevoDirectorio, nullptr, nullptr);
			if (nodoDirectorio->ph != NULL) {
				nuevoNodoDirectorio->sh = nodoDirectorio->ph;
			}
			nodoDirectorio->ph = nuevoNodoDirectorio;
		}
		else {
			retorno = ERROR_YA_EXISTE_SUBDIRECTORIO;
		}
	}
	else {
		retorno = ERROR_NO_SE_ENCUENTRA_RUTA;
	}
	return retorno;
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

NodoLista<Cadena>* Directorios::rutaALista(Cadena* ruta) {
	char* copiaS = ruta->GetNewCharPtr();
	Cadena* raiz = new Cadena("/");
	NodoLista<Cadena>* lista = new NodoLista<Cadena>(*raiz, nullptr, nullptr);
	char * token = strtok(copiaS, "/");
	while (token != NULL) {		
		this->AgregarNombreDirectorioAlFinal(lista, token);
		token = strtok(NULL, "/");
	}
	delete[] copiaS;
	return lista;
}

void Directorios::AgregarNombreDirectorioAlFinal(NodoLista<Cadena>*& lista,const char* nombreDirectorio) {
	Cadena* cadenaDir = new Cadena(nombreDirectorio);
	NodoLista<Cadena>* nuevo = new NodoLista<Cadena>(*cadenaDir,nullptr, nullptr);
	if (lista == nullptr) {
		lista = nuevo;
	}
	else {
		NodoLista<Cadena>* copiaLista = lista;
		while (copiaLista->sig != NULL) {
			copiaLista = copiaLista->sig;
		}
		copiaLista->sig = nuevo;
	}
}

NodoAG<Directorio>* Directorios::buscarRuta(NodoAG<Directorio>*& r, NodoLista<Cadena>* listaRuta){
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


Cadena Directorios::obtenerYBorrarUltimaCadena(NodoLista<Cadena>* listaRuta) {
	NodoLista<Cadena>* copia = listaRuta;
	while (copia->sig->sig != NULL) {
		copia = copia->sig;
	}
	NodoLista<Cadena>* aux = copia->sig;
	Cadena ultimaCadena = aux->dato;
	copia->sig = NULL;
	delete aux;
	return ultimaCadena;
}

bool Directorios::ExisteHijoEnRuta(NodoAG<Directorio>* nodoDirectorio, Cadena nombreDirectorio) {
	bool existe = false;
	if (nodoDirectorio->ph != NULL) {
		nodoDirectorio = nodoDirectorio->ph;
		if (nodoDirectorio->dato.GetNombre() == nombreDirectorio) {
			existe = true;
		}
		else {
			while (nodoDirectorio->sh!=NULL && !existe) {
				nodoDirectorio = nodoDirectorio->sh;
				if (nodoDirectorio->dato.GetNombre() == nombreDirectorio) {
					existe = true;
				}
			}
		}
	}
	return existe;
}

#endif
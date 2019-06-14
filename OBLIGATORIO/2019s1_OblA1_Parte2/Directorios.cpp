#include "Directorios.h"
#pragma warning(disable : 4996)

#ifndef DIRECTORIOS_CPP
#define DIRECTORIOS_CPP

Directorios::Directorios()
{
	Cadena* nombreDirectorioRaiz = new Cadena("/");
	Directorio* directorioRaiz = new Directorio(*nombreDirectorioRaiz, 0);
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
	TipoError retorno = this->ValidacionesPorOperacion(MKDIR, ruta, "");
	if (retorno == NO_HAY_ERROR) {
		NodoLista<Cadena>* listaRuta = rutaALista(&ruta);
		Cadena nombreDirectorioACrear = obtenerYBorrarUltimaCadena(listaRuta);
		NodoAG<Directorio>* nodoDirectorio = buscarRuta(this->arbolDirectorios, listaRuta);
		if (nodoDirectorio == NULL) {
			retorno = ERROR_NO_SE_ENCUENTRA_RUTA;
		} else {
			if (this->ExisteHijoEnRuta(nodoDirectorio, nombreDirectorioACrear)) {
				retorno = ERROR_YA_EXISTE_SUBDIRECTORIO;
			} else {
				int nivelNuevoDirectorio = listaRuta->Length();
				Directorio* nuevoDirectorio = new Directorio(nombreDirectorioACrear, nivelNuevoDirectorio);
				NodoAG<Directorio>* nuevoNodoDirectorio = new NodoAG<Directorio>(*nuevoDirectorio, nullptr, nullptr);
				if (nodoDirectorio->ph != NULL) {
					nuevoNodoDirectorio->sh = nodoDirectorio->ph;
				}
				nodoDirectorio->ph = nuevoNodoDirectorio;
			}
		}
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

TipoError Directorios::Dir(Cadena ruta, Cadena parametro)
{
	TipoError retorno = this->ValidacionesPorOperacion(DIR, ruta, parametro);
	if (retorno == NO_HAY_ERROR) {
		NodoLista<Cadena>* listaRuta = rutaALista(&ruta);
		NodoAG<Directorio>* nodoDirectorio = buscarRuta(this->arbolDirectorios, listaRuta);
		if (nodoDirectorio == NULL) {
			retorno = ERROR_NO_SE_ENCUENTRA_RUTA;
		} else {
			this->ListarDirectorios(nodoDirectorio, ruta, parametro);
		}
	}
	return retorno;
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

TipoError Directorios::ValidacionesPorOperacion(TipoOperacion nombreOperacion, Cadena ruta, Cadena parametro)
{
	TipoError retorno = NO_HAY_ERROR;
	if (nombreOperacion == MKDIR) {
		if (this->rutaComienzaMal(ruta)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
		}
		else if (this->directorioRaizDuplicado(ruta)) {
			retorno = ERROR_NO_SE_PUEDE_CREAR_DIR_RAIZ;
		}
		else if (this->directorioNombreIncorrecto(ruta)) {
			retorno = ERROR_DIRECTORIO_NOMBRE_INCORRECTO;
		}
	}
	if (nombreOperacion == DIR) {
		if (this->rutaComienzaMal(ruta)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
		}
		if (parametro != "" && parametro != "-H") {
			retorno = ERROR_PARAMETRO_DESCONOCIDO;
		}
	}
	return retorno;
}

bool Directorios::rutaComienzaMal(Cadena ruta) {
	return ruta[0] != *barra;
}

bool Directorios::directorioRaizDuplicado(Cadena ruta) {
	return ruta[0] == *barra && ruta.Length() == 1;
}

bool Directorios::directorioNombreIncorrecto(Cadena ruta) {
	const char* dobleBarra = "//";
	Cadena* cadDobleBarra = new Cadena(dobleBarra, true);
	const char* punto = ".";
	Cadena* cadPunto = new Cadena(punto, true);
	bool retorno = ruta.Contains(*cadDobleBarra) || ruta.Contains(*cadPunto);
	delete[] cadDobleBarra;
	delete[] cadPunto;
	return retorno;
}

void Directorios::ListarDirectorios(NodoAG<Directorio>* nodoDirectorio, Cadena ruta, Cadena parametro) {
	//cout << "DIR " << ruta << parametro << endl;
	cout << ruta << endl;
	nodoDirectorio->dato.ListarArchivos(ruta, parametro);
	nodoDirectorio = nodoDirectorio->ph;//Lo avanzo uno para que busque solo directorios descendientes, no hermanos
	ListaOrd<Asociacion<Cadena, Directorio>>* listaRutasDirectorios = new ListaOrdImp<Asociacion<Cadena, Directorio>>();
	this->obtenerListaOrdenadaTodoslLosDirectorios(nodoDirectorio, ruta, listaRutasDirectorios);
	Iterador<Asociacion<Cadena, Directorio>> itListaDirectorios = listaRutasDirectorios->GetIterador();
	while (!itListaDirectorios.EsFin()){
		cout << itListaDirectorios.Elemento().GetDominio() << endl;	
		itListaDirectorios.Elemento().GetRango().ListarArchivos(ruta, parametro);
		itListaDirectorios++;
	}
	delete listaRutasDirectorios;
}

void Directorios::obtenerListaOrdenadaTodoslLosDirectorios(NodoAG<Directorio>* nodoDirectorio, Cadena ruta, ListaOrd<Asociacion<Cadena,Directorio>>*& listaRutasDirectorios) {
	if (nodoDirectorio !=NULL){
		Cadena nuevaRuta = ruta + nodoDirectorio->dato.GetNombre() + "/";
		Directorio directorio = nodoDirectorio->dato;
		Asociacion<Cadena, Directorio>* rutaDirectorio = new Asociacion<Cadena, Directorio>(nuevaRuta, directorio);
		listaRutasDirectorios->AgregarOrd(*rutaDirectorio);
		obtenerListaOrdenadaTodoslLosDirectorios(nodoDirectorio->ph, nuevaRuta, listaRutasDirectorios);
		obtenerListaOrdenadaTodoslLosDirectorios(nodoDirectorio->sh, ruta, listaRutasDirectorios);
	}
}



#endif
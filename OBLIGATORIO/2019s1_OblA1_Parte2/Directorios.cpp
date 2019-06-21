#include "Directorios.h"
#pragma warning(disable : 4996)

#ifndef DIRECTORIOS_CPP
#define DIRECTORIOS_CPP

Directorios::Directorios()
{
	Cadena* nombreDirectorioRaiz = new Cadena("/");
	Directorio* directorioRaiz = new Directorio(*nombreDirectorioRaiz, 0);
	this->arbolDirectorios = new NodoAG<Directorio>(*directorioRaiz, nullptr, nullptr);
	this->maximoRecupera = 0;
	this->listaUndeleteArchivos = new PilaImp2<Asociacion<Cadena,Archivo>>();
}

Directorios::Directorios(unsigned int MAX_RECUPERAR)
{
	Cadena* nombreDirectorioRaiz = new Cadena("/");
	Directorio* directorioRaiz = new Directorio(*nombreDirectorioRaiz, 0);
	this->arbolDirectorios = new NodoAG<Directorio>(*directorioRaiz, nullptr, nullptr);
	this->maximoRecupera = MAX_RECUPERAR;
	this->listaUndeleteArchivos = new PilaImp2<Asociacion<Cadena, Archivo>>();
}

Directorios::~Directorios()
{
	this->Vaciar();
	delete this->arbolDirectorios;
	delete this->listaUndeleteArchivos;
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

TipoError Directorios::AgregarArchivo(Cadena ruta) {

	TipoError retorno = this->ValidacionesPorOperacion(CREATEFILE, ruta, "", "");
	if (retorno == NO_HAY_ERROR) {
				
		if (!ExisteDirectorio(ruta, true)) {
			retorno = ERROR_NO_SE_ENCUENTRA_RUTA;
		}
		else {
			Cadena nombreArchivoACrear = "";
			NodoAG<Directorio> *nodoDirectorio = this->BuscarNodoDirectorio(ruta, true, nombreArchivoACrear);
			if (nodoDirectorio->dato.ExisteArchivo(nombreArchivoACrear)) {
				retorno = ERROR_YA_EXISTE_ARCHIVO;
			}
			else {				
				Archivo* nuevoArchivo = new Archivo(nombreArchivoACrear);
				nodoDirectorio->dato.AgregarArchivo(*nuevoArchivo);
			}
		}

	}
	return retorno;
}

TipoError Directorios::Type(Cadena ruta) {
	TipoError retorno = this->ValidacionesPorOperacion(TYPE, ruta, "", "");
	if (retorno == NO_HAY_ERROR) {	
		if (!ExisteDirectorio(ruta, true)) {
			retorno = ERROR_NO_SE_ENCUENTRA_RUTA;
		}
		if (retorno == NO_HAY_ERROR) {
			Cadena nombreArchivo = "";
			NodoAG<Directorio> *nodoDirectorio = this->BuscarNodoDirectorio(ruta, true, nombreArchivo);
			if (!nodoDirectorio->dato.ExisteArchivo(nombreArchivo)) {
				retorno = ERROR_NO_EXISTE_ARCHIVO_NOMBRE_EN_RUTA;
			}
			else {
				Archivo archivo = nodoDirectorio->dato.BuscarArchivo(nombreArchivo);
				cout << ruta << endl;
				cout << "" << endl;
				if (!archivo.EstaOculto()) {
					if (!archivo.TieneLineas()) {
						cout << "El archivo no posee contenido" << endl;
					}
					else {
						archivo.MostrarContenido();
					}
				}
				else {
					cout << "El archivo esta oculto" << endl;
				}
			}

		}

	}
	return retorno;
}

TipoError Directorios::DeleteText(Cadena rutaArchivo, unsigned int linea, unsigned int posicion, unsigned int k) {

	TipoError retorno = this->ValidacionesPorOperacion(DELETETEXT, rutaArchivo, "", "");
	if (retorno == NO_HAY_ERROR) {
		if (!ExisteDirectorio(rutaArchivo, true)) {
			retorno = ERROR_NO_SE_ENCUENTRA_RUTA;
		}
		if (linea == 0) {
			retorno = ERROR_LINEA_CERO_NO_VALIDA;
		}
		if (posicion == 0) {
			retorno = ERROR_POSICION_CERO_NO_VALIDA;
		}
		if (retorno == NO_HAY_ERROR) {

			Cadena nombreArchivo = "";
			NodoAG<Directorio> *nodoDirectorio = BuscarNodoDirectorio(rutaArchivo, true, nombreArchivo);
			if (!nodoDirectorio->dato.ExisteArchivo(nombreArchivo)) {
				retorno = ERROR_NO_EXISTE_ARCHIVO_NOMBRE_EN_RUTA;
			}
			else {
				Archivo archivo = nodoDirectorio->dato.BuscarArchivo(nombreArchivo);
				if (archivo.CantidadValidaLineas(k)) {
					retorno = ERROR_LINEA_NO_EXISTE;
				}
				else {
					archivo.EliminarTexto(linea, posicion, k);
				}
			}
		}
	}
	return retorno;

} 

TipoError Directorios::InsertText(Cadena rutaArchivo, unsigned int linea, unsigned int posicion, Cadena texto) {

	TipoError retorno = this->ValidacionesPorOperacion(INSERTTEXT, rutaArchivo, "", "");
	if (retorno == NO_HAY_ERROR) {
		if (!ExisteDirectorio(rutaArchivo, true)) {
			retorno = ERROR_NO_SE_ENCUENTRA_RUTA;
		}	
		if (linea == 0) {
			retorno = ERROR_LINEA_CERO_NO_VALIDA;
		}
		if (posicion == 0) {
			retorno = ERROR_POSICION_CERO_NO_VALIDA;
		}
		if (retorno == NO_HAY_ERROR) {

			Cadena nombreArchivo = "";
			NodoAG<Directorio> *nodoDirectorio = this->BuscarNodoDirectorio(rutaArchivo, true, nombreArchivo);
			if (!nodoDirectorio->dato.ExisteArchivo(nombreArchivo)) {
				retorno = ERROR_NO_EXISTE_ARCHIVO_NOMBRE_EN_RUTA;
			}
			else {
				Archivo &archivo = nodoDirectorio->dato.BuscarArchivo(nombreArchivo);
				archivo.InsertarTexto(linea, posicion, texto);
			}
		}
	}
	return retorno;
}

TipoError Directorios::AgregarDirectorio(Cadena ruta)
{
	TipoError retorno = this->ValidacionesPorOperacion(MKDIR, ruta, "", "");
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

TipoError Directorios::EliminarDirectorio(Cadena ruta)
{
	TipoError retorno = this->ValidacionesPorOperacion(RMDIR, ruta, "", "");
	NodoLista<Cadena>* listaRuta = rutaALista(&ruta);
	if (listaRuta->Length() == 1) {
		//Se eligió eliminar todos los directorios (y sus archivos) excepto el raiz "/"
		this->Vaciar();
	}
	else {
		NodoAG<Directorio>* nodoEliminar = buscarRuta(this->arbolDirectorios, listaRuta);
		Cadena nombreDirectorioAEliminar = obtenerYBorrarUltimaCadena(listaRuta);
		NodoAG<Directorio>* nodoPadre = buscarRuta(this->arbolDirectorios, listaRuta);
		if (nodoEliminar == NULL) {
			retorno = ERROR_NO_SE_ENCUENTRA_RUTA;
		}
		else {
			//El nodo a eliminar puede ser el primer hijo del nodo padre
			if (nodoPadre->ph->dato == nodoEliminar->dato) {
				this->EliminarDirectorioPrimerHijo(nodoPadre);
			}
			else {
				this->EliminarDirectorioSiguienteHermano(nodoPadre, nombreDirectorioAEliminar);
			}
		}
	}
	return retorno;
}

bool Directorios::ExisteDirectorio(Cadena ruta, bool descartarUltimaParte)
{
	NodoLista<Cadena>* listaRuta = rutaALista(&ruta);
	if (descartarUltimaParte) {
		obtenerYBorrarUltimaCadena(listaRuta);
	}
	NodoAG<Directorio>* nodoDirectorio = buscarRuta(this->arbolDirectorios, listaRuta);
	return(nodoDirectorio != NULL);
}


NodoAG<Directorio> *Directorios::BuscarNodoDirectorio(Cadena ruta, bool descartarUltimaParte, Cadena& ultimParte)
{
	NodoLista<Cadena>* listaRuta = rutaALista(&ruta);
	if (descartarUltimaParte) {
		ultimParte = obtenerYBorrarUltimaCadena(listaRuta);
	}
	NodoAG<Directorio>* nodoDirectorio = buscarRuta(this->arbolDirectorios, listaRuta);
	return nodoDirectorio;
}

TipoError Directorios::Dir(Cadena ruta, Cadena parametro)
{
	TipoError retorno = this->ValidacionesPorOperacion(DIR, ruta,"",parametro);
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
	this->arbolDirectorios->dato.EliminarArchivos();
	this->EliminarTodo(this->arbolDirectorios->ph);
	this->listaUndeleteArchivos->Vaciar();
}

TipoError Directorios::CopiarDirectorio(Cadena rutaOrigen, Cadena rutaDestino)
{
	TipoError retorno = this->ValidacionesPorOperacion(COPYDIR, rutaOrigen, rutaDestino, "");
	if (retorno == NO_HAY_ERROR) {
		NodoLista<Cadena>* listaRutaOrigen = rutaALista(&rutaOrigen);
		NodoAG<Directorio>* nodoDirectorioOrigen = buscarRuta(this->arbolDirectorios, listaRutaOrigen);
		if (nodoDirectorioOrigen == NULL) {
			retorno = ERROR_NO_SE_ENCUENTRA_RUTA_ORIGEN;
		}
		else {
			NodoLista<Cadena>* listaRutaDestino = rutaALista(&rutaDestino);
			NodoAG<Directorio>* nodoDirectorioDestino = buscarRuta(this->arbolDirectorios, listaRutaDestino);
			if (nodoDirectorioDestino != NULL) {
				retorno = ERROR_YA_EXISTE_RUTA_DESTINO;
			}
			else {
				//if (this->DestinoEsSubdirectorioOrigen(listaRutaOrigen, listaRutaDestino)) {
				if(*listaRutaOrigen <= *listaRutaDestino){
					retorno = ERROR_RUTA_DESTINO_ES_SUBDIR_DE_ORIGEN;
				}
				else {
					Cadena nombreDirectorioACrear = obtenerYBorrarUltimaCadena(listaRutaDestino);
					NodoAG<Directorio>* nodoPadreDestino = buscarRuta(this->arbolDirectorios, listaRutaDestino);
					if (nodoPadreDestino == NULL) {
						retorno = ERROR_NO_SE_ENCUENTRA_PADRE_RUTA_DESTINO;
					}
					else {
						//Se puede hacer la copia
						Directorio* nuevoDir = new Directorio();
						*nuevoDir = nodoDirectorioOrigen->dato;
						nuevoDir->SetNombre(nombreDirectorioACrear);
						NodoAG<Directorio>* nodosDescendientes = this->ClonarNodoDirectorio(nodoDirectorioOrigen->ph);
						NodoAG<Directorio>* nuevoNodo = new NodoAG<Directorio>(*nuevoDir, NULL, NULL);
						nuevoNodo->ph = nodosDescendientes;
						nuevoNodo->sh = nodoPadreDestino->ph;
						nodoPadreDestino->ph = nuevoNodo;
					}
				}
			}
		}

	}
	return retorno;
}

TipoError Directorios::Delete(Cadena rutaArchivo) {
	TipoError retorno = this->ValidacionesPorOperacion(DELETE, rutaArchivo, "", "");
	if (!ExisteDirectorio(rutaArchivo,true)) {
		retorno = ERROR_NO_SE_ENCUENTRA_RUTA;
	}
	else {
		Cadena nombreArchivo = "";
		NodoAG<Directorio> *nodoDirectorio = BuscarNodoDirectorio(rutaArchivo, true, nombreArchivo);
		if (!nodoDirectorio->dato.ExisteArchivo(nombreArchivo)) {
			retorno = ERROR_NO_EXISTE_ARCHIVO_NOMBRE_EN_RUTA;
		}
		else {
			Archivo archivo = nodoDirectorio->dato.BuscarArchivo(nombreArchivo);
			Asociacion<Cadena, Archivo>* asociacionRutaArchivo = new Asociacion<Cadena, Archivo>(rutaArchivo, archivo);
			this->listaUndeleteArchivos->Push(*asociacionRutaArchivo);
			nodoDirectorio->dato.EliminarArchivo(nombreArchivo);
		}
	}
	return retorno;
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

TipoError Directorios::ValidacionesPorOperacion(TipoOperacion nombreOperacion, Cadena rutaOrigen, Cadena rutaDestino="", Cadena parametro= "")
{
	TipoError retorno = NO_HAY_ERROR;
	if (nombreOperacion == MKDIR) {
		if (this->rutaComienzaMal(rutaOrigen)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
		}
		else if (this->directorioRaizDuplicado(rutaOrigen)) {
			retorno = ERROR_NO_SE_PUEDE_CREAR_DIR_RAIZ;
		}
		else if (this->directorioNombreIncorrecto(rutaOrigen)) {
			retorno = ERROR_DIRECTORIO_NOMBRE_INCORRECTO;
		}
	}
	if (nombreOperacion == DIR) {
		if (this->rutaComienzaMal(rutaOrigen)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
		}
		if (parametro != "" && parametro != "-H") {
			retorno = ERROR_PARAMETRO_DESCONOCIDO;
		}
	}
	if (nombreOperacion == RMDIR) {
		if (this->rutaComienzaMal(rutaOrigen)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
		}
	}
	if (nombreOperacion == COPYDIR) {
		if (this->rutaComienzaMal(rutaOrigen) || this->rutaComienzaMal(rutaDestino)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
		}
	}
	if (nombreOperacion == DELETE) {
		if (this->rutaComienzaMal(rutaOrigen)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
		}
	}
	if (nombreOperacion == CREATEFILE) {
		if (this->rutaComienzaMal(rutaOrigen)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
		}
	}
	if (nombreOperacion == INSERTTEXT) {
		if (this->rutaComienzaMal(rutaOrigen)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
		}
	}
	if (nombreOperacion == TYPE) {
		if (this->rutaComienzaMal(rutaOrigen)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
		}
	}
	if (nombreOperacion == DELETETEXT) {
		if (this->rutaComienzaMal(rutaOrigen)) {
			retorno = ERROR_RUTA_COMIENZA_MAL;
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
	delete cadDobleBarra;
	delete cadPunto;
	return retorno;
}

void Directorios::ListarDirectorios(NodoAG<Directorio>* nodoDirectorio, Cadena ruta, Cadena parametro) {
	//cout << "DIR " << ruta << parametro << endl;
	cout << ruta << endl;
	if (!nodoDirectorio->dato.ContieneArchivos() && nodoDirectorio->ph == NULL) {
		cout << "No contiene archivos ni directorios." << endl;
	}
	else {
		nodoDirectorio->dato.ListarArchivos(ruta, parametro);
		nodoDirectorio = nodoDirectorio->ph;//Lo avanzo uno para que busque solo directorios descendientes, no hermanos
		ListaOrd<Asociacion<Cadena, Directorio>>* listaRutasDirectorios = new ListaOrdImp<Asociacion<Cadena, Directorio>>();
		this->obtenerListaOrdenadaTodoslLosDirectorios(nodoDirectorio, ruta, listaRutasDirectorios);
		Iterador<Asociacion<Cadena, Directorio>> itListaDirectorios = listaRutasDirectorios->GetIterador();
		while (!itListaDirectorios.EsFin()) {
			Cadena ruta = itListaDirectorios.Elemento().GetDominio();
			ruta.QuitarUltimoCaracter();
			cout << ruta << endl;
			itListaDirectorios.Elemento().GetRango().ListarArchivos(ruta, parametro);
			itListaDirectorios++;
		}
		delete listaRutasDirectorios;
	}
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

void Directorios::EliminarDirectorioPrimerHijo(NodoAG<Directorio>*& nodoPadre) {
	NodoAG<Directorio>* aux = nodoPadre->ph;
	nodoPadre->ph = aux->sh;
	aux->sh = NULL;
	this->EliminarTodo(aux->ph);
	delete aux;
	aux = NULL;
}

void Directorios::EliminarDirectorioSiguienteHermano(NodoAG<Directorio>*& nodoPadre, Cadena nombreNodoEliminar) {
	NodoAG<Directorio>* auxHermanoAnterior = nodoPadre->ph;
	while (auxHermanoAnterior->sh->dato.GetNombre() != nombreNodoEliminar) {
		auxHermanoAnterior = auxHermanoAnterior->sh;
	}
	NodoAG<Directorio>* auxEliminar = auxHermanoAnterior->sh;
	auxHermanoAnterior->sh = auxEliminar->sh;
	auxEliminar->sh = NULL;
	this->EliminarTodo(auxEliminar->ph);
	delete auxEliminar;
	auxEliminar = NULL;
}


void Directorios::EliminarTodo(NodoAG<Directorio>*& raiz) {
	if (raiz != NULL) {
		this->EliminarTodo(raiz->sh);
		this->EliminarTodo(raiz->ph);
		delete raiz;
		raiz = NULL;
	}
}


NodoAG<Directorio> *Directorios::ClonarNodoDirectorio(NodoAG<Directorio>* nodo) {
	if (nodo == NULL) {
		return NULL;
	}
	else {
		return new NodoAG<Directorio>(nodo->dato, ClonarNodoDirectorio(nodo->ph), ClonarNodoDirectorio(nodo->sh));
	}
}

#endif
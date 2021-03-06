#ifndef DIRECTORIOS_H
#define DIRECTORIOS_H

using namespace std;
#include "Constantes.h"
#include "Directorio.h"
#include "NodoAG.h"
#include "ListaOrdImp.h"
#include "TipoOperacion.h"
#include "TipoError.h"
#include "PilaAcotadaEspecial.h"


class Directorios {

public:

	//Constructor por defecto
	Directorios();

	//Constructor con m�ximo n�mero de archivos a recuperar
	Directorios(unsigned int MAX_RECUPERAR);

	//Destructor
	virtual ~Directorios();

	//Constructor copia
	Directorios(const Directorios &d);

	//Operador de asignaci�n
	Directorios &operator=(const Directorios &d);

	//PRE: 
	//POS: Agregar el Archivo
	TipoError AgregarArchivo(Cadena ruta);

	//PRE: 
	//POS: Agregar el directorio
	TipoError AgregarDirectorio(Cadena ruta);

	//PRE: 
	//POS: Elimina el directorio.
	TipoError EliminarDirectorio(Cadena ruta);

	//PRE: 
	//POS: Retorna true si existe directorio correspondiente a ruta.
	//Si el parametro descartarUltimaParte se setea en true, se busca el directorio hasta la �ltima / de la ruta
	bool ExisteDirectorio(Cadena ruta, bool descartarUltimaParte);

	//PRE: Existe ruta
	//POS: Retorna Directorio correspondiente a la ruta.
	//Si el parametro descartarUltimaParte se setea en true, se busca el directorio hasta la �ltima / de la
	//ruta y se carga el par�metro ultimParte con el texto que procede la �ltima / de la ruta
	NodoAG<Directorio> *BuscarNodoDirectorio(Cadena ruta, bool descartarUltimaParte, Cadena& ultimParte);

	//PRE: Existe ruta
	//POS: Imprime la jerarquia de directorios a partir de ruta teniendo en cuenta el parametro que indica la visibilidad.
	TipoError Dir(Cadena ruta, Cadena parametro);

	//PRE: 
	//POS: Elimina todos los directorios (y sus archivos) excepto el raiz "/".
	void Vaciar();

	//PRE: 
	//POS: Modifica la visibilidad de un archivo, +H lo oculta y -H lo hace visible
	TipoError Attrib(Cadena ruta, Cadena parametro);

	//PRE: 
	//POS: Copia el directorio de origen a destino
	TipoError CopiarDirectorio(Cadena rutaOrigen, Cadena rutaDestino);

	//PRE: 
	//POS: Se muestra el contenido en unarchivo
	TipoError Type(Cadena ruta);

	//PRE: 
	//POS: Borra el texto desde determinada linea y posicion
	TipoError DeleteText(Cadena rutaArchivo, unsigned int linea, unsigned int posicion, unsigned int k);

	//PRE: 
	//POS: Inserta el texto en determinada linea y posicion
	TipoError InsertText(Cadena rutaArchivo,unsigned int linea, unsigned int posicion, Cadena texto);

	//PRE: 
	//POS: Elimina un archivo de la ruta especificada sin importar si est� oculto o no.
	TipoError Delete(Cadena rutaArchivo);

	//PRE: 
	//POS: Recupera el �ltimo archivo eliminado con la operaci�n delete.
	//El archivo lo recupera en la misma ruta que se encontraba, 
	//a menos que en dicha ruta ya exista otro archivo con el mismo nombre o la ruta ya no exista m�s.
	//Solo en caso que no hayan archivos para recuperar se devuelve un mensaje de error indicandolo.
	TipoError Undelete();


private:
	const char* barra = "/";
	NodoAG<Directorio>* arbolDirectorios;
	Pila<Asociacion<Cadena, Archivo>> *listaUndeleteArchivos;

	//PRE:
	//POS: Copia un arbol general de directorios pasado por par�metros
	NodoAG<Directorio>* CopiarArbolDirectorios(NodoAG<Directorio>* d);

	//PRE:
	//POS: Convierte una ruta en una lista de nombres de directorios.
	//La ruta la separa por / y cada nombre es un nodo de la lista.
	NodoLista<Cadena>* rutaALista(Cadena* ruta);

	//PRE:
	//POS: Agrega un nodo con el nombre de un directorio al final de la lista 
	void AgregarNombreDirectorioAlFinal(NodoLista<Cadena>*& lista, const char* nombreDirectorio);

	//PRE:
	//POS:Busca en el NodoAG<Directorio> propio si tiene la ruta pasada por par�metro
	//como una lista y la devuelve
	NodoAG<Directorio>* buscarRuta(NodoAG<Directorio>*& r, NodoLista<Cadena>* listaRuta);

	//PRE: La lista tiene por lo menos 2 nodos
	//POS: Borra el �ltimo nodo y devuelve la cadena de ese �ltimo nodo
	Cadena obtenerYBorrarUltimaCadena(NodoLista<Cadena>* listaRuta);
	
	//PRE:
	//POS: Valida que no exista un nodo hijo de nodoDirectorio con nombre: nombreDirectorio
	bool ExisteHijoEnRuta(NodoAG<Directorio>* nodoDirectorio, Cadena nombreDirectorio);

	//PRE:
	//POS: Devuelve true si la ruta no comienza con /
	bool rutaComienzaMal(Cadena ruta);

	//PRE:
	//POS: Devuelve true la ruta tiene un solo caracter que es /
	bool directorioRaizDuplicado(Cadena ruta);

	//PRE:
	//POS: Devuelve true si la ruta contiene // o un .
	bool directorioNombreIncorrecto(Cadena ruta);

	//PRE:
	//POS: Realiza las validaciones de la Operaci�n pasada por par�metro y devuelve 
	// si encuentra error o no. Si encuentra error imprime el texto correspondiente
	TipoError ValidacionesPorOperacion(TipoOperacion nombreOperacion, Cadena rutaOrigen, Cadena rutaDestino, Cadena parametro);

	//PRE: Ruta y par�metro v�lidos
	//POS: Imprime la jerarquia de directorios a partir de nodoDirectorio teniendo en cuenta el parametro que indica la visibilidad.
	void ListarDirectorios(NodoAG<Directorio>* nodoDirectorio, Cadena ruta, Cadena parametro);

	//PRE: listaDirectorios es vac�a
	//POS: Obtiene una lista ordenada alfabeticamente de todos los directorios que posee el arbol general.
	void obtenerListaOrdenadaTodoslLosDirectorios(NodoAG<Directorio>* nodoDirectorio, Cadena ruta, ListaOrd<Asociacion<Cadena, Directorio>>*& listaRutasDirectorios);

	//PRE: 
	//POS:Elimina todos los archivos y descendientes del primer hijo de nodoPadre
	void EliminarDirectorioPrimerHijo(NodoAG<Directorio>*& nodoPadre);

	//PRE: nodoEliminar es un Hijo de nodoPadre. No es el primer hijo
	//POS: Elimina todos los archivos y descendientes del hijo de nodoPadre que se llama igual a nombreNodoEliminar
	void EliminarDirectorioSiguienteHermano(NodoAG<Directorio>*& nodoPadre, Cadena nombreNodoEliminar);

	//PRE: 
	//POS: Elimina todo el contenido del nodo ra�z, de sus descendientes, sus hermanos y de los descendientes de sus hermanos
	void EliminarTodo(NodoAG<Directorio>*& raiz);

	//PRE: 
	//POS: Clona completamente el Arbol General pasado por par�metro y devuleve uno identico que no comparte memoria
	NodoAG<Directorio> *ClonarNodoDirectorio(NodoAG<Directorio>* n);

};
#endif 
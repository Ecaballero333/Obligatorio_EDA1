#ifndef DIRECTORIOS_H
#define DIRECTORIOS_H

using namespace std;
#include "Constantes.h"
#include "Directorio.h"
#include "NodoAG.h"
#include "ListaOrdImp.h"
#include "TipoOperacion.h"
#include "TipoError.h"


class Directorios {
	
	public:

		//Constructor por defecto
		Directorios();
		
		//Destructor
		virtual ~Directorios();

		//Constructor copia
		Directorios(const Directorios &d);

		//Operador de asignación
		Directorios &operator=(const Directorios &d);

		//PRE: 
		//POS: Agregar el directorio
		TipoError AgregarDirectorio(Cadena ruta);
		
		//PRE: 
		//POS: Elimina el directorio.
		void EliminarDirectorio(Cadena ruta);

		//PRE: 
		//POS: Retorna true si existe directorio correspondiente a ruta.
		bool ExisteDirectorio(Cadena ruta) const;

		//PRE: Existe ruta
		//POS: Retorna Directorio correspondiente a la ruta.
		//Directorio &BuscarDirectorio(Cadena ruta) const;

		//PRE: Existe ruta
		//POS: Imprime la jerarquia de directorios a partir de ruta teniendo en cuenta el parametro que indica la visibilidad.
		TipoError Dir(Cadena ruta, Cadena parametro);

		//PRE: 
		//POS: Elimina todos los directorios (y sus archivos) excepto el raiz "/".
		void Vaciar();

		//PRE: 
		//POS: Copia el directorio de origen a destino
		void CopiarDirectorio(Cadena rutaOrigen, Cadena rutaDestino);
				

    private:
		const char* barra = "/";
		NodoAG<Directorio>* arbolDirectorios;

		//PRE:
		//POS: Copia un arbol general de directorios pasado por parámetros
		NodoAG<Directorio>* CopiarArbolDirectorios(NodoAG<Directorio>* d);

		//PRE:
		//POS: Convierte una ruta en una lista de nombres de directorios.
		//La ruta la separa por / y cada nombrees un nodo de la lista.
		NodoLista<Cadena>* rutaALista(Cadena* ruta);

		//PRE:
		//POS: Agrega un nodo con el nombre de un directorio al final de la lista 
		void AgregarNombreDirectorioAlFinal(NodoLista<Cadena>*& lista, const char* nombreDirectorio);

		//PRE:
		//POS:Busca en el NodoAG<Directorio> propio si tiene la ruta pasada por parámetro
		//como una lista y la devuelve
		NodoAG<Directorio>* buscarRuta(NodoAG<Directorio>*& r, NodoLista<Cadena>* listaRuta);

		//PRE: La lista tiene por lo menos 2 nodos
		//POS: Borra el último nodo y devuelve la cadena de ese último nodo
		Cadena obtenerYBorrarUltimaCadena(NodoLista<Cadena>* listaRuta);

		//PRE:
		//POS: Valida que no exista un nodo hijo de nodoDirectorio con nombre: nombreDirectorio
		bool ExisteHijoEnRuta(NodoAG<Directorio>* nodoDirectorio, Cadena nombreDirectorio);

		//PRE:
		//POS: Devuelve true si la ruta no comienza con /
		bool rutaComienzaMal(Cadena ruta);

		//PRE:
		//POS: Devuelve true si la ruta no comienza con /
		bool directorioRaizDuplicado(Cadena ruta);

		//PRE:
		//POS: Devuelve true si la ruta no comienza con /
		bool directorioNombreIncorrecto(Cadena ruta);
		
		//PRE:
		//POS: Realiza las validaciones de la Operación pasada por parámetro y devuelve 
		// si encuentra error o no. Si encuentra error imprime el texto correspondiente
		TipoError ValidacionesPorOperacion(TipoOperacion nombreOperacion, Cadena ruta, Cadena parametro);

		//PRE: Ruta y parámetro válidos
		//POS: Imprime la jerarquia de directorios a partir de nodoDirectorio teniendo en cuenta el parametro que indica la visibilidad.
		void ListarDirectorios(NodoAG<Directorio>* nodoDirectorio, Cadena ruta, Cadena parametro);
		
		//PRE: listaDirectorios es vacía
		//POS: Obtiene una lista ordenada de todos los directorios que posee el arbol general.
		//El orden está definido en el operador < de Directorio. Cuanto menor sea el nivel, antes aparece en la lista.
		//Los directorios que esten en el mismo nivel se ordenan por nombre
		void obtenerListaOrdenadaTodoslLosDirectorios(NodoAG<Directorio>* nodoDirectorio, Cadena ruta, ListaOrd<Asociacion<Cadena, Directorio>>*& listaRutasDirectorios);

};

#endif 
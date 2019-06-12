#ifndef DIRECTORIOS_H
#define DIRECTORIOS_H

using namespace std;
#include "Constantes.h"
#include "Directorio.h"
#include "NodoAG.h"
#include "ListaOrdImp.h"
#include "TipoError.h"


class Directorios {
	
	public:

		//Constructor por defecto
		Directorios();
		
		//Destructor
		virtual ~Directorios();

		//Constructor copia
		Directorios(const Directorios &d);

		//Operador de asignaci�n
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
		void Dir(Cadena ruta, Cadena parametro) const;

		//PRE: 
		//POS: Elimina todos los directorios (y sus archivos) excepto el raiz "/".
		void Vaciar();

		//PRE: 
		//POS: Copia el directorio de origen a destino
		void CopiarDirectorio(Cadena rutaOrigen, Cadena rutaDestino);
				

    private:
		NodoAG<Directorio>* arbolDirectorios;

		//PRE:
		//POS: Copia un arbol general de directorios pasado por par�metros
		NodoAG<Directorio>* CopiarArbolDirectorios(NodoAG<Directorio>* d);

		//PRE:
		//POS: Convierte una ruta en una lista de nombres de directorios.
		//La ruta la separa por / y cada nombrees un nodo de la lista.
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

		bool ExisteHijoEnRuta(NodoAG<Directorio>* nodoDirectorio, Cadena nombreDirectorio);
};

#endif 
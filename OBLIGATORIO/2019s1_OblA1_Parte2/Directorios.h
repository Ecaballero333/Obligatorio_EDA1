#ifndef DIRECTORIOS_H
#define DIRECTORIOS_H

#include "Constantes.h"
#include "Directorio.h"
#include "NodoAG.h"
#include "ListaOrdImp.h"


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
		void AgregarDirectorio(Cadena ruta);
		
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

		//PRE:
		//POS: Copia un arbol general de directorios pasado por parámetro
		NodoAG<Directorio>* CopiarArbolDirectorios(NodoAG<Directorio>* d);

		//PRE:
		//POS: Convierte una ruta en una lista de nombres de directorios.
		//La ruta la separa por / y cada nombrees un nodo de la lista.
		NodoLista<char*>* rutaALista(Cadena* ruta);

		//PRE:
		//POS: Agrega un nodo con el nombre de un directorio al final de la lista 
		void AgregarNombreDirectorioAlFinal(NodoLista<char*>*& lista, char* nombreDirectorio);

		//PRE:
		//POS:Busca en el NodoAG<Directorio> propio si tiene la ruta pasada por parámetro
		//como una lista y la devuelve
		NodoAG<Directorio>* buscarRuta(NodoAG<Directorio>*& r, NodoLista<char*>* listaRuta);

    private:
		NodoAG<Directorio>* arbolDirectorios;

};

#endif 
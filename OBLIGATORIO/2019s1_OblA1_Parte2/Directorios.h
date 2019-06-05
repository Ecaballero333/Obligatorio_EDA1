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

    private:
		NodoAG<Directorio>* arbolDirectorios;

};

#endif 
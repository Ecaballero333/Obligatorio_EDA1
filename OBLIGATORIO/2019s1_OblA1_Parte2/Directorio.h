#ifndef DIRECTORIO_H
#define DIRECTORIO_H

#include "Cadena.h"
#include "ListaOrdImp.h"
#include "Asociacion.h"
#include "Referencia.h"
#include "Archivo.h"

class Directorio;

inline ostream &operator<<(ostream& out, const Directorio &d) {
	assert(false); // No implementada
	return out;
}

class Directorio{
	
	public:

		//Constructor por defecto
		Directorio();

		//Constructor
		Directorio(Cadena nombreDirectorio, int nivel);
		
		//Destructor
		virtual ~Directorio();

		//Constructor copia
		Directorio(const Directorio &d);

		//Operador de asignación
		Directorio &operator=(const Directorio &d);

		//Operadores de menor, menor igual y mayor igual
		//Revisa primero el nivel en el que se encuentra el directorio en el arbol de directorios.
		//Cuanto menor sea el numero de nivel, menor será el directorio.
		//Si los niveles son iguales, revisa por nombre de directorio
		bool operator<(const Directorio &d) const;
		bool operator<=(const Directorio &d) const;
		bool operator>=(const Directorio &d) const;

		//Operador de igualdad. 
		bool operator==(const Directorio &d) const;

		//PRE: El archivo no existe
		//POS: Agrega el archivo
	    void AgregarArchivo(Cadena nombreArchivo);

		//PRE: El archivo no existe
		//POS: Agrega el archivo
	    void AgregarArchivo(const Archivo &archivo);

		//PRE: El archivo existe
		//POS: Elimina el archivo
		void EliminarArchivo(Cadena nombreArchivo);

		//PRE:
		//POS: Elimina todos los archivos
		void EliminarArchivos();

		//PRE:
		//POS: Retorna true si existe archivo con ese nombre
		bool ExisteArchivo(Cadena nombreArchivo) const;

		//PRE:
		//POS: True si existe al menos un archivo.
		bool ContieneArchivos() const;

		//PRE: Existe archivo
		//POS: Retorna Archivo
		Archivo &BuscarArchivo(Cadena nombreArchivo) const;
 
		//PRE:
		//POS: Retorna el nombre del directorio
		Cadena GetNombre() const;

		//PRE:
		//POS: Cambia el nombre del directorio
		void SetNombre(Cadena nombre);

		//PRE:
		//POS: Lista todos los archivos en orden alfabetico con prefijo ruta teniendo en cuenta el parametro que indica la visibilidad.
		void ListarArchivos(Cadena ruta, Cadena parametro) const; 

		//PRE:
		//POS: Establece el nivel en el que se encuentra el directorio en el arbol de directorios.
		//El directorio raíz está en el nivel 0.
		//El resto de directorios estan a partir del nivel 1
		void setNivel(int nivel);

		//PRE:
		//POS: Devuelve el nivel en el que se encuentra el directorio en el arbol de directorios.
		int getNivel();



private:
	Cadena nombre;
	int nivel;
	ListaOrd<Archivo>* archivos;

};

#endif 
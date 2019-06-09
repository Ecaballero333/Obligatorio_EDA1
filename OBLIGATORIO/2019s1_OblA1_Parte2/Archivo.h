#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "Cadena.h"
#include "ListaPosImp.h"
#include "Referencia.h"

class Archivo;

inline ostream &operator<<(ostream& out, const Archivo &a) {
	assert(false); // No implementada
	return out;
}

class Archivo{
	
	public:

		//Constructor por defecto
		Archivo();

		//Constructor
		Archivo(Cadena nombre);
		
		//Destructor
		virtual ~Archivo();

		//Constructor copia
		Archivo(const Archivo &a);

		//Operador de asignación
		Archivo &operator=(const Archivo &a);

		//Operador que evalúa que sea menor por nombre 
		bool operator<(const Archivo &a);

		//Operador que evalúa que sea menor o igual por nombre 
		bool operator<=(const Archivo &a);

		//Operador que evalúa que sea mayor o igual por nombre 
		bool operator>=(const Archivo &a);

		//Operador igualdad
		bool operator==(const Archivo &a) const;
		
		//PRE:
		//POS: Si los parametros son validos se agrega texto al archivo 
		void InsertarTexto(unsigned int nroLinea, unsigned int posLinea, Cadena texto);

		//PRE:
		//POS: Si los parametros son validos se elimina texto del archivo
		void EliminarTexto(unsigned int nroLinea, unsigned int posLinea, unsigned int k);

		//PRE:
		//POS: Se lista su contenido 
		void MostrarContenido() const;

		//PRE:
		//POS: Retorna true si esta oculto
		bool EstaOculto() const;

		//PRE:
		//POS: Retorna nombre
		Cadena GetNombre() const;

		//PRE: Recibe nombre de archivo existente y nueva visibilidad
		//POS: Modifica visibilidad del archivo correspondiente al recibido
		void ModificarVisibilidad(Cadena nuevaVisibilidad);

		//PRE:
		//POS: Retorna si el archivo tiene lineas
		bool TieneLineas() const;

    private:
		Cadena nombre;
		bool oculto;
		ListaPos<Cadena>* lineas;
	
};

#endif 
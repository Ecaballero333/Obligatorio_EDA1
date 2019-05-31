#ifndef INTERFAZ_DEL_SISTEMA_H
#define INTERFAZ_DEL_SISTEMA_H

#include "Constantes.h"

/*	
	Todos los métodos retornan un enumerado correspondiente a si la operación 
	se pudo realizar correctamente, hubo un error o no fue implementada.
   

	NOTA:
			Ver la especificación completa de los diferentes comandos en 
			la letra del obligatorio.

*/

class Expresion;

class InterfazDelSistema abstract
{
	
	public:

		/*
		Libera la memoria utilizada por el FileSystem
		*/
		virtual ~InterfazDelSistema() {};

		/*
		Este comando crea un nuevo subdirectorio vacío en la ruta especificada. El nuevo directorio creado no deberá estar oculto.
		*/
		virtual TipoRetorno Mkdir (const char *rutaDirectorio) abstract;

		/*
		Este comando elimina un subdirectorio en la ruta especificada sin importar si está oculto o no
		*/
		virtual TipoRetorno Rmdir (const char *rutaDirectorio) abstract;

		/*
		Este comando copia un directorio de una ubicación a otra. 
		*/
		virtual TipoRetorno CopyDir(const char *rutaOrigen, const char *rutaDestino) abstract;

		/*
		Este comando muestra el contenido del directorio especificado, ya sean subdirectorios o archivos.
		*/
		virtual TipoRetorno Dir (const char *rutaDirectorio, const char *parametro) const abstract;

		/*
		Este comando crea un nuevo archivo en la ruta especificada.
		*/
		virtual TipoRetorno CreateFile (const char *rutaArchivo) abstract;

		/*
		Este comando elimina un archivo en la ruta especificada.
		*/
		virtual TipoRetorno Delete (const char *rutaArchivo) abstract;

		/*
		Este comando cambia los atributos de un archivo perteneciente al directorio especificado.
		*/
		virtual TipoRetorno Attrib (const char *rutaArchivo, const char *parametro) abstract;

		/*
		Agrega un texto en la línea y posición del archivo RutaArchivo.
		*/
		virtual TipoRetorno InsertText (const char *rutaArchivo, unsigned int nroLinea, unsigned int posLinea, const char *texto) abstract;

		/*
		Elimina los a lo sumo K caracteres, comenzando en la línea y posición especificada.
		*/
		virtual TipoRetorno DeleteText (const char *rutaArchivo, unsigned int nroLinea, unsigned int posLinea, unsigned int k) abstract;

		/*
		Este comando imprime el contenido del archivo parámetro.
		*/
		virtual TipoRetorno Type (const char *rutaArchivo) const abstract;

		/*
		Este comando recupera el último archivo eliminado del filesystem. 
		*/
		virtual TipoRetorno Undelete() abstract;


};

#endif 
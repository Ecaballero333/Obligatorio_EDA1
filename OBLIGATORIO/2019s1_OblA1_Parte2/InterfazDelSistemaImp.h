#ifndef INTERFAZ_DEL_SISTEMA_IMP_H
#define INTERFAZ_DEL_SISTEMA_IMP_H

#include "Constantes.h"
#include "InterfazDelSistema.h"

#include "FileSystem.h"

class InterfazDelSistemaImp  : public InterfazDelSistema
{
public:
	
		InterfazDelSistemaImp(unsigned int MAX_RECUPERAR);

		~InterfazDelSistemaImp();

		TipoRetorno Mkdir (const char *rutaDirectorio);

		TipoRetorno Rmdir (const char *rutaDirectorio);

		TipoRetorno CopyDir (const char *rutaOrigen, const char *rutaDestino);

		TipoRetorno Dir (const char *rutaDirectorio, const char *parametro) const;

		TipoRetorno CreateFile (const char *rutaArchivo);

		TipoRetorno Delete (const char *rutaArchivo);

		TipoRetorno Attrib (const char *rutaArchivo, const char *parametro);

		TipoRetorno InsertText (const char *rutaArchivo, unsigned int nroLinea, unsigned int posLinea, const char *texto);

		TipoRetorno DeleteText (const char *rutaArchivo, unsigned int nroLinea, unsigned int posLinea, unsigned int k);

		TipoRetorno Type (const char *rutaArchivo) const;

		TipoRetorno Undelete();
			

private:

	InterfazDelSistemaImp() { assert(false); }

	// Atributos
	FileSystem *fileSystem;
};

#endif

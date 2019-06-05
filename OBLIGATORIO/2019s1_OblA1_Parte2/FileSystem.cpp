#include "FileSystem.h"

#ifndef FILESYSTEM_CPP
#define FILESYTEM_CPP



FileSystem::FileSystem()
{
	this->raiz = new Directorios();
}


FileSystem::FileSystem(unsigned int MAX_RECUPERAR)
{
	// NO IMPLEMENTADA
}


FileSystem::~FileSystem()
{
	// NO IMPLEMENTADA
}

FileSystem::FileSystem(const FileSystem &f)
{
	// NO IMPLEMENTADA
	*this = f;
}

FileSystem &FileSystem::operator=(const FileSystem &f) 
{
	if (this != &f)
	{
		// NO IMPLEMENTADA
		assert(false);
	}
	return *this;
}


TipoRetorno FileSystem::Mkdir(Cadena rutaDirectorio)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno FileSystem::Rmdir(Cadena rutaDirectorio)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}


TipoRetorno FileSystem::CopyDir (Cadena rutaOrigen, Cadena rutaDestino)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}


TipoRetorno FileSystem::Dir(Cadena rutaDirectorio, Cadena parametro) const
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno FileSystem::CreateFile(Cadena rutaArchivo)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}


TipoRetorno FileSystem::Delete (Cadena rutaArchivo)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno FileSystem::Attrib(Cadena rutaArchivo, Cadena parametro)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno FileSystem::InsertText(Cadena rutaArchivo, unsigned int nroLinea, unsigned int posLinea, Cadena texto)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno FileSystem::DeleteText(Cadena rutaArchivo, unsigned int nroLinea, unsigned int posLinea, unsigned int k)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno FileSystem::Type(Cadena rutaArchivo) const
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno FileSystem::Undelete()
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}



#endif
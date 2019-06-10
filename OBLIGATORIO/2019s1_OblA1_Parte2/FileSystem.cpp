#include "FileSystem.h"

#ifndef FILESYSTEM_CPP
#define FILESYTEM_CPP



FileSystem::FileSystem()
{
	this->raiz = new Directorios();
	//this->listaUndeleteArchivos = new PilaImp<rutaArchivo>();
}


FileSystem::FileSystem(unsigned int MAX_RECUPERAR)
{
	this->maximoRecupera = MAX_RECUPERAR;
	this->raiz = new Directorios();
	//this->listaUndeleteArchivos = new PilaImp<Asociacion<ruta, Archivo>>();
}


FileSystem::~FileSystem()
{
	this->maximoRecupera = NULL;
	delete this->raiz;
	//delete this->listaUndeleteArchivos;
}

FileSystem::FileSystem(const FileSystem &f)
{
	this->maximoRecupera = NULL;
	this->raiz = NULL;
	//this->listaUndeleteArchivos = NULL;
	*this = f;
}

FileSystem &FileSystem::operator=(const FileSystem &f) 
{
	if (this != &f)
	{
		this->maximoRecupera = f.maximoRecupera;
		*this->raiz = *f.raiz;
		//*this->listaUndeleteArchivos = *f.listaUndeleteArchivos;
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
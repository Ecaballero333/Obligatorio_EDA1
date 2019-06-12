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
	TipoRetorno retorno = this->ValidacionTextoRuta(MKDIR,rutaDirectorio);
	if (retorno==OK) {
		TipoError resultado = this->raiz->AgregarDirectorio(rutaDirectorio);
		if (resultado != NO_HAY_ERROR) {
			retorno = ERROR;
			this->ImprimirError(resultado);
		}
	}
	else {
		retorno = ERROR;		
	}
	return retorno;
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



TipoRetorno FileSystem::ValidacionTextoRuta(TipoOperacion nombreOperacion, Cadena ruta)
{
	TipoRetorno retorno = OK;
	if (nombreOperacion == MKDIR) {
		if (this->rutaComienzaMal(ruta)) {
			retorno = ERROR;
			ImprimirError(ERROR_RUTA_COMIENZA_MAL);
		}
		else if (this->directorioRaizDuplicado(ruta)) {
			retorno = ERROR;
			ImprimirError(ERROR_NO_SE_PUEDE_CREAR_DIR_RAIZ);
		}
		else if (this->directorioNombreIncorrecto(ruta)) {
			retorno = ERROR;
			ImprimirError(ERROR_DIRECTORIO_NOMBRE_INCORRECTO);
		}
	}
	return retorno;
}

bool FileSystem::rutaComienzaMal(Cadena ruta) {
	return ruta[0] != *barra;
}

bool FileSystem::directorioRaizDuplicado(Cadena ruta) {
	return ruta[0] == *barra && ruta.Length() == 1;
}

bool FileSystem::directorioNombreIncorrecto(Cadena ruta) {
	const char* dobleBarra = "//";
	Cadena* cadDobleBarra = new Cadena(dobleBarra, true);
	const char* punto = ".";
	Cadena* cadPunto = new Cadena(punto, true);
	bool retorno = ruta.Contains(*cadDobleBarra) || ruta.Contains(*cadPunto);
	delete[] cadDobleBarra;
	delete[] cadPunto;
	return retorno;
}


void FileSystem::ImprimirError(TipoError tipoError) {
	switch (tipoError)
	{
		case ERROR_RUTA_COMIENZA_MAL:
			cout << "ERROR: La ruta no comienza con /.";
			break;
		case ERROR_NO_SE_ENCUENTRA_RUTA:
			cout << "ERROR: No se encuentra la ruta.";
				break;
		case ERROR_YA_EXISTE_SUBDIRECTORIO:
			cout << "ERROR: Ya existe un subdirectorio con el mismo nombre en esa ruta.";
			break;
		case ERROR_NO_SE_PUEDE_CREAR_DIR_RAIZ:
			cout << "ERROR: No se puede volver a crear el directorio raiz.";
			break;
		case ERROR_DIRECTORIO_NOMBRE_INCORRECTO:
			cout << "ERROR: Directorio con nombre incorrecto";
			break;
		default:
			break;
	}
}


#endif
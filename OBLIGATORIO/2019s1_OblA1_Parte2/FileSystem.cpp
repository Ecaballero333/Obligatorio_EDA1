#include "FileSystem.h"

#ifndef FILESYSTEM_CPP
#define FILESYTEM_CPP



FileSystem::FileSystem()
{
	this->raiz = new Directorios();
}


FileSystem::FileSystem(unsigned int MAX_RECUPERAR)
{
	this->raiz = new Directorios(MAX_RECUPERAR);
	//this->listaUndeleteArchivos = new PilaImp<Asociacion<ruta, Archivo>>();
}


FileSystem::~FileSystem()
{
	this->raiz->Vaciar();
	delete this->raiz;
	this->raiz = NULL;
}

FileSystem::FileSystem(const FileSystem &f)
{
	this->raiz = NULL;
	*this = f;
}

FileSystem &FileSystem::operator=(const FileSystem &f) 
{
	if (this != &f)
	{
		//this->maximoRecupera = f.maximoRecupera;
		*this->raiz = *f.raiz;
	}
	return *this;
}


TipoRetorno FileSystem::Mkdir(Cadena rutaDirectorio)
{
	TipoRetorno retorno = OK;
	TipoError resultado = this->raiz->AgregarDirectorio(rutaDirectorio);
	if (resultado != NO_HAY_ERROR) {
		retorno = ERROR;
		this->ImprimirError(resultado);
	}
	return retorno;
}

TipoRetorno FileSystem::Rmdir(Cadena rutaDirectorio)
{
	TipoRetorno retorno = OK;
	TipoError resultado = this->raiz->EliminarDirectorio(rutaDirectorio);
	if (resultado != NO_HAY_ERROR) {
		retorno = ERROR;
		this->ImprimirError(resultado);
	}
	return retorno;
}


TipoRetorno FileSystem::CopyDir (Cadena rutaOrigen, Cadena rutaDestino)
{
	TipoRetorno retorno = OK;
	TipoError resultado = this->raiz->CopiarDirectorio(rutaOrigen, rutaDestino);
	if (resultado != NO_HAY_ERROR) {
		retorno = ERROR;
		this->ImprimirError(resultado);
	}
	return retorno;
}


TipoRetorno FileSystem::Dir(Cadena rutaDirectorio, Cadena parametro) const
{
	TipoRetorno retorno = OK;
	TipoError resultado = this->raiz->Dir(rutaDirectorio, parametro);
	if (resultado != NO_HAY_ERROR) {
		retorno = ERROR;
		this->ImprimirError(resultado);
	}
	return retorno;
}

TipoRetorno FileSystem::CreateFile(Cadena rutaArchivo)
{
	TipoRetorno retorno = OK;
	TipoError resultado = this->raiz->AgregarArchivo(rutaArchivo);
	if (resultado != NO_HAY_ERROR) {
		retorno = ERROR;
		this->ImprimirError(resultado);
	}
	return retorno;
}


TipoRetorno FileSystem::Delete (Cadena rutaArchivo)
{
	TipoRetorno retorno = OK;
	TipoError resultado = this->raiz->Delete(rutaArchivo);
	if (resultado != NO_HAY_ERROR) {
		retorno = ERROR;
		this->ImprimirError(resultado);
	}
	return retorno;
}

TipoRetorno FileSystem::Attrib(Cadena rutaArchivo, Cadena parametro)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno FileSystem::InsertText(Cadena rutaArchivo, unsigned int nroLinea, unsigned int posLinea, Cadena texto)
{
	TipoRetorno retorno = OK;
	TipoError resultado = this->raiz->InsertText(rutaArchivo, nroLinea, posLinea, texto);
	if (resultado != NO_HAY_ERROR) {
		retorno = ERROR;
		this->ImprimirError(resultado);
	}
	return retorno;

}

TipoRetorno FileSystem::DeleteText(Cadena rutaArchivo, unsigned int nroLinea, unsigned int posLinea, unsigned int k)
{

	return NO_IMPLEMENTADA;

	TipoRetorno retorno = OK;
	TipoError resultado = this->raiz->DeleteText(rutaArchivo, nroLinea, posLinea, k);
	if (resultado != NO_HAY_ERROR) {
		retorno = ERROR;
		this->ImprimirError(resultado);
	}
	return retorno;
}

TipoRetorno FileSystem::Type(Cadena rutaArchivo) const
{
	TipoRetorno retorno = OK;
	TipoError resultado = this->raiz->Type(rutaArchivo);
	if (resultado != NO_HAY_ERROR) {
		retorno = ERROR;
		this->ImprimirError(resultado);
	}
	return retorno;
}

TipoRetorno FileSystem::Undelete()
{
	return NO_IMPLEMENTADA;
	/*TipoRetorno retorno = OK;
	//TipoError resultado = this->raiz->Undelete();
	if (resultado != NO_HAY_ERROR) {
		retorno = ERROR;
		this->ImprimirError(resultado);
	}
	return retorno;*/
}



void FileSystem::ImprimirError(TipoError tipoError) const {
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
		cout << "ERROR: Directorio con nombre incorrecto.";
		break;
	case ERROR_PARAMETRO_DESCONOCIDO:
		cout << "ERROR: Parametro desconocido.";
		break;
	case ERROR_NO_SE_ENCUENTRA_RUTA_ORIGEN:
		cout << "ERROR: No se encuentra la ruta origen.";
		break;
	case ERROR_YA_EXISTE_RUTA_DESTINO:
		cout << "ERROR: Ya existe la ruta destino.";
		break;
	case ERROR_RUTA_DESTINO_ES_SUBDIR_DE_ORIGEN:
		cout << "ERROR: La ruta destino no puede ser un subdirectorio de origen.";
		break;
	case ERROR_NO_SE_ENCUENTRA_PADRE_RUTA_DESTINO:
		cout << "ERROR: No se encuentra el padre de la ruta destino.";
		break;
	case ERROR_NO_EXISTE_ARCHIVO_NOMBRE_EN_RUTA:
		cout << "ERROR: No existe un archivo con ese nombre en esa ruta.";
		break;
	case ERROR_YA_EXISTE_ARCHIVO:
		cout << "ERROR: Ya existe un archivo con el mismo nombre en esa ruta.";
		break;
	default:
		break;
	}
}



#endif
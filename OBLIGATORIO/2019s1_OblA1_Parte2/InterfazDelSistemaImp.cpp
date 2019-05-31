#include "InterfazDelSistemaImp.h"

#ifndef INTERFAZ_DEL_SISTEMA_IMP_CPP
#define INTERFAZ_DEL_SISTEMA_IMP_CPP

// Inicialización de los atributos
InterfazDelSistemaImp::InterfazDelSistemaImp(unsigned int MAX_RECUPERAR)
{
	fileSystem = new FileSystem(MAX_RECUPERAR);
}

// Eliminación de los objetos creados con "new"
InterfazDelSistemaImp::~InterfazDelSistemaImp()
{	
	delete fileSystem;
}

TipoRetorno InterfazDelSistemaImp::Mkdir(const char *rutaDirectorio)
{
	return fileSystem->Mkdir(rutaDirectorio);
}

TipoRetorno InterfazDelSistemaImp::Rmdir(const char *rutaDirectorio)
{
	return fileSystem->Rmdir(rutaDirectorio);
}

TipoRetorno InterfazDelSistemaImp::CopyDir(const char *rutaOrigen, const char *rutaDestino)
{
	return fileSystem->CopyDir(rutaOrigen,rutaDestino);
}

TipoRetorno InterfazDelSistemaImp::Dir(const char *rutaDirectorio, const char *parametro) const
{
	return fileSystem->Dir(rutaDirectorio,parametro);
}

TipoRetorno InterfazDelSistemaImp::CreateFile(const char *rutaArchivo)
{
	return fileSystem->CreateFile(rutaArchivo);
}

TipoRetorno InterfazDelSistemaImp::Delete (const char *rutaArchivo)
{
	return fileSystem->Delete(rutaArchivo);
}

TipoRetorno InterfazDelSistemaImp::Attrib(const char *rutaArchivo, const char *parametro)
{
	return fileSystem->Attrib(rutaArchivo, parametro);
}

TipoRetorno InterfazDelSistemaImp::InsertText(const char *rutaArchivo, unsigned int nroLinea, unsigned int posLinea, const char *texto)
{
	return fileSystem->InsertText(rutaArchivo,nroLinea,posLinea,texto);
}

TipoRetorno InterfazDelSistemaImp::DeleteText(const char *rutaArchivo, unsigned int nroLinea, unsigned int posLinea, unsigned int k)
{
	return fileSystem->DeleteText(rutaArchivo,nroLinea,posLinea,k);
}

TipoRetorno InterfazDelSistemaImp::Type(const char *rutaArchivo) const
{
	return fileSystem->Type(rutaArchivo);
}

TipoRetorno InterfazDelSistemaImp::Undelete()
{
	return fileSystem->Undelete();
}



		
#endif
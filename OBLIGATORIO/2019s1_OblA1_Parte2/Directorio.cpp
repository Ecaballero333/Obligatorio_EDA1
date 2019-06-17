#include "Directorio.h"

#ifndef DIRECTORIO_CPP
#define DIRECTORIO_CPP


Directorio::Directorio()
{
	this->nombre = *new Cadena();
	this->nivel = 0;
	this->archivos = new ListaOrdImp<Archivo>();
}

Directorio::Directorio(Cadena nombreDirectorio, int nivel)
{
	this->nivel = 0;
	this->nombre = nombreDirectorio;
	this->nivel = nivel;
	this->archivos = new ListaOrdImp<Archivo>();
}

Directorio::~Directorio()
{
	this->EliminarArchivos();
}

Directorio::Directorio(const Directorio &d)
{
	*this = d;
}

bool Directorio::operator<(const Directorio &d) const
{
	/*bool retorno = false;
	if (this->nivel != d.nivel) {
		retorno = this->nivel < d.nivel;
	}
	else {
		retorno = this->nombre < d.nombre;
	}
	return retorno;*/
	return this->nombre < d.nombre;
}

bool Directorio::operator<=(const Directorio &d) const
{
	bool retorno = false;
	if (this->nivel != d.nivel) {
		retorno = this->nivel <= d.nivel;
	}
	else {
		retorno = this->nombre <= d.nombre;
	}
	return retorno;
}

bool Directorio::operator>=(const Directorio &d) const
{
	bool retorno = false;
	if (this->nivel != d.nivel) {
		retorno = this->nivel >= d.nivel;
	}
	else {
		retorno = this->nombre >= d.nombre;
	}
	return retorno;
}

bool Directorio::operator==(const Directorio &d) const
{
	bool sonIguales = this->nombre == d.nombre;
	if (sonIguales) {
		bool sonIguales = (this->archivos == NULL && d.archivos == NULL) || (this->archivos != NULL && d.archivos != NULL);
		if (sonIguales && (this->archivos != NULL && d.archivos != NULL)) {
			Iterador<Archivo> itArchivosThis = this->archivos->GetIterador();
			Iterador<Archivo> itArchivosParam = d.archivos->GetIterador();

			while (!itArchivosThis.EsFin() && !itArchivosParam.EsFin() && sonIguales)
			{
				sonIguales = itArchivosThis.Elemento() == itArchivosParam.Elemento();
				itArchivosThis++;
				itArchivosParam++;
			}
			if (sonIguales)
			{
				sonIguales = itArchivosThis.EsFin() && itArchivosParam.EsFin();
			}
		}
	}

	return sonIguales;
}

Directorio &Directorio::operator=(const Directorio&d) 
{
	if (this != &d) 
	{
		this->EliminarArchivos();
		this->nombre = d.nombre;
		this->nivel = d.nivel;
		if (d.archivos != NULL) {
			if (d.archivos->CantidadElementos() > 0) {
				Iterador<Archivo> itArchivosACopiar = d.archivos->GetIterador();
				while (!itArchivosACopiar.EsFin());
				{
					Archivo archivoCopia = itArchivosACopiar.Elemento();
					this->archivos->AgregarOrd(archivoCopia);
					itArchivosACopiar++;
				}
			}
		}
	}
	return *this;
}

void Directorio::AgregarArchivo(Cadena nombreArchivo)
{
	Archivo* archivo = new Archivo(nombreArchivo);
	this->AgregarArchivo(*archivo);
}

void Directorio::AgregarArchivo(const Archivo &archivo)
{
	this->archivos->AgregarOrd(archivo);
}

void Directorio::EliminarArchivo(Cadena nombreArchivo)
{
	Archivo archivo = this->BuscarArchivo(nombreArchivo);
	delete &archivo;
}

void Directorio::EliminarArchivos()
{
	if (this->archivos != NULL) {
		Iterador<Archivo> itArchivosThis = this->archivos->GetIterador();
		while (!itArchivosThis.EsFin())
		{
			Archivo archivoCopia = itArchivosThis.Elemento();
			itArchivosThis++;
			delete &archivoCopia;
		}
	}
}

bool Directorio::ExisteArchivo(Cadena nombreArchivo) const
{
	Iterador<Archivo> itArchivosThis = this->archivos->GetIterador();
	bool existe = false;
	while (!itArchivosThis.EsFin() && !existe)
	{
		if (itArchivosThis.Elemento().GetNombre() == nombreArchivo) {
			existe = true;
		}
		else {
			itArchivosThis++;
		}
	}
	return existe;
}

bool Directorio::ContieneArchivos() const
{
	return this->archivos != NULL && !this->archivos->EsVacia();
}

Archivo &Directorio::BuscarArchivo(Cadena nombreArchivo) const
{
	Iterador<Archivo> itArchivosThis = this->archivos->GetIterador();
	bool encontro = false;
	Archivo retorno;
	while (!itArchivosThis.EsFin() && !encontro)
	{
		if (itArchivosThis.Elemento().GetNombre() == nombreArchivo) {
			encontro = true;
			retorno = itArchivosThis.Elemento();
		}
		else {
			itArchivosThis++;
		}
	}
	return retorno;
}

Cadena Directorio::GetNombre() const
{
	return this->nombre;
}

void Directorio::SetNombre(Cadena nombre)
{
	this->nombre = nombre;
}

void Directorio::ListarArchivos(Cadena ruta, Cadena parametro) const
{
	if (this->archivos != NULL) {
		Iterador<Archivo> itArchivosThis = this->archivos->GetIterador();
		while (!itArchivosThis.EsFin())
		{
			if (parametro == "-H") {
				if (itArchivosThis.Elemento().EstaOculto()) {
					cout << ruta << "/" << itArchivosThis.Elemento().GetNombre() << " (H)" << endl;
				}
			}
			if (!itArchivosThis.Elemento().EstaOculto()) {
				cout << ruta << "/" << itArchivosThis.Elemento().GetNombre() << endl;
			}
			itArchivosThis++;
		}
	}
}

void Directorio::SetNivel(int nivel) {
	this->nivel = nivel;
}

int Directorio::GetNivel() const {
	return this->nivel;
}

#endif
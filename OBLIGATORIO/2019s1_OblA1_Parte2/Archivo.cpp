#include "Archivo.h"


#ifndef ARCHIVO_CPP
#define ARCHIVO_CPP

Archivo::Archivo(Cadena nombre)
{
	this->nombre = nombre;
	this->oculto = false;
	this->lineas = new ListaPosImp<Cadena>();

}

Archivo::Archivo()
{
	this->nombre = *new Cadena();
	this->oculto = false;
	this->lineas = new ListaPosImp<Cadena>();


}

Archivo::~Archivo()
{
	//delete this->lineas;
}

Archivo::Archivo(const Archivo &a)
{
	this->nombre = *new Cadena();
	this->oculto = false;
	this->lineas = new ListaPosImp<Cadena>();
	*this = a;
}

Archivo &Archivo::operator=(const Archivo &a) 
{
	if (this != &a)
	{		
		this->lineas->Vaciar();
		this->nombre = a.nombre;
		this->oculto = a.EstaOculto();
		if(a.lineas!=NULL){
			Iterador<Cadena> itLineasACopiar = a.lineas->GetIterador();
			while (!itLineasACopiar.EsFin()) {

				Cadena cadenaCopia = itLineasACopiar.Elemento();
				this->lineas->AgregarFin(cadenaCopia);
				itLineasACopiar++;
			}
		}
		
	}
	return *this;
}

bool Archivo::operator==(const Archivo &a) const
{
	bool sonIguales = this->nombre == a.nombre;
	if (sonIguales) {
		if (this->lineas != NULL) {
			Iterador<Cadena> itCadenaThis = this->lineas->GetIterador();
			Iterador<Cadena> itCadenaParam = a.lineas->GetIterador();

			while (!itCadenaThis.EsFin() && !itCadenaParam.EsFin() && sonIguales)
			{
				sonIguales = itCadenaThis.Elemento() == itCadenaParam.Elemento();
				itCadenaThis++;
				itCadenaParam++;
			}
			if (sonIguales)
			{
				sonIguales = itCadenaThis.EsFin() && itCadenaParam.EsFin();
			}
		}
	}

	return sonIguales;
}

bool Archivo::operator<(const Archivo &a) {
	return this->GetNombre() < a.GetNombre();
}

bool Archivo::operator<=(const Archivo &a){
	return this->GetNombre() <= a.GetNombre();
}

bool Archivo::operator>=(const Archivo &a) {
	return this->GetNombre() >= a.GetNombre();
}

void Archivo::ModificarVisibilidad(Cadena nuevaVisibilidad)
{

	if (nuevaVisibilidad == "+H") { // en la letra dice que pasan -H o +H
		oculto = true;
	}
	else {
		oculto = false;
	}

}

bool Archivo::CantidadValidaLineas(int nroLinea){

	if(lineas->CantidadElementos() >= nroLinea){
		return true;
	}
	else {
		return false;
	}

}

void Archivo::InsertarTexto(unsigned int nroLinea, unsigned int posLinea, Cadena texto)
{
	while (nroLinea > lineas->CantidadElementos()) {
		lineas->AgregarFin("");
	}
	
	Cadena &aux = lineas->ElementoPos(nroLinea-1);
	(&aux)->InsertarTexto(posLinea, texto);
}


bool Archivo::TieneLineas() const
{
	if (lineas->EsVacia()) {
		return false;
	}
	else {
		return true;
	}
}

void Archivo::EliminarTexto(unsigned int nroLinea, unsigned int posLinea, unsigned int k)
{
	bool llegueAlFinal = false;
	Cadena &aux = lineas->ElementoPos(nroLinea-1);//Las líneas empiezan en 1, por eso resto 1
	//caso 1: Hay que borrar la línea entera porque se borraron todos los caracteres
	if (posLinea == 1 && k >= aux.Length()) {
		lineas->BorrarPos(nroLinea);
	}
	else {
		//Caso 2: No hay que hacer nada porque la posLinea es superior al largo del texto de la línea
		if (posLinea < aux.Length()) {
			//Caso 3: Borro una parte del texto de la línea (no todo completo)		
			aux.EliminarTexto(posLinea,k);
		}
	}

}

void Archivo::borrarPosicion(char str[], int n) {
	size_t slen = std::strlen(str);

	for (n; n <= slen; n++)
		str[n] = str[n + 1];
}

void Archivo::MostrarContenido() const
{
	int n = 1;	
	for (Iterador<Cadena> i = this->lineas->GetIterador(); !i.EsFin();) {
		Cadena c = i.Elemento();		
		cout << n <<": " << c << endl; // empieza en 0 y n en 1
		i++;
		n++;
	}	
}


bool Archivo::EstaOculto() const
{
	return oculto;
}

Cadena Archivo::GetNombre() const
{
	return nombre;
}



#endif
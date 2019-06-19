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
	this->nombre = *new Cadena();
	this->oculto = false;
	this->EliminarLineas();

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
		this->EliminarLineas();
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

bool Archivo::CantidadValidaLineas(int k){

	if(lineas->CantidadElementos() >= k){
		return true;
	}
	else {
		return false;
	}

}

void Archivo::InsertarTexto(unsigned int nroLinea, unsigned int posLinea, Cadena texto)
{
	
	//if (nroLinea > lineas->CantidadElementos()) {
		while (nroLinea > lineas->CantidadElementos()) {
			lineas->AgregarFin(*(new Cadena()));
			//nroLinea++;
		}
	//}
	
	Cadena &aux = lineas->ElementoPos(nroLinea-1); //nrolinea empieza en 1, lineas en 0
	(&aux)->InsertarTexto(posLinea, texto);
	//lineas->AgregarPos(*aux, posLinea);

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
	Cadena aux = lineas->ElementoPos(nroLinea);

	if (nroLinea <= lineas->CantidadElementos()) {
		if (aux.Length() < posLinea) {

			if (k + posLinea > aux.Length()){
				while (aux[posLinea] != '\0') {
					//delete &aux[posLinea];
					char* nuevo = aux.GetNewCharPtr();
					borrarPosicion(nuevo, posLinea);
					Cadena nuevaAux = *new Cadena(nuevo, false);
					aux = nuevaAux;

					delete& nuevaAux;
					delete nuevo;
					posLinea++;
				}
			}
			else{
				while (k != 0){
					//delete &aux[posLinea];
					char* nuevo = aux.GetNewCharPtr();
					borrarPosicion(nuevo, posLinea);
					Cadena nuevaAux = *new Cadena(nuevo, false);
					aux = nuevaAux;
					
					delete &nuevaAux;
					delete nuevo;
					k--;
					posLinea++;
				}

			}


		}
		if (posLinea == 0 && llegueAlFinal) {
			lineas->BorrarPos(nroLinea);
		}
	}
	else {
		//ERROR
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
	ListaPos<Cadena>* aux = lineas;

	while (!aux->EsVacia()) {

		cout << n <<": " << aux->ElementoPos(n-1); // empieza en 0 y n en 1
		n++;
	}
	
	delete aux;
}

void Archivo::EliminarLineas(){
	if (this->lineas != NULL) {
		Iterador<Cadena> itCadena = this->lineas->GetIterador();
		while (!itCadena.EsFin())
		{
			Cadena cadenaCopia = itCadena.Elemento();
			itCadena++;
		}
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
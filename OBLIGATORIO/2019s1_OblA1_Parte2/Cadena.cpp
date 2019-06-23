#include "Cadena.h"

#ifndef CADENA_CPP
#define CADENA_CPP

/****************************************************/
ostream &operator<<(ostream &os, const Cadena &cad){
	if(cad.s)
		os << cad.s;
	return os;
}

istream &operator>>(istream &is, Cadena &cad){
	char aux[200];
	is>>aux;
	cad = aux;
	return is;
}

/****************************************************/
Cadena::Cadena(const char *cad, bool ignoreCase) {
	size_t len = strlen(cad)+1;
	s = new char[len];
	strcpy_s(s, len, cad);
	this->ignoreCase = ignoreCase;
}
/****************************************************/
Cadena::Cadena(){
	s = new char[1];
	s[0] = '\0';
	this->ignoreCase = true;
}
/****************************************************/   
Cadena::Cadena(const Cadena &c) {
	s = NULL;
	*this = c;
}
/****************************************************/
Cadena::~Cadena() {
	if(s)
		delete[] s;
}
/****************************************************/
Cadena &Cadena::operator=(const Cadena &c) {
	if(this != &c) {
		delete [] s;

		size_t len = strlen(c.s)+1;
		s = new char[len];
		strcpy_s(s, len, c.s);

		this->ignoreCase = c.ignoreCase;
	}
	return *this;
}
/****************************************************/
Cadena Cadena::operator+(const Cadena &c) const {
	size_t len = strlen(s)+strlen(c.s)+1;
	char *sNew = new char[len];
	strcpy_s(sNew, len, s);
	strcat_s(sNew, len, c.s);
	Cadena cNew(sNew, ignoreCase);
	delete [] sNew;

	return cNew;
}
/****************************************************/
bool Cadena::operator==(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) == 0;
	else
		return strcmp(s, c.s) == 0;
}
/****************************************************/
bool Cadena::operator!=(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) != 0;
	else
		return strcmp(s, c.s) != 0;
}
/****************************************************/
bool Cadena::operator<(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) < 0;
	else
		return strcmp(s, c.s) < 0;
}
/****************************************************/
bool Cadena::operator>(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) > 0;
	else
		return strcmp(s, c.s) > 0;
}
/****************************************************/
bool Cadena::operator<=(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) <= 0;
	else
		return strcmp(s, c.s) <= 0;
}
/****************************************************/
bool Cadena::operator>=(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) >= 0;
	else
		return strcmp(s, c.s) >= 0;
}
/****************************************************/
char *Cadena::GetNewCharPtr() const {
	size_t len = strlen(s)+1;
	char *ret = new char[len];
	strcpy_s(ret, len, s);
	return ret;
}
/****************************************************/

unsigned int Cadena::Length() const {
	return (unsigned int)strlen(s);
}

bool Cadena::Contains(const Cadena &substr) const {
	if (substr.Length() == 0)
		return true;
	char * s2 = substr.s;
	unsigned int j, j2;

	std::size_t largoS = strlen(s);
	std::size_t largoS2 = strlen(s2);
	if (!ignoreCase) {
		for (unsigned int i = 0; i < largoS; i++) {
			if (i + largoS2 > largoS + 1)
				return false;
			if (s[i] == s2[0]) {
				j = i;
				j2 = 0;
				while (j2 < largoS2 && s[j] == s2[j2]) {
					j++;
					j2++;
				}
				if (j2 == largoS2)
					return true;
			}
		}
	}
	else {
		for (unsigned int i = 0; i < largoS; i++) {
			if (i + largoS2 > largoS + 1)
				return false;
			if (toupper(s[i]) == toupper(s2[0])) {
				j = i;
				j2 = 0;
				while (j2 < largoS2 && toupper(s[j]) == toupper(s2[j2])) {
					j++;
					j2++;
				}
				if (j2 == largoS2)
					return true;
			}
		}
	}
	return false;
}

char Cadena::operator[] (const unsigned int index)
{
	assert (index < Length());
	return s[index];
}

/****************************************************/
bool Cadena::esVacia() {
	return this->Length() == 0;
}

/****************************************************/
void Cadena::QuitarUltimoCaracter() {
	int largo = Length();
	char* aux = new char[largo]();
	for (int i = 0; i < largo; i++)
	{
		if (i == largo - 1) {
			s[i] = '\0';
		}
		else {
			aux[i] = this->s[i];
		}
	}
	*this->s = *aux;
	delete[] aux;
}

void Cadena::InsertarTexto(unsigned int posLinea, Cadena texto) {
	//agrando el vector si la posLinea es mayor que el tamaño de la cadena
	if (posLinea > this->Length()+1) {
		int dif = posLinea - this->Length();
		this->AgrandarNPosiciones(dif);
	}
	//Agrando el tamaño de caracteres que va a ocupar el texto a insertar
	this->AgrandarNPosiciones(texto.Length());
	//inserto el texto en los lugares que quedaron libres;
	char* aux = this->GetNewCharPtr();
	int posAux = 0;
	for (int i = 0; i < posLinea - 1; i++) {
		s[i] = aux[posAux];
		posAux++;
	}
	int posTexto = 0;
	int hasta = posLinea + texto.Length();
	for (int i = posLinea-1; i < hasta-1; i++) {
		s[i] = texto[posTexto];
		posTexto++;
	}
	for (int i = hasta-1; i < this->Length(); i++) {
		s[i] = aux[posAux];
		posAux++;
	}
	delete[] aux;
}

void Cadena::AgrandarNPosiciones(int cantPosiciones) {
	int tamanoInicial = this->Length();
	int nuevoTamano = this->Length() + cantPosiciones;
	char* aux = this->GetNewCharPtr();
	this->s = new char[nuevoTamano];
	for (int i = 0; i < tamanoInicial; i++)
	{
		this->s[i] = aux[i];
	}
	for (int i = tamanoInicial; i <= nuevoTamano; i++)
	{
		if (i == nuevoTamano) {
			this->s[i] = '\0';
		}
		else {

			this->s[i] = ' ';
		}
	}

	delete[] aux;
	
}

void Cadena::EliminarTexto(int posLinea, int k) {
	char* aux = this->GetNewCharPtr();
	int largoInicial = this->Length();
	int posHasta = (posLinea-1) + k;
	if (posHasta > largoInicial) {
		posHasta = largoInicial;
	}
	int sobraDerecha = largoInicial - posLinea;
	bool borraEnElMedio = sobraDerecha - k > 0;
	sobraDerecha = borraEnElMedio ? sobraDerecha - k : 0;
	int tamanoNuevo = posLinea + sobraDerecha;
	this->s = new char[tamanoNuevo]();
	int posNuevo = 0;
	for (int i = 0; i < posLinea-1; i++)
	{
		s[posNuevo] = aux[i];
		posNuevo++;
	}
	if (!borraEnElMedio) {
		s[posNuevo] = '\0';
	} else {
		for (int i = posLinea - 1 + k; i <= largoInicial; i++)
		{
			if (i == largoInicial) {
				s[posNuevo] = '\0';
			}
			else {
				s[posNuevo] = aux[i];
				posNuevo++;
			}
		}
	}
	delete[] aux;
}


#endif
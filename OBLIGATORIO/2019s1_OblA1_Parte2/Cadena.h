#ifndef CADENA_H
#define CADENA_H

#include <string.h>
#include <assert.h>

#include <iostream>
using namespace std;

class Cadena {
	// Entrada y salida de flujo
	friend ostream &operator<<(ostream&, const Cadena &);
	friend istream &operator>>(istream&, Cadena &);
public:

	// Constructor por defecto (string vacio)
	Cadena();

	// Constructor que recibe un string terminado por /0 
	// y si los operadores de comparacion deben ser case sensitive o no 
	// (por defecto case-insensitive)
	Cadena(const char *cad, bool ignoreCase = false);

	// Constructor copia
	Cadena(const Cadena &c);

	// Destructor
	virtual ~Cadena();

	// Operador de asignacion
	Cadena &operator=(const Cadena &c);

	// Operador de suma
	Cadena operator+(const Cadena &c) const;

	// Operadores de comparacion
	bool operator==(const Cadena &c) const;
	bool operator!=(const Cadena &c) const;
	bool operator<(const Cadena &c) const;
    bool operator>(const Cadena &c) const;
    bool operator<=(const Cadena &c) const;
	bool operator>=(const Cadena &c) const;

	// Retorna un nuevo vector de caracteres sin compartir memoria con this
	// El que llame a esta funcion es responsable de la liberacion del retorno con delete []
	char *GetNewCharPtr() const;

	// Retorna el largo del string
	unsigned int Length() const;

	// Retorna true si substr esta contenido en la Cadena
	bool Contains(const Cadena &substr) const;

	// PRE: index < Largo()
	// Retorna el caracter en la posicion index
	char operator[] (const unsigned int index);

	//PRE:
	//POS: retorna true si el string no tiene caracteres
	bool esVacia();

	void QuitarUltimoCaracter();

	void InsertarTexto(unsigned int posLinea, Cadena texto);

protected:
	char *s;
	bool ignoreCase;

	//PRE: La posici�n existe dentro del vector.
	//POS: Desplaza un lugar para adelante todos los elementos a partir de la posici�n POS
	void desplazar(int pos);


	//PRE: -
	//POS: Agranda el vector con cantPosiciones m�s. Las nuevas pocisi�nes tendran el valor " "
	void AgrandarNPosiciones(int cantPosiciones);
};

#endif
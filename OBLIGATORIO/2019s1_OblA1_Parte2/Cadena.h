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

	//PRE:
	//POS: Borra el último caracter de la línea
	void QuitarUltimoCaracter();

	//PRE:
	//POS: Inserta el texto (pasado por parámetro) a partir de la posición posLinea, 
	//desplazando el texto existente (si hay) hacia el final del texto insertado
	void InsertarTexto(unsigned int posLinea, Cadena texto);

	//PRE: posLinea es una posición con texto dentro de la cadena
	//POS: Elimina los k carácteres (si hay k caracteres, si no los que existan) de la cadena a partir de la posición posLinea. 
	void EliminarTexto(int posLinea, int k);

protected:
	char *s;
	bool ignoreCase;

	//PRE: -
	//POS: Agranda el vector con cantPosiciones más. Las nuevas pocisiónes tendran el valor " "
	void AgrandarNPosiciones(int cantPosiciones);
};

#endif
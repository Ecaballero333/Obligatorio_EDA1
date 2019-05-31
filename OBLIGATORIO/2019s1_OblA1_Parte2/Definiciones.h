#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#include <iostream>
using namespace std;
#include <string.h>
#include <assert.h>


struct NodoListaInt {
	int dato;
	NodoListaInt *sig;
	NodoListaInt(int d) : dato(d), sig(NULL) {}
};

struct NodoABInt {
	int dato;
	NodoABInt *izq;
	NodoABInt *der;
	NodoABInt(int d) : dato(d), izq(NULL), der(NULL) {}
};

struct NodoAGInt {
	int dato;
	NodoAGInt *ph;
	NodoAGInt *sh;
	NodoAGInt(int d) : dato(d), ph(NULL), sh(NULL) {}
};

struct NodoListaIntDobleDato {
	int dato1;
	int dato2;
	NodoListaIntDobleDato *sig;
	NodoListaIntDobleDato(int d1, int d2) : dato1(d1), dato2(d2), sig(NULL) {}
};

struct NodoABIntDobleDato {
	int dato1;
	int dato2;
	NodoABIntDobleDato *izq;
	NodoABIntDobleDato *der;
	NodoABIntDobleDato(int d1, int d2) : dato1(d1), dato2(d2), izq(NULL), der(NULL) {}
};

#endif
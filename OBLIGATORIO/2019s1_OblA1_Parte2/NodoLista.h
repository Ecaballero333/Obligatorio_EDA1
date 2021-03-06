#ifndef NODOLISTA_H
#define NODOLISTA_H

#include <iostream>
#include <assert.h>

template <class U>
class NodoLista {
	public:
		U dato;
		NodoLista<U> *ant;
		NodoLista<U> *sig;

		NodoLista(const U &e, NodoLista<U> *a, NodoLista<U> *s) : dato(e), ant(a), sig(s) {}
		virtual ~NodoLista() {}
		
		int Length() {
			int largo = 0;
			NodoLista* l = this;
			while (l != NULL) {
				largo++;
				l = l->sig;
			}
			return largo;
		}

		bool operator<=(NodoLista<U> &l) {
			NodoLista* auxThis = this;
			NodoLista* auxL = &l;
			bool menorIgual = true;
			while (auxThis != NULL && menorIgual) {
				if (auxThis->dato != auxL->dato) {
					menorIgual = false;
				}
				else {
					auxThis = auxThis->sig;
					auxL = auxL->sig;
				}
			}
			return menorIgual;
		}
		
	private:
		NodoLista(const NodoLista<U> &n) : dato(n.dato), ant(n.ant), sig(n.sig)  {}

		NodoLista<U> &operator=(const NodoLista<U> &n) { assert(false); return *this; }
};

#endif
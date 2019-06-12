#include "PruebasPropias.h"

PruebasPropias::PruebasPropias(ConductorPrueba* conductor)
:Prueba(conductor)
{
}

PruebasPropias::~PruebasPropias()
{
}

const char* PruebasPropias::getNombre() const
{
	return "PruebasPropias";
}

template <class T>
void PruebasPropias::ProbarPila(Pila<T> *p)
{
	this->mImpresion.iniciarSeccion("PRUEBAS PILA IMP");

	this->mImpresion.iniciarSeccion("AGREGO 2 ELEMENTOS");
	p->Push(5);
	p->Push(10);
	p->Push(15);
	p->Push(20);
	p->Push(25);
	cout << *p << endl;

	this->mImpresion.iniciarSeccion("QUITO EL TOPE");
	p->Pop();
	cout << *p << endl;

	this->mImpresion.iniciarSeccion("CLONO LA LISTA E IMPRIMO EL CLON");
	Pila<T>* q = p->Clon();
	cout <<* q << endl;

	//cout <<"Dirección p " << p << endl;
	//cout <<"Dirección q " << q << endl;

	this->mImpresion.iniciarSeccion("MODIFICO Q. IMPRIMO P Y Q");
	q->Pop();
	q->Pop();
	cout << *p << endl;
	cout << *q << endl;

	this->mImpresion.iniciarSeccion("IGUAL P A Q E IMPRIMO");
	p = q;//Quedan con la misma direccion de memoria
	//*p = *q;//p queda con los mismos datos que q y no comparten memoria
	cout << *p << endl;
	cout << *q << endl;
	cout << "Dirección p " << p << endl;
	cout << "Dirección q " << q << endl;


	this->mImpresion.iniciarSeccion("USO CONSTRCTOR POR COPIA");


	Pila<T>* nueva = new PilaImp<T>(*p);// llama a PilaImp<T>::PilaImp(const Pila<T>& p)
	PilaImp<T>* nuevap = new PilaImp<T>(*p);// llama a PilaImp<T>::PilaImp(const Pila<T>& p)
	PilaImp<T>* nuevap2 = new PilaImp<T>(*nuevap);// PilaImp<T>::PilaImp(const PilaImp<T>& p)

	
	cout << *nuevap << endl;
	p->Push(50);
	p->Push(69);

	PilaImp<T>* nuevaq = new PilaImp<T>(*p);
	cout << *nuevaq << endl;
	cout << "Dirección nuevap " << nuevap << endl;
	cout << "Dirección nuevaq " << nuevaq << endl;


	/*
	- Cómo puedo ejecutar pruebas tipo las tad, que le diga lo esperado y lo devuelto
	- Porque uso el asterisco en *p en PilaImp<T>* nuevaq = new PilaImp<T>(*p);
	- Porque el p = q; de la linea 48 no invocan al Pila<T>& PilaImp<T>::operator=(const Pila<T>& p) ??? El operator = es solo dentro de la clase?
	- En la cola: El primero es el ultimo elemento de la lista? cuando desencolo sale el ultimo? cuando encolo inserto primero? 
	*/
}

void PruebasPropias::correrPruebaConcreta()
{
	// Este archivo lo puedo modificar para hacer mis propias pruebas

	/*Pila<int> * p = new PilaImp<int>();
	ProbarPila(p);*/

	// Ejemplo:

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(4);
	this->FormarRedBasica(interfaz);

}


void PruebasPropias::FormarRedBasica(InterfazDelSistema* interfaz){

	//se crea directorios
	interfaz->Mkdir("/directorio1"),OK,"Se crea el directorio 'Directorio1'.";
	interfaz->Mkdir("/directorio2"),OK,"Se crea el directorio 'Directorio2'.";
	interfaz->Mkdir("/directorio1/directorio2"),OK,"Se crea el directorio 'Directorio2', dentro de 'Directorio1'.";
	interfaz->Mkdir("/directorio2/directorio1"),OK,"Se crea el directorio 'Directorio1', dentro de 'Directorio2'.";
	interfaz->Mkdir("/directorio1/directorio2/directorio1"),OK,"Se crea el directorio 'Directorio1', dentro de 'Directorio2'.";
	interfaz->Mkdir("/directorio3"),OK,"Se crea el directorio 'Directorio3'.";
	interfaz->Mkdir("/directorio3/directorio2"),OK,"Se crea el directorio 'Directorio2', dentro de 'Directorio3'.";
	interfaz->Mkdir("/directorio3/directorio1"),OK,"Se crea el directorio 'Directorio1', dentro de 'Directorio3'.";
	
	//se crean archivos
	interfaz->CreateFile("/archivo1.txt"),OK,"Se crea archivo1.txt en /.";
	interfaz->CreateFile("/Archivo1.txt"),OK,"Se crea Archivo1.txt en /.";
	interfaz->CreateFile("/directorio1/archivo11.txt"),OK,"Se crea archivo11.txt en /directorio1/directorio11.";
	interfaz->CreateFile("/directorio2/directorio1/archivo11.txt"),OK,"Se crea archivo11.txt en /directorio2/directorio1.";
	interfaz->CreateFile("/directorio3/directorio1/archivo11.txt"),OK,"Se crea archivo11.txt en /directorio3/directorio1.";
	interfaz->CreateFile("/directorio2/documento.txt"),OK,"Se crea documento.txt en /directorio2.";
	interfaz->CreateFile("/directorio3/directorio2/documento.txt"),OK,"Se crea documento.txt en /directorio3/directorio2.";

	//se introduce texto en archivos
	 interfaz->InsertText("/archivo1.txt", 1,1, "An error saepe."),OK,"Se inserta texto en archivo1.txt, linea 1, posicion 1.";
	 interfaz->InsertText("/archivo1.txt", 1,30, "An error saepe."),OK,"Se inserta texto en archivo1.txt, linea 1 posicion 30";
	 interfaz->InsertText("/archivo1.txt",40,1, "Vis omnis legere"),OK,"Se inserta texto en archivo1.txt, linea 4, posicion 1";
	 interfaz->InsertText("/archivo1.txt", 4,1, "Omnesque philosophia eum an, ius tale."),OK,"Se inserta texto en archivo1.txt, en linea 4, posicion 1";
	 interfaz->InsertText("/directorio3/directorio1/archivo11.txt", 1,1, "Ius invidunt convenire at, has in atqui probatus deserunt."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 1, posicion 1";
	 interfaz->InsertText("/directorio3/directorio1/archivo11.txt", 1,1, "Eos nibh regione."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 1, posicion 1";
	 interfaz->InsertText("/directorio3/directorio1/archivo11.txt", 10,1, "Sed fabulas laoreet appellantur."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 10, posicion 1";
	 interfaz->InsertText("/directorio3/directorio1/archivo11.txt", 4,1, "Mel et illum sententiae, vix inani."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 4, posicion 1";
	 interfaz->InsertText("/directorio2/directorio1/archivo11.txt",1,1, "Usu rebum virtute."),OK,"Se inserta texto en /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt, en linea 1, posicion 1";
	 interfaz->InsertText("/directorio2/directorio1/archivo11.txt",2,1, "Eam habeo."),OK,"Se inserta texto en /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt, en linea 2, posicion 1";
	 interfaz->InsertText("/directorio2/directorio1/archivo11.txt",3,1, "His no putant vivendo."),OK,"Se inserta texto en /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt, en linea 3, posicion 1";

}

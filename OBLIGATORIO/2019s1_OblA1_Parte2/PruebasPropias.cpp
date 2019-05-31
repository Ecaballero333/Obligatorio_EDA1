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

void PruebasPropias::correrPruebaConcreta()
{
	// Este archivo lo puedo modificar para hacer mis propias pruebas
	
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

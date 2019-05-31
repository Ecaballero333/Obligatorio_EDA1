#include "ConductorPruebaObl2.h"
#include "ManejadorArchivos.h"
#include <iostream>
#include <fstream>
using namespace std;

// NO MODIFICAR ACA. HACER LAS PRUEBAS EN EL ARCHIVO PRUEBASPROPIAS.CPP
int main()
{
	_mkdir("./SalidaDeLasPruebas");
	_mkdir("./SalidaDeLasPruebas/Resultados");
	_mkdir("./SalidaDeLasPruebas/SalidasSinProcesar");
	system("del /Q .\\SalidaDeLasPruebas\\Resultados\\*.*");
	system("del /Q .\\SalidaDeLasPruebas\\SalidasSinProcesar\\*.*");

	ConductorPrueba* prueba = new ConductorPruebaObl2();
	prueba->correrPrueba();
	delete prueba;

	char rutaLectura1[] = "../SalidaDeLasPruebas/SalidasSinProcesar/PruebasEjemploDeUso.txt";
	char rutaCorreccion1[] = "../PruebasEjemploDeUso.txt";
	char rutaEscritura1[] = "../SalidaDeLasPruebas/Resultados/PruebasEjemploDeUsoResultado.txt";
	ManejadorArchivos* m = new ManejadorArchivos(rutaLectura1, rutaCorreccion1, rutaEscritura1);
	
	// Comparar
	// - Parametro 1: si se le pasa true muestra el resultado de todas las salidas incluso cuando dan OK
	// - Parametro 2: si se le pasa true solamente muestra las pruebas que no están correctas
	m->Comparar(false, false);
	delete m;

	char rutaLectura3[] = "../SalidaDeLasPruebas/SalidasSinProcesar/PruebasCorreccion.txt";
	char rutaCorreccion3[] = "../PruebasCorreccion.txt";
	char rutaEscritura3[] = "../SalidaDeLasPruebas/Resultados/PruebasCorreccionResultado.txt";
	m = new ManejadorArchivos(rutaLectura3, rutaCorreccion3, rutaEscritura3);

	// Comparar
	// - Parametro 1: si se le pasa true muestra el resultado de todas las salidas incluso cuando dan OK
	// - Parametro 2: si se le pasa true solamente muestra las pruebas que no están correctas
	m->Comparar(false, false);
	delete m;

	char rutaLectura4[] = "../SalidaDeLasPruebas/SalidasSinProcesar/PruebasTad.txt";
	char rutaCorreccion4[] = "../PruebasTad.txt";
	char rutaEscritura4[] = "../SalidaDeLasPruebas/Resultados/PruebasTadResultado.txt";
	m = new ManejadorArchivos(rutaLectura4, rutaCorreccion4, rutaEscritura4);

	// Comparar
	// - Parametro 1: si se le pasa true muestra el resultado de todas las salidas incluso cuando dan OK
	// - Parametro 2: si se le pasa true solamente muestra las pruebas que no están correctas
	m->Comparar(false, false);
	delete m;

	/*
	char rutaLectura4[] = "../SalidaDeLasPruebas/SalidasSinProcesar/PruebasPropias.txt";
	char rutaCorreccion4[] = "../PruebasPropias.txt";
	char rutaEscritura4[] = "../SalidaDeLasPruebas/Resultados/PruebasPropiasResultado.txt";
	m = new ManejadorArchivos(rutaLectura4, rutaCorreccion4, rutaEscritura4);
	
	// Comparar
	// - Parametro 1: si se le pasa true muestra el resultado de todas las salidas incluso cuando dan OK
	// - Parametro 2: si se le pasa true solamente muestra las pruebas que no están correctas
	m->Comparar(false, false); 
	delete m;
	*/

	//system("pause");
	return 0;
}


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

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(2);
	this->FormarRedBasica(interfaz);

}


void PruebasPropias::FormarRedBasica(InterfazDelSistema* interfaz){

	/**************MKDIR***************/
	cout << "/**************MKDIR***************/" << endl;
	//se crea directorios
	interfaz->Mkdir("/directorio1"),OK,"Se crea el directorio 'Directorio1'.";
	interfaz->Mkdir("/directorio2"),OK,"Se crea el directorio 'Directorio2'.";
	interfaz->Mkdir("/directorio1/directorio2"),OK,"Se crea el directorio 'Directorio2', dentro de 'Directorio1'.";
	interfaz->Mkdir("/directorio2/directorio1"),OK,"Se crea el directorio 'Directorio1', dentro de 'Directorio2'.";
	interfaz->Mkdir("/directorio1/directorio2/directorio1"),OK,"Se crea el directorio 'Directorio1', dentro de 'Directorio2'.";
	interfaz->Mkdir("/directorio3"),OK,"Se crea el directorio 'Directorio3'.";
	interfaz->Mkdir("/directorio3/directorio2"),OK,"Se crea el directorio 'Directorio2', dentro de 'Directorio3'.";
	interfaz->Mkdir("/directorio3/directorio1"),OK,"Se crea el directorio 'Directorio1', dentro de 'Directorio3'.";
	
	cout << "#####################################################" << endl;
	cout << "Se crean 8 directorios (desordenados) y se muestran. Pruebo que el orden en el que se muestran esté ok"<<endl;
	interfaz->Dir("/", "");

	/*Prueba Errores*/

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba Mkdir ERROR: La ruta no comienza con /." << endl;
	interfaz->Mkdir("directorio4");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba Mkdir ERROR: No se encuentra la ruta." << endl;
	interfaz->Mkdir("/directorio4/directorio5");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba Mkdir ERROR: Ya existe un subdirectorio con el mismo nombre en esa ruta." << endl;
	interfaz->Mkdir("/directorio1/directorio2/directorio1");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba Mkdir ERROR: No se puede volver a crear el directorio raíz." << endl;
	interfaz->Mkdir("/");

	cout << "" << endl;
	/**************CREATEFILE***************/
	cout << "/**************CREATEFILE***************/" << endl;
	//se crean archivos
	interfaz->CreateFile("/archivo1.txt"),OK,"Se crea archivo1.txt en /.";
	interfaz->CreateFile("/Archivo1.txt"),OK,"Se crea Archivo1.txt en /.";
	interfaz->CreateFile("/directorio1/archivo11.txt"),OK,"Se crea archivo11.txt en /directorio1/directorio11.";
	interfaz->CreateFile("/directorio2/directorio1/archivo11.txt"),OK,"Se crea archivo11.txt en /directorio2/directorio1.";
	interfaz->CreateFile("/directorio3/directorio1/archivo11.txt"),OK,"Se crea archivo11.txt en /directorio3/directorio1.";
	interfaz->CreateFile("/directorio2/documento.txt"),OK,"Se crea documento.txt en /directorio2.";
	interfaz->CreateFile("/directorio3/directorio2/documento.txt"),OK,"Se crea documento.txt en /directorio3/directorio2.";
	interfaz->CreateFile("/directorio2/directorio1/b.pdf"), OK, "Se crea archivo11.txt en /directorio2/directorio1.";
	interfaz->CreateFile("/directorio2/directorio1/archivo11.pdf"), OK, "Se crea archivo11.txt en /directorio2/directorio1.";
	interfaz->CreateFile("/directorio1/archivo10.txt"), OK, "Se crea archivo11.txt en /directorio1/directorio11.";
	
	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Se crean 10 archivos desordenados y se muestran. Pruebo que se creen bien todos y se muestren ordenados en sus directorios" << endl;
	interfaz->Dir("/", "-H");

	/*Prueba Errores*/

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba 1 CreateFile ERROR: La ruta no comienza con /." << endl;
	interfaz->CreateFile("directorio4");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba 2 CreateFile ERROR: La ruta no comienza con /." << endl;
	interfaz->CreateFile("");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba 1 CreateFile ERROR: No se encuentra la ruta." << endl;
	interfaz->CreateFile("/directorio4/hola.pdf");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba 2 CreateFile ERROR: No se encuentra la ruta." << endl;
	interfaz->CreateFile("/directorio4/directorio1/hola.pdf");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba 2 CreateFile ERROR: Ya existe un archivo con el mismo nombre en esa ruta." << endl;
	interfaz->CreateFile("/Archivo1.txt");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba 2 CreateFile ERROR: Ya existe un archivo con el mismo nombre en esa ruta." << endl;
	interfaz->CreateFile("/directorio3/directorio2/documento.txt");

	cout << "" << endl;
	/**************ATTRIB***************/
	cout << "/**************ATTRIB***************/" << endl;
	//Se cambia la visibilidad de todos los archivos
	interfaz->Attrib("/archivo1.txt","+H");
	interfaz->Attrib("/Archivo1.txt", "+H");
	interfaz->Attrib("/directorio1/archivo11.txt", "+H");
	interfaz->Attrib("/directorio2/directorio1/archivo11.txt", "+H");
	interfaz->Attrib("/directorio3/directorio1/archivo11.txt", "+H");
	interfaz->Attrib("/directorio2/documento.txt", "+H");
	interfaz->Attrib("/directorio3/directorio2/documento.txt", "+H");
	interfaz->Attrib("/directorio2/directorio1/b.pdf", "+H");
	interfaz->Attrib("/directorio2/directorio1/archivo11.pdf", "+H");
	interfaz->Attrib("/directorio1/archivo10.txt", "+H");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Se ocultan todos los archivos y se muestan solo los visibles" << endl;
	interfaz->Dir("/", "");
	cout << "" << endl;
	cout << "Se ocultan todos los archivos y se muestan todos los archivos" << endl;
	interfaz->Dir("/", "-H");


	interfaz->Attrib("/directorio2/directorio1/archivo11.txt", "-H");
	interfaz->Attrib("/directorio3/directorio2/documento.txt", "-H");
	interfaz->Attrib("/directorio2/directorio1/archivo11.pdf", "-H");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Se vuelven a mostrar 3 archivos y se muestan solo los visibles" << endl;
	interfaz->Dir("/", "");
	cout << "" << endl;
	cout << "Se vuelven a mostrar 2 archivos y se muestan todos los archivos" << endl;
	interfaz->Dir("/", "-H");

	/*Prueba Errores*/

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba Attrib ERROR: La ruta no comienza con /." << endl;
	interfaz->Attrib("directorio2/directorio1/archivo11.txt", "-H");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba Attrib ERROR: No se encuentra la ruta." << endl;
	interfaz->Attrib("/directorio2/directorio2/archivo11.txt", "+H");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba Attrib ERROR: No existe un archivo con ese nombre en esa ruta." << endl;
	interfaz->Attrib("/directorio2/directorio1/prueba.txt", "-H");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba 1 Attrib ERROR: Parametro desconocido." << endl;
	interfaz->Attrib("/directorio2/directorio1/archivo11.txt", "A");

	cout << "" << endl;
	cout << "#####################################################" << endl;
	cout << "Prueba 2 Attrib ERROR: Parametro desconocido." << endl;
	interfaz->Attrib("/directorio2/directorio1/archivo11.txt", "");

	cout << "" << endl;
	/**************INSERTTEXT***************/
	cout << "/**************INSERTTEXT***************/" << endl;
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

	 /*Prueba Errores*/
	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba InsertText ERROR: La ruta no comienza con /." << endl;
	 interfaz->InsertText("directorio2/directorio1/archivo11.txt", 3, 1, "His no putant vivendo.");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba InsertText ERROR: No se encuentra la ruta." << endl;
	 interfaz->InsertText("/directorio2/directorio2/archivo11.txt", 3, 1, "His no putant vivendo.");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba InsertText No existe un archivo con ese nombre en esa ruta. " << endl;
	 interfaz->InsertText("/directorio2/directorio1/archivo20.txt", 3, 1, "His no putant vivendo.");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba InsertText ERROR: La linea cero no es valida." << endl;
	 interfaz->InsertText("/directorio2/directorio1/archivo11.txt", 0, 1, "His no putant vivendo.");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba InsertText ERROR: La posicion cero no es valida." << endl;
	 interfaz->InsertText("/directorio2/directorio1/archivo11.txt", 3, 0, "His no putant vivendo.");

	 cout << "" << endl;
	 /**************TYPE***************/
	 cout << "/**************TYPE***************/" << endl;
	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Se muestra el contenido de cada archivo" << endl;
	 interfaz->Type("/archivo1.txt");
	 cout << "" << endl;
	 interfaz->Type("/directorio3/directorio1/archivo11.txt");
	 cout << "" << endl;
	 interfaz->Type("/directorio2/directorio1/archivo11.txt");
	 cout << "" << endl;

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Se muestran los archivos ocultos y vuelve a mostrar el texto" << endl;
	 interfaz->Attrib("/archivo1.txt","-H");
	 interfaz->Attrib("/directorio3/directorio1/archivo11.txt", "-H");
	 interfaz->Type("/archivo1.txt");
	 cout << "" << endl;
	 interfaz->Type("/directorio3/directorio1/archivo11.txt");
	 cout << "" << endl;

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Se inserta texto en un archivo vacío y se muestra" << endl;
	 interfaz->Attrib("/directorio1/archivo10.txt", "-H");
	 interfaz->InsertText("/directorio1/archivo10.txt", 3, 10, "Hola, bien?");
	 interfaz->InsertText("/directorio1/archivo10.txt", 3, 16, "todo ");
	 interfaz->InsertText("/directorio1/archivo10.txt", 5, 5, "Pruba de texto");
	 interfaz->InsertText("/directorio1/archivo10.txt", 5, 4, "Esto es una");
	 interfaz->InsertText("/directorio1/archivo10.txt", 2, 1, "Esto prueba");
	 interfaz->InsertText("/directorio1/archivo10.txt", 2, 6, "es una ");
	 interfaz->InsertText("/directorio1/archivo10.txt", 2, 20, "type");
	 interfaz->Type("/directorio1/archivo10.txt");

	 /*Prueba Errores*/

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba Type ERROR: La ruta no comienza con /." << endl;
	 interfaz->Type("directorio1/archivo10.txt");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba Type ERROR: No se encuentra la ruta." << endl;
	 interfaz->Type("/directorio10/archivo10.txt");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba Type ERROR: No existe un archivo con ese nombre en esa ruta." << endl;
	 interfaz->Type("/directorio1/archivo59.txt");

	 cout << "" << endl;

	 /**************DeleteText***************/
	 cout << "/**************DeleteText***************/" << endl; 
	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Se borra texto de un archivo y se muestra" << endl;
	 interfaz->DeleteText("/directorio1/archivo10.txt", 3, 5, 10);
	 interfaz->DeleteText("/directorio1/archivo10.txt", 2, 1, 19);
	 interfaz->DeleteText("/directorio1/archivo10.txt", 5, 9, 3);

	 interfaz->Type("/directorio1/archivo10.txt");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DeleteText ERROR: La ruta no comienza con /." << endl;
	 interfaz->DeleteText("directorio1/archivo10.txt", 5, 9, 3);

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DeleteText ERROR: No se encuentra la ruta." << endl;
	 interfaz->DeleteText("/directorio25/archivo10.txt", 5, 9, 3);

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DeleteText ERROR: No existe un archivo con ese nombre en esa ruta." << endl;
	 interfaz->DeleteText("/directorio1/archivo13.txt", 5, 9, 3);

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DeleteText ERROR: La linea cero no es valida." << endl;
	 interfaz->DeleteText("/directorio1/archivo10.txt", 0, 9, 3);

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DeleteText ERROR: La linea no existe." << endl;
	 interfaz->DeleteText("/directorio1/archivo10.txt", 10, 9, 3);

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DeleteText ERROR: La posicion cero no es valida." << endl;
	 interfaz->DeleteText("/directorio1/archivo10.txt", 5, 0, 3);

	 /**************delete***************/
	 cout << "/**************delete***************/" << endl;
	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Se  muestra el directorio raíz completo" << endl;
	 cout << "" << endl;
	 interfaz->Dir("/", "-H");

	 cout << "Se borran 3 archivos y se muestra el directorio raíz completo" << endl;

	 interfaz->Delete("/archivo1.txt");
	 interfaz->Delete("/Archivo1.txt");
	 interfaz->Delete("/directorio1/archivo11.txt");

	 cout << "" << endl;
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 cout << "Se intenta ver el contenido de los 3 archivos borrados" << endl;
	 cout << "" << endl;
	 interfaz->Type("/archivo1.txt");
	 interfaz->Type("/Archivo1.txt");
	 interfaz->Type("/directorio1/archivo11.txt");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba delete ERROR: La ruta no comienza con /." << endl;
	 interfaz->Delete("directorio2/directorio1/archivo11.txt");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba delete ERROR: No se encuentra la ruta." << endl;
	 interfaz->Delete("/directorio2/directorio3/archivo11.txt");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba delete ERROR: No existe un archivo con ese nombre en esa ruta." << endl;
	 interfaz->Delete("/directorio2/directorio1/archivo13.txt");

	 /**************UNDELETE***************/
	 cout << "/**************UNDELETE***************/" << endl;
	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Se  muestra el directorio raíz completo" << endl;
	 cout << "" << endl;
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 cout << "El máximo de archivos a recuperar es 2" << endl;

	 cout << "" << endl;
	 cout << "1- Se recupera un archivo y se muestra el directorio raíz completo" << endl;
	 interfaz->Undelete();
	 interfaz->Dir("/", "-H");
	 
	 cout << "" << endl;
	 cout << "2 - Se recupera un archivo y se muestra el directorio raíz completo" << endl;
	 interfaz->Undelete();
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba UNDELETE ERROR: No hay archivos para recuperar." << endl;
	 interfaz->Undelete();
	 cout << "" << endl;
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 cout << "Se elimina un archivo y se muestra el directorio raíz completo" << endl;
	 interfaz->Delete("/Archivo1.txt");
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 cout << "Se crea el mismo archivo y se muestra el directorio raíz completo" << endl;
	 interfaz->CreateFile("/Archivo1.txt");
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 cout << "Se intenta recuperar el archivo y se muestra el directorio raíz completo" << endl;
	 interfaz->Undelete();
	 interfaz->Dir("/", "-H");

	 cout << "Se elimina un archivo y se muestra el directorio raíz completo" << endl;
	 interfaz->Delete("/directorio3/directorio2/documento.txt");
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 cout << "Se elimina el directorio del archivo y se muestra el directorio raíz completo" << endl;
	 interfaz->Rmdir("/directorio3/directorio2");
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 cout << "Se intenta recuperar el archivo y se muestra el directorio raíz completo" << endl;
	 interfaz->Undelete();
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 /**************copydir***************/
	 cout << "/**************copydir***************/" << endl;
	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Se muestra el direcorio raíz completo, se copia un directorio y se vuelve a mostrar el raíz" << endl;
	 cout << "" << endl;
	 interfaz->Dir("/", "-H");
	 cout << "" << endl;
	 interfaz->CopyDir("/directorio1","/directorio3/directorio2");
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba copydir 1 ERROR: La ruta no comienza con /." << endl;
	 interfaz->CopyDir("directorio1", "/directorio3/directorio2");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba copydir 2 ERROR: La ruta no comienza con /." << endl;
	 interfaz->CopyDir("/directorio1", "directorio3/directorio2");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba copydir ERROR: No se encuentra la ruta origen." << endl;
	 interfaz->CopyDir("/directorio33", "/directorio3/directorio2");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba copydir ERROR: Ya existe la ruta destino." << endl;
	 interfaz->CopyDir("/directorio1", "/directorio3/directorio1");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba copydir 1 ERROR: La ruta destino no puede ser un subdirectorio de origen." << endl;
	 interfaz->CopyDir("/directorio1", "/directorio1/directorio2");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba copydir 2 ERROR: La ruta destino no puede ser un subdirectorio de origen." << endl;
	 interfaz->CopyDir("/directorio1", "/directorio1/directorio2/directorio1");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba copydir ERROR: No se encuentra el padre de la ruta destino." << endl;
	 interfaz->CopyDir("/directorio1", "/directorio4/directorio2");

	 cout << "" << endl;
	 /**************RMDIR***************/
	 cout << "/**************RMDIR***************/" << endl;
	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Se borran 2 directorios y se muestra el directorio raíz completo" << endl;
	 cout << "" << endl;
	 interfaz->Rmdir("/directorio3/directorio2");
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 interfaz->Rmdir("/directorio1");
	 interfaz->Dir("/", "-H");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba RMDIR ERROR: La ruta no comienza con /." << endl;
	 interfaz->Rmdir("directorio1");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba RMDIR ERROR: No se encuentra la ruta." << endl;
	 interfaz->Rmdir("/directorio1");


	 cout << "" << endl;
	 /**************DIR***************/
	 cout << "/**************DIR***************/" << endl;
	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Se muestra un subdirectorio con archivos" << endl;
	 interfaz->Dir("/directorio2/directorio1", "-H");
	 cout << "" << endl; 
	 cout << "Se crea un subdirectorio vacío y se muestra" << endl;
	 cout << "" << endl;
	 interfaz->Mkdir("/directorio3/directorio1/directorio5");
	 interfaz->Dir("/directorio3/directorio1/directorio5", "-H");
	 cout << "" << endl;

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DIR ERROR: La ruta no comienza con /." << endl; 
	 interfaz->Dir("directorio3/directorio1", "-H");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DIR ERROR: No se encuentra la ruta." << endl;
	 interfaz->Dir("/directorio3/directorio1/directorio5/directorio99", "-H");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DIR 1 ERROR: Parametro desconocido." << endl;
	 interfaz->Dir("/directorio3/directorio1/directorio5", "-V");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DIR 2 ERROR: Parametro desconocido." << endl;
	 interfaz->Dir("/directorio3/directorio1/directorio5", "-h");

	 cout << "" << endl;
	 cout << "#####################################################" << endl;
	 cout << "Prueba DIR 3 ERROR: Parametro desconocido." << endl;
	 interfaz->Dir("/directorio3/directorio1/directorio5", "H");

	 /**************DIR***************/
	 cout << "/**************DIR***************/" << endl; 
	 cout << "Se muestra el directorio raíz completo, se borra la raíz y se vuelve a mostrar" << endl;

	 cout << "" << endl;
	 interfaz->Dir("/", "-H");
	 interfaz->Rmdir("/");
	 cout << "" << endl;
	 interfaz->Dir("/", "-H");
}

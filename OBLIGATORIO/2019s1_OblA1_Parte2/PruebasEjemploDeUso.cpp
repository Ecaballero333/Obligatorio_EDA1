#include "PruebasEjemploDeUso.h"

PruebasEjemploDeUso::PruebasEjemploDeUso(ConductorPrueba* conductor)
:Prueba(conductor)
{

}

PruebasEjemploDeUso::~PruebasEjemploDeUso()
{
	
}

const char* PruebasEjemploDeUso::getNombre()const
{
	return "PruebasEjemploDeUso";
}

void PruebasEjemploDeUso::correrPruebaConcreta()
{
	//cout<<"\n\n";
	//cout<<"*********************************************************************\n\n";
	//cout<<"********************** PRUEBAS EJEMPLO DE USO ***********************\n";
	//cout<<"*********************************************************************\n\n";

	//cout<<"\n\n";
	//cout<<"*********************************************************************\n\n";
	//cout<<"******************** PRUEBAS EJEMPLO DE USO OK **********************\n";
	//cout<<"*********************************************************************\n\n";


	PruebasOK();

	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------ FIN PRUEBAS EJEMPLO DE USO OK --------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl;

	//cout<<"\n\n";
	//cout<<"*********************************************************************\n\n";
	//cout<<"********************* PRUEBAS EJEMPLO DE USO ERROR ******************\n";
	//cout<<"*********************************************************************\n\n";

	PruebasError();
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------------- FIN PRUEBAS EJEMPLO DE USO ERROR. -------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl;

	//cout<<"\n\n";
	//cout<<"*********************************************************************\n\n";
	//cout<<"************************ PRUEBAS DE OPCIONAL ************************\n";
	//cout<<"*********************************************************************\n\n";

	PruebasOKOpcional();
	PruebasErrorOpcional();

	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"-------------------- FIN PRUEBAS DE OPCIONAL. -----------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"-------------------- FIN PRUEBAS EJEMPLO DE USO. --------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl;
}

void PruebasEjemploDeUso::PruebasOK()
{	
	PruebasOKTipo1();
	PruebasOKRmdir();
	PruebasOKCopydir();
	PruebasOKDelete();
	PruebasOKAttrib();
	PruebasOKDeleteText();
};

void PruebasEjemploDeUso::PruebasError()
{
	PruebasErrorCrearDirectorio();
	PruebasErrorEliminarDirectorio();
	PruebasErrorCopiarDirectorio();
	PruebasErrorMostrarDirectorio();
	PruebasErrorCrearArchivo();
	PruebasErrorEliminarArchivo();
	PruebasErrorModificarParametros();
	PruebasErrorEliminarTexto();
	PruebasErrorInsertarTexto();
	PruebasErrorMostrarArchivo();
}

void PruebasEjemploDeUso::PruebasOKOpcional()
{	
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------------------- Pruebas para OK opcional ----------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(6);
	this->FormarRedBasica(interfaz);

	this->mImpresion.iniciarSeccion("PRUEBAS Opcional");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->Delete("/archivo1.txt"), OK, "Se borra archivo /archivo1.txt");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->Undelete(), OK, "Se recupera /archivo1.txt");

	ver2(interfaz->Type("/archivo1.txt"),OK,"Se muestra /archivo1.txt");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->Delete("/directorio1/directorio11/archivo11.txt"), OK, "Se borra archivo /directorio1/directorio11/archivo11.txt");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->Undelete(), OK, "Se recupera /directorio1/directorio11/archivo11.txt");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->Type("/directorio1/directorio11/archivo11.txt"),OK,"Se muestra /directorio1/directorio11/archivo11.txt");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Opcional");
	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"-------------------- Fin de pruebas OK Opcional  --------------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

};

void PruebasEjemploDeUso::PruebasErrorOpcional()
{
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------------- PruebasERROR Opcional -----------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Error Opcional");

	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(0);
	
	ver2(interfaz->Undelete(), ERROR, "No hay archivos para recuperar");
	
	this->mImpresion.cerrarSeccion("PRUEBAS Error Opcional");
	delete interfaz;

	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------- Fin de pruebasERROR Opcional -----------------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasOKTipo1()
{
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"----------------- Prueba las operaciones de Tipo 1 ------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;


	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------- Pruebas para Crear Directorio -------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Mkdir");

	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(6);

	ver2(interfaz->Mkdir("/directorio1"),OK,"Se crea el directorio 'Directorio1'.");	
	ver2(interfaz->Mkdir("/directorio2"),OK,"Se crea el directorio 'Directorio2'.");
	ver2(interfaz->Mkdir("/directorio1/directorio11"),OK,"Se crea el directorio 'Directorio11', dentro de 'Directorio1'.");
	ver2(interfaz->Mkdir("/directorio1/directorio12"),OK,"Se crea el directorio 'Directorio12', dentro de 'Directorio1'.");
	ver2(interfaz->Mkdir("/directorio2/directorio21"),OK,"Se crea el directorio 'Directorio21', dentro de 'Directorio2'.");
	ver2(interfaz->Mkdir("/directorio2/directorio22"),OK,"Se crea el directorio 'Directorio22', dentro de 'Directorio2'.");
	ver2(interfaz->Mkdir("/directorio2/directorio21/directorio211"),OK,"Se crea el directorio 'Directorio211', dentro de 'Directorio21'.");
	ver2(interfaz->Mkdir("/directorio2/directorio21/directorio211/directorio2111"),OK,"Se crea el directorio 'Directorio2111', dentro de 'Directorio211'.");
	
	ver2(interfaz->Dir("/", ""),OK,"Se muestran todo el contenido del filesystem.");
	
	this->mImpresion.cerrarSeccion("PRUEBAS Mkdir");

	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------- Pruebas para Crear archivo  ---------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS CreateFile");

	ver2(interfaz->CreateFile("/archivo1.txt"),OK,"Se crea archivo1.txt en /.");
	ver2(interfaz->CreateFile("/directorio1/directorio11/archivo11.txt"),OK,"Se crea archivo11.txt en /directorio1/directorio11.");
	ver2(interfaz->CreateFile("/directorio1/directorio11/archivo12.txt"),OK,"Se crea archivo12.txt en /directorio1/directorio11.");
	ver2(interfaz->CreateFile("/directorio1/directorio11/archivo13.txt"),OK,"Se crea archivo13.txt en /directorio1/directorio11.");
	ver2(interfaz->CreateFile("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt"),OK,"Se crea archivo2111.txt en /directorio2/directorio21/directorio211/directorio2111.");
	ver2(interfaz->CreateFile("/directorio2/directorio21/directorio211/archivo211.h"),OK,"Se crea archivo211.h en /directorio2/directorio21/directorio211.");
	ver2(interfaz->CreateFile("/directorio2/directorio21/directorio211/archivo212.ppt"),OK,"Se crea archivo212.ppt en /directorio2/directorio21/directorio211.");
	ver2(interfaz->CreateFile("/directorio2/directorio22/archivo22.txt"),OK,"Se crea archivo22.txt en /directorio2/directorio22.");
	ver2(interfaz->CreateFile("/directorio2/directorio22/Archivo22.txt"),OK,"Se crea Archivo22.txt en /directorio2/directorio22.");
	ver2(interfaz->CreateFile("/directorio2/directorio22/Archivo23.txt"),OK,"Se crea Archivo23.txt en /directorio2/directorio22.");

	ver2(interfaz->Dir("/", ""),OK,"Se muestran todo el contenido del filesystem.");

	this->mImpresion.cerrarSeccion("PRUEBAS CreateFile");

	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------- Pruebas para Mostrar Directorios ------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Dir");

	ver2(interfaz->Dir("/directorio1", ""),OK,"Se muestra contenido de /directorio1");
	ver2(interfaz->Dir("/directorio1/directorio12", ""),OK,"Se muestra contenido de /directorio1/directorio12");
	ver2(interfaz->Dir("/directorio2", ""),OK,"Se muestra contenido de /directorio2");
	ver2(interfaz->Dir("/directorio2/directorio21/directorio211", ""),OK,"Se muestra contenido de /directorio2/directorio21/directorio211");
	ver2(interfaz->Dir("/directorio2/directorio21/directorio211/directorio2111", ""),OK,"Se muestra contenido de /directorio2/directorio21/directorio211/directorio2111");

	this->mImpresion.cerrarSeccion("PRUEBAS Dir");


	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------------------- Pruebas para Insertar texto ------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS InsertText");

	ver2(interfaz->InsertText("/archivo1.txt", 1,1, "An error saepe."),OK,"Se inserta texto en archivo1.txt, linea 1, posicion 1.");
	ver2(interfaz->InsertText("/archivo1.txt", 1,30, "An error saepe."),OK,"Se inserta texto en archivo1.txt, linea 1 posicion 30");
	ver2(interfaz->InsertText("/archivo1.txt", 4,1, "Vis omnis legere"),OK,"Se inserta texto en archivo1.txt, linea 4, posicion 1");
	ver2(interfaz->InsertText("/archivo1.txt", 4,1, "Omnesque philosophia eum an, ius tale."),OK,"Se inserta texto en archivo1.txt, en linea 4, posicion 1");
	ver2(interfaz->InsertText("/directorio1/directorio11/archivo11.txt", 1,1, "Ius invidunt convenire at, has in atqui probatus deserunt."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 1, posicion 1");
	ver2(interfaz->InsertText("/directorio1/directorio11/archivo11.txt", 1,1, "Eos nibh regione."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 1, posicion 1");
	ver2(interfaz->InsertText("/directorio1/directorio11/archivo11.txt", 10,1, "Sed fabulas laoreet appellantur."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 10, posicion 1");
	ver2(interfaz->InsertText("/directorio1/directorio11/archivo11.txt", 4,1, "Mel et illum sententiae, vix inani."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 4, posicion 1");
	ver2(interfaz->InsertText("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt",1,1, "Usu rebum virtute."),OK,"Se inserta texto en /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt, en linea 1, posicion 1");
	ver2(interfaz->InsertText("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt",2,1, "Eam habeo."),OK,"Se inserta texto en /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt, en linea 2, posicion 1");
	ver2(interfaz->InsertText("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt",3,1, "His no putant vivendo."),OK,"Se inserta texto en /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt, en linea 3, posicion 1");
	
	this->mImpresion.cerrarSeccion("PRUEBAS InsertText");



	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------ Pruebas para Mostrar Archivo --------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Type");

	ver2(interfaz->Type("/archivo1.txt"),OK,"Se muestra /archivo1.txt");
	ver2(interfaz->Type("/directorio1/directorio11/archivo11.txt"),OK,"Se muestra /directorio1/directorio11/archivo11.txt");
	ver2(interfaz->Type("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt"),OK,"Se muestra /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt");
	ver2(interfaz->Type("/directorio1/directorio11/archivo13.txt"),OK,"Se muestra /directorio1/directorio11/archivo13.txt");



	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------ Pruebas para Destruir filesystem -------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	delete interfaz;
	ver2(OK,OK, "Se destruye filesystem y memoria asociada");

	this->mImpresion.cerrarSeccion("PRUEBAS Type");

	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"----------- Fin de pruebas OK para las operaciones Tipo 1 -----------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	
}

void PruebasEjemploDeUso::PruebasOKRmdir(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------ Pruebas para Eliminar Directorio -----------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Rmdir");
		
	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(6);
	this->FormarRedBasica(interfaz);

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->Rmdir("/directorio1/directorio11"), OK, "Se borra directorio /directorio1/directorio11");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->Rmdir("/directorio2/directorio21/directorio211/directorio2111"), OK, "Se borra directorio /directorio2/directorio21/directorio211/directorio2111");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->Rmdir("/directorio2"), OK, "Se borra directorio /directorio2");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Rmdir");

	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------------- Fin de pruebas OK Eliminar Directorio --------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasOKCopydir(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------ Pruebas para Copiar Directorio ------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
	this->mImpresion.iniciarSeccion("PRUEBAS CopyDir");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(6);
	this->FormarRedBasica(interfaz);

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->CopyDir("/directorio1/directorio11", "/directorio3"), OK, "Se copia /directorio1/directorio11 en /directorio3");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->CopyDir("/directorio2/directorio21/directorio211", "/directorio3/directorio4"), OK, "Se copia /directorio2/directorio21/directorio211 en /directorio3/directorio4");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de /directorio");

	ver2(interfaz->CopyDir("/directorio1/directorio12", "/directorio3/directorio5"), OK, "Se copia directorio /directorio1/directorio12 a /directorio3/directorio5");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS CopyDir");

	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------- Fin de pruebas OK Copiar Directorio ---------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

}

void PruebasEjemploDeUso::PruebasOKDelete(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------ Pruebas para Eliminar archivo ------------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
	this->mImpresion.iniciarSeccion("PRUEBAS Delete");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(6);
	this->FormarRedBasica(interfaz);

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->Delete("/directorio1/directorio11/archivo11.txt"), OK, "Se borra archivo /directorio1/directorio11/archivo11.txt");

	ver2(interfaz->Delete("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt"), OK, "Se borra archivo /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt");

	ver2(interfaz->Delete("/directorio2/directorio21/directorio211/archivo212.ppt"), OK, "Se borra archivo /directorio2/directorio21/directorio211/archivo212.ppt");

	ver2(interfaz->Dir("/", ""),OK,"Se muestra contenido de todo el filesystem");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Delete");

	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------- Fin de pruebas OK Eliminar Archivo ---------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasOKAttrib(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"----------------- Pruebas para Modificar parametros ----------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Attrib");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(6);
	this->FormarRedBasica(interfaz);

	ver2(interfaz->Dir("/", "-H"),OK,"Se muestra contenido de todo el filesystem");

	ver2(interfaz->Attrib("/directorio1/directorio11/archivo11.txt", "+H"), OK, "Se oculta archivo /directorio1/directorio11/archivo11.txt");

	ver2(interfaz->Attrib("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt", "+H"), OK, "Se oculta archivo /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt");

	ver2(interfaz->Attrib("/directorio2/directorio21/directorio211/archivo212.ppt", "+H"), OK, "Se oculta archivo /directorio2/directorio21/directorio211/archivo212.ppt");

	ver2(interfaz->Dir("/", "-H"),OK,"Se muestra contenido de todo el filesystem, incluyendo archivos ocultos");

	ver2(interfaz->Attrib("/directorio2/directorio21/directorio211/archivo212.ppt", "-H"), OK, "Se vuelve visible archivo /directorio2/directorio21/directorio211/archivo212.ppt");

	ver2(interfaz->Dir("/", "-H"),OK,"Se muestra contenido de todo el filesystem, incluyendo archivos ocultos");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Attrib");
	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------- Fin de pruebas OK Modificar Parametros -------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

}

void PruebasEjemploDeUso::PruebasOKDeleteText(){

	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"----------------- Pruebas para Eliminar texto ----------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
	this->mImpresion.iniciarSeccion("PRUEBAS DeleteText");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(6);
	this->FormarRedBasica(interfaz);

	ver2(interfaz->Type("/archivo1.txt"),OK,"Se muestra /archivo1.txt");

	ver2(interfaz->DeleteText("/archivo1.txt",1,3,10), OK, "Se borran 10 caracteres, de la linea 1, posicion 3 de /archivo1.txt");

	ver2(interfaz->Type("/archivo1.txt"),OK,"Se muestra /archivo1.txt");

	ver2(interfaz->DeleteText("/archivo1.txt",2,1,100), OK, "Se borran 100 caracteres, de la linea 2, posicion 1 de /archivo1.txt");

	ver2(interfaz->Type("/archivo1.txt"),OK,"Se muestra /archivo1.txt");

	ver2(interfaz->DeleteText("/archivo1.txt",3,10,60), OK, "Se borran 60 caracteres, de la linea 3, posicion 10 de /archivo1.txt");

	ver2(interfaz->Type("/archivo1.txt"),OK,"Se muestra /archivo1.txt");

	ver2(interfaz->DeleteText("/archivo1.txt",3,1,60), OK, "Se borran 60 caracteres, de la linea 3, posicion 1 de /archivo1.txt");

	ver2(interfaz->Type("/archivo1.txt"),OK,"Se muestra /archivo1.txt");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS DeleteText");

	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"----------------- Fin de pruebas OK Eliminar Texto -----------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::FormarRedBasica(InterfazDelSistema* interfaz){

	//se crea directorios
	interfaz->Mkdir("/directorio1"),OK,"Se crea el directorio 'Directorio1'.";
	interfaz->Mkdir("/directorio2"),OK,"Se crea el directorio 'Directorio2'.";
	interfaz->Mkdir("/directorio1/directorio11"),OK,"Se crea el directorio 'Directorio11', dentro de 'Directorio1'.";
	interfaz->Mkdir("/directorio1/directorio12"),OK,"Se crea el directorio 'Directorio12', dentro de 'Directorio1'.";
	interfaz->Mkdir("/directorio2/directorio21"),OK,"Se crea el directorio 'Directorio21', dentro de 'Directorio2'.";
	interfaz->Mkdir("/directorio2/directorio22"),OK,"Se crea el directorio 'Directorio22', dentro de 'Directorio2'.";
	interfaz->Mkdir("/directorio2/directorio21/directorio211"),OK,"Se crea el directorio 'Directorio211', dentro de 'Directorio21'.";
	interfaz->Mkdir("/directorio2/directorio21/directorio211/directorio2111"),OK,"Se crea el directorio 'Directorio2111', dentro de 'Directorio211'.";
	
	//se crean archivos
	interfaz->CreateFile("/archivo1.txt"),OK,"Se crea archivo1.txt en /.";
	interfaz->CreateFile("/directorio1/directorio11/archivo11.txt"),OK,"Se crea archivo11.txt en /directorio1/directorio11.";
	interfaz->CreateFile("/directorio1/directorio11/archivo12.txt"),OK,"Se crea archivo12.txt en /directorio1/directorio11.";
	interfaz->CreateFile("/directorio1/directorio11/archivo13.txt"),OK,"Se crea archivo13.txt en /directorio1/directorio11.";
	interfaz->CreateFile("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt"),OK,"Se crea archivo13.txt en /directorio2/directorio21/directorio211/directorio2111.";
	interfaz->CreateFile("/directorio2/directorio21/directorio211/archivo211.h"),OK,"Se crea archivo211.h en /directorio2/directorio21/directorio211.";
	interfaz->CreateFile("/directorio2/directorio21/directorio211/archivo212.ppt"),OK,"Se crea archivo212.ppt en /directorio2/directorio21/directorio211.";
	interfaz->CreateFile("/directorio2/directorio22/archivo22.txt"),OK,"Se crea archivo22.txt en /directorio2/directorio22.";
	interfaz->CreateFile("/directorio2/directorio22/Archivo22.txt"),OK,"Se crea Archivo22.txt en /directorio2/directorio22.";
	interfaz->CreateFile("/directorio2/directorio22/Archivo23.txt"),OK,"Se crea Archivo23.txt en /directorio2/directorio22.";

	//se introduc texto en archivos
	 interfaz->InsertText("/archivo1.txt", 1,1, "An error saepe."),OK,"Se inserta texto en archivo1.txt, linea 1, posicion 1.";
	 interfaz->InsertText("/archivo1.txt", 1,30, "An error saepe."),OK,"Se inserta texto en archivo1.txt, linea 1 posicion 30";
	 interfaz->InsertText("/archivo1.txt", 4,1, "Vis omnis legere"),OK,"Se inserta texto en archivo1.txt, linea 4, posicion 1";
	 interfaz->InsertText("/archivo1.txt", 4,1, "Omnesque philosophia eum an, ius tale."),OK,"Se inserta texto en archivo1.txt, en linea 4, posicion 1";
	 interfaz->InsertText("/directorio1/directorio11/archivo11.txt", 1,1, "Ius invidunt convenire at, has in atqui probatus deserunt."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 1, posicion 1";
	 interfaz->InsertText("/directorio1/directorio11/archivo11.txt", 1,1, "Eos nibh regione."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 1, posicion 1";
	 interfaz->InsertText("/directorio1/directorio11/archivo11.txt", 10,1, "Sed fabulas laoreet appellantur."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 10, posicion 1";
	 interfaz->InsertText("/directorio1/directorio11/archivo11.txt", 4,1, "Mel et illum sententiae, vix inani."),OK,"Se inserta texto en /directorio1/directorio11/archivo11.txt, en linea 4, posicion 1";
	 interfaz->InsertText("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt",1,1, "Usu rebum virtute."),OK,"Se inserta texto en /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt, en linea 1, posicion 1";
	 interfaz->InsertText("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt",2,1, "Eam habeo."),OK,"Se inserta texto en /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt, en linea 2, posicion 1";
	 interfaz->InsertText("/directorio2/directorio21/directorio211/directorio2111/archivo2111.txt",3,1, "His no putant vivendo."),OK,"Se inserta texto en /directorio2/directorio21/directorio211/directorio2111/archivo2111.txt, en linea 3, posicion 1";

}

void PruebasEjemploDeUso::PruebasErrorCrearDirectorio(){

	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------ PruebasERROR para Crear Directorio ---------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Error Mkdir");

	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);
	interfaz->Mkdir("/directorio1");

	ver2(interfaz->Mkdir("directorio"), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->Mkdir("/directorio2/directorio5"), ERROR, "No se encuentra la ruta.");
	ver2(interfaz->Mkdir("/directorio1"),ERROR,"Ya Existe un subdirectorio con el mismo nombre en esa ruta.");
	ver2(interfaz->Mkdir("/"),ERROR,"No se puede volver a crear el directorio raiz.");
	
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Error Mkdir");

	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------ Fin de pruebasERROR para Crear Directorio --------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasErrorEliminarDirectorio(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------------- PruebasERROR para Eliminar Directorio --------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Error Rmdir");

	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);
	interfaz->Mkdir("/directorio1");

	ver2(interfaz->Rmdir("directorio"), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->Rmdir("/directorio2/directorio5"), ERROR, "No se encuentra la ruta.");
	
	
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Error Rmdir");

	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------- Fin de pruebasERROR para Eliminar Directorio --------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasErrorCopiarDirectorio(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------- PruebasERROR para Copiar Directorio ---------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Error CopyDir");

	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);

	interfaz->Mkdir("/directorio1");
	interfaz->Mkdir("/directorio2");
	interfaz->Mkdir("/directorio1/directorio1");

	ver2(interfaz->CopyDir("/directorio2","directorio"), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->CopyDir("directorio2","/directorio"), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->CopyDir("/directorio3","/directorio"), ERROR, "No se encuentra la ruta de origen.");
	ver2(interfaz->CopyDir("/directorio2","/directorio1/directorio1"), ERROR, "Ya existe la ruta de destino.");
	ver2(interfaz->CopyDir("/directorio1", "/directorio1/directorio1"), ERROR, "La ruta de destino no puede ser un subdirectorio de origen.");
	ver2(interfaz->CopyDir("/directorio1", "/dirdesconocido/aaa"), ERROR, "No se encuentra el padre de la ruta destino.");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Error CopyDir");

	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------- Fin de pruebasERROR para Copiar Directorio ---------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasErrorMostrarDirectorio(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------- PruebasERROR para Mostrar Directorio ---------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Error Dir");
	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);

	interfaz->Mkdir("/directorio1");
	interfaz->Mkdir("/directorio2");
	interfaz->Mkdir("/directorio1/directorio1");

	ver2(interfaz->Dir("directorio2",""), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->Dir("/directorio3",""), ERROR, "No se encuentra la ruta.");
	ver2(interfaz->Dir("/directorio2","hh"), ERROR, "Parametro desconocido");
	
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Error Dir");
	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------- Fin de pruebasERROR para Mostrar Directorio ---------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasErrorCrearArchivo(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------- PruebasERROR para Crear Archivo ---------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Error CreateFile");
	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);

	interfaz->Mkdir("/directorio1");
	interfaz->CreateFile("/directorio1/archivo1.txt");

	ver2(interfaz->CreateFile("directorio2"), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->CreateFile("/directorio3/archivo"), ERROR, "No se encuentra la ruta.");
	ver2(interfaz->CreateFile("/directorio1/archivo1.txt"), ERROR, "Ya existe un archivo con el mismo nombre en esa ruta.");
	
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Error CreateFile");
	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------- Fin de pruebasERROR para Crear Archivo ---------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasErrorEliminarArchivo(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------- PruebasERROR para Eliminar Archivo ---------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;

	this->mImpresion.iniciarSeccion("PRUEBAS Error Delete");
	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);

	interfaz->Mkdir("/directorio1");

	ver2(interfaz->Delete("directorio2"), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->Delete("/directorio3/archivo"), ERROR, "No se encuentra la ruta.");
	ver2(interfaz->Delete("/directorio1/archivo1.txt"), ERROR, "No existe un archivo con ese nombre en esa ruta.");
	
	delete interfaz;
	this->mImpresion.cerrarSeccion("PRUEBAS Error Delete");
	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------- Fin de pruebasERROR para Eliminar Archivo ---------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void  PruebasEjemploDeUso::PruebasErrorModificarParametros(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"---------------- PruebasERROR para Modificar Parametros ---------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
	this->mImpresion.iniciarSeccion("PRUEBAS Error Attrib");
	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);

	interfaz->Mkdir("/directorio1");

	ver2(interfaz->Attrib("directorio2", "+H"), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->Attrib("/directorio3/archivo", "+H"), ERROR, "No se encuentra la ruta.");
	ver2(interfaz->Attrib("/directorio1/archivo1.txt", "+H"), ERROR, "No existe un archivo con ese nombre en esa ruta.");
	interfaz->CreateFile("/directorio1/archivo1.txt");
	ver2(interfaz->Attrib("/directorio1/archivo1.txt", "ll"), ERROR, "Parametro desconocido.");
	
	delete interfaz;
	this->mImpresion.cerrarSeccion("PRUEBAS Error Attrib");
	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------- Fin de pruebasERROR para Modificar Parametros ---------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasErrorInsertarTexto(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------ PruebasERROR para Insertar Texto ----------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
	this->mImpresion.iniciarSeccion("PRUEBAS Error DeleteText");
	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);

	interfaz->Mkdir("/directorio1");
	interfaz->CreateFile("/directorio1/archivo1.txt");

	ver2(interfaz->DeleteText("directorio1/archivo1.txt",1,1,1 ), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->DeleteText("/directorio2/archivo1.txt",1,1,1), ERROR, "No se encuentra la ruta.");
	ver2(interfaz->DeleteText("/directorio1/archivo2.txt",1,1,1), ERROR, "No existe un archivo con ese nombre en esa ruta.");
	ver2(interfaz->DeleteText("/directorio1/archivo1.txt",0,1,1), ERROR, "La linea 0 no es valida.");
	ver2(interfaz->DeleteText("/directorio1/archivo1.txt",1,0,1), ERROR, "La posicion 0 no es valida.");
		
	delete interfaz;
	this->mImpresion.cerrarSeccion("PRUEBAS Error DeleteText");
	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------- Fin de pruebasERROR para Insertar Texto ---------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasErrorEliminarTexto(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------ PruebasERROR para Insertar Texto ----------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
	this->mImpresion.iniciarSeccion("PRUEBAS Error InsertText");
	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);

	interfaz->Mkdir("/directorio1");
	interfaz->CreateFile("/directorio1/archivo1.txt");

	ver2(interfaz->InsertText("directorio1/archivo1.txt",1,1, "Mel sanctus delenit ea."  ), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->InsertText("/directorio2/archivo1.txt",1,1, "Mel sanctus delenit ea."  ), ERROR, "No se encuentra la ruta.");
	ver2(interfaz->InsertText("/directorio1/archivo2.txt",1,1, "Mel sanctus delenit ea."), ERROR, "No existe un archivo con ese nombre en esa ruta.");
	ver2(interfaz->InsertText("/directorio1/archivo1.txt",0,1, "Mel sanctus delenit ea."), ERROR, "La linea 0 no es valida.");
	ver2(interfaz->InsertText("/directorio1/archivo1.txt",1,0, "Mel sanctus delenit ea."), ERROR, "La posicion 0 no es valida.");
		
	delete interfaz;
	this->mImpresion.cerrarSeccion("PRUEBAS Error InsertText");
	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------- Fin de pruebasERROR para Insertar Texto ---------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

void PruebasEjemploDeUso::PruebasErrorMostrarArchivo(){
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"------------------ PruebasERROR para Mostrar Archivo ----------------"<<endl;
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
	this->mImpresion.iniciarSeccion("PRUEBAS Error Type");
	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);

	interfaz->Mkdir("/directorio1");
	interfaz->CreateFile("/directorio1/archivo1.txt");

	ver2(interfaz->Type("directorio1/archivo1.txt"), ERROR, "La ruta no comienza con /.");
	ver2(interfaz->Type("/directorio2/archivo1.txt"), ERROR, "No se encuentra la ruta.");
	ver2(interfaz->Type("/directorio1/archivo2.txt"), ERROR, "No existe un archivo con ese nombre en esa ruta.");
		
	delete interfaz;
	this->mImpresion.cerrarSeccion("PRUEBAS Error Type");
	//cout<<"\n\n";
	//cout<<"---------------------------------------------------------------------"<<endl;
	//cout<<"--------- Fin de pruebasERROR para Mostrar Archivo ---------------\n";
	//cout<<"---------------------------------------------------------------------"<<endl<<endl;
}
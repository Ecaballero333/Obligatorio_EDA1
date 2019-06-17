#ifndef TIPO_OPERACION_H
#define TIPO_OPERACION_H

enum _operacion
{
	MKDIR, RMDIR, DIR, COPYDIR, DELETE, CREATEFILE, INSERTTEXT, TYPE, 
	ATTRIB, DELETETEXT, UNDELETE
};
typedef enum _operacion TipoOperacion;

#endif

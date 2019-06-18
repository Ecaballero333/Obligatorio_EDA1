#ifndef CODIGO_ERROR_H
#define CODIGO_ERROR_H

enum _error
{
	NO_HAY_ERROR,
	ERROR_RUTA_COMIENZA_MAL,
	ERROR_NO_SE_ENCUENTRA_RUTA,
	ERROR_YA_EXISTE_SUBDIRECTORIO, 
	ERROR_YA_EXISTE_ARCHIVO,
	ERROR_NO_SE_PUEDE_CREAR_DIR_RAIZ,
	ERROR_DIRECTORIO_NOMBRE_INCORRECTO,
	ERROR_PARAMETRO_DESCONOCIDO,
	ERROR_NO_SE_ENCUENTRA_RUTA_ORIGEN,
	ERROR_YA_EXISTE_RUTA_DESTINO,
	ERROR_NO_SE_ENCUENTRA_PADRE_RUTA_DESTINO,
	ERROR_RUTA_DESTINO_ES_SUBDIR_DE_ORIGEN,
	ERROR_NO_EXISTE_ARCHIVO_NOMBRE_EN_RUTA,
	ERROR_LINEA_CERO_NO_VALIDA,
	ERROR_POSICION_CERO_NO_VALIDA,
	ERROR_LINEA_NO_EXISTE
};
typedef enum _error TipoError;

#endif
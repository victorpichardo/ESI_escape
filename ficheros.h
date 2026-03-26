#ifndef FICHEROS_H
#define FICHEROS_H

#include "salas.h"

// Carga de datos desde archivos de texto
int cargar_salas(Sala vector_salas[]);
int cargar_conexiones(Conexion vector_conexiones[]);
int cargar_objetos(Objeto vector_objetos[]);

#endif // FICHEROS_H

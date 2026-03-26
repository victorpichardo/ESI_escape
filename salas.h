#ifndef SALAS_H
#define SALAS_H

#define MAX_SALAS 100
#define MAX_CONEXIONES 100
#define MAX_OBJETOS 100

typedef struct {
    int id;
    char nombre[50];
    char tipo[20];
    char descripcion[512];
} Sala;

typedef struct {
    char id_conexion[10];
    int id_origen;
    char nombre_origen[50];
    int id_destino;
    char nombre_destino[50];
    char estado[20];
    char objeto_necesario[50];
} Conexion;

typedef struct {
    char id_obj[10];
    char nombre[50];
    char descripcion[100];
    char localizacion[20];
} Objeto;

int cargar_salas(Sala vector_salas[]);
int cargar_conexiones(Conexion vector_conexiones[]);
int cargar_objetos(Objeto vector_objetos[]);

void describir_sala(Sala vector_salas[], int total_salas, int id_buscado);
void examinar_sala(int id_sala, Objeto vector_objetos[], int total_objetos, Conexion vector_conexiones[], int total_conexiones);
void entrar_sala(int *sala_actual, int sala_destino, Conexion vector_conexiones[], int total_conexiones);

// Nueva función para listar destinos
int mostrar_destinos_posibles(int id_sala_actual, Conexion vector_conexiones[], int total_conexiones);

#endif

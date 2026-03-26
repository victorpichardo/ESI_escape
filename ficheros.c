#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salas.h"

int cargar_salas(Sala vector_salas[]) {
    FILE *archivo = fopen("Salas.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo Salas.txt.\n");
        return 0; 
    }
    
    char linea[600]; 
    int contador = 0;
    
    while (fgets(linea, sizeof(linea), archivo) != NULL && contador < MAX_SALAS) {
        char *token_id = strtok(linea, "-");                  
        char *token_nombre = strtok(NULL, "-");    
        char *token_tipo = strtok(NULL, "-");     
        char *token_desc = strtok(NULL, "\n");     
        
        if (token_id != NULL && token_nombre != NULL && token_tipo != NULL && token_desc != NULL) {
            vector_salas[contador].id = atoi(token_id);
            strncpy(vector_salas[contador].nombre, token_nombre, 49);
            strncpy(vector_salas[contador].tipo, token_tipo, 19);
            strncpy(vector_salas[contador].descripcion, token_desc, 511);
            contador++;
        }
    }
    
    fclose(archivo); 
    return contador;
}

int cargar_conexiones(Conexion vector_conexiones[]) {
    FILE *archivo = fopen("Conexiones.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo Conexiones.txt.\n");
        return 0;
    }
    
    char linea[600];
    int contador = 0;
    
    while (fgets(linea, sizeof(linea), archivo) != NULL && contador < MAX_CONEXIONES) {
        char *t_id = strtok(linea, "-");
        char *t_id_origen = strtok(NULL, "-");
        char *t_nom_origen = strtok(NULL, "-");
        char *t_id_dest = strtok(NULL, "-");
        char *t_nom_dest = strtok(NULL, "-");
        char *t_estado = strtok(NULL, "-");
        char *t_obj = strtok(NULL, "\n");
        
        if (t_id && t_id_origen && t_nom_origen && t_id_dest && t_nom_dest && t_estado && t_obj) {
            strncpy(vector_conexiones[contador].id_conexion, t_id, 9);
            vector_conexiones[contador].id_origen = atoi(t_id_origen);
            strncpy(vector_conexiones[contador].nombre_origen, t_nom_origen, 49);
            vector_conexiones[contador].id_destino = atoi(t_id_dest);
            strncpy(vector_conexiones[contador].nombre_destino, t_nom_dest, 49);
            strncpy(vector_conexiones[contador].estado, t_estado, 19);
            strncpy(vector_conexiones[contador].objeto_necesario, t_obj, 49);
            contador++;
        }
    }
    
    fclose(archivo);
    return contador;
}

int cargar_objetos(Objeto vector_objetos[]) {
    FILE *archivo = fopen("Objetos.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo Objetos.txt.\n");
        return 0;
    }
    
    char linea[600];
    int contador = 0;
    
    while (fgets(linea, sizeof(linea), archivo) != NULL && contador < MAX_OBJETOS) {
        char *t_id = strtok(linea, "-");
        char *t_nom = strtok(NULL, "-");
        char *t_desc = strtok(NULL, "-");
        char *t_loc = strtok(NULL, "\n");
        
        if (t_id && t_nom && t_desc && t_loc) {
            strncpy(vector_objetos[contador].id_obj, t_id, 9);
            strncpy(vector_objetos[contador].nombre, t_nom, 49);
            strncpy(vector_objetos[contador].descripcion, t_desc, 99);
            strncpy(vector_objetos[contador].localizacion, t_loc, 19);
            contador++;
        }
    }
    
    fclose(archivo);
    return contador;
}
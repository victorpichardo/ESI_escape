#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salas.h"

void describir_sala(Sala vector_salas[], int total_salas, int id_buscado) {
    for (int i = 0; i < total_salas; i++) {
        if (vector_salas[i].id == id_buscado) {
            printf("[%s] %s: %s\n", vector_salas[i].tipo, vector_salas[i].nombre, vector_salas[i].descripcion);
            return;
        }
    }
    printf("Error: La sala con identificador %d no existe.\n", id_buscado);
}

void examinar_sala(int id_sala, Objeto vector_objetos[], int total_objetos, Conexion vector_conexiones[], int total_conexiones) {
    int objetos_encontrados = 0;
    int salidas_encontradas = 0;

    printf("Objetos en la sala:\n");
    for (int i = 0; i < total_objetos; i++) {
        if (atoi(vector_objetos[i].localizacion) == id_sala) {
            printf("  - %s: %s\n", vector_objetos[i].nombre, vector_objetos[i].descripcion);
            objetos_encontrados++;
        }
    }
    if (objetos_encontrados == 0) printf("  - No hay objetos visibles.\n");

    printf("Salidas disponibles:\n");
    for (int i = 0; i < total_conexiones; i++) {
        if (vector_conexiones[i].id_origen == id_sala) {
            printf("  - Hacia %s (Estado: %s)\n", vector_conexiones[i].nombre_destino, vector_conexiones[i].estado);
            salidas_encontradas++;
        }
    }
    if (salidas_encontradas == 0) printf("  - No hay salidas visibles.\n");
}

void entrar_sala(int *sala_actual, int sala_destino, Conexion vector_conexiones[], int total_conexiones) {
    for (int i = 0; i < total_conexiones; i++) {
        if (vector_conexiones[i].id_origen == *sala_actual && vector_conexiones[i].id_destino == sala_destino) {
            if (strcmp(vector_conexiones[i].estado, "Activa") == 0) {
                *sala_actual = sala_destino;
                printf("Has entrado en la sala: %s\n", vector_conexiones[i].nombre_destino);
            } else {
                printf("La conexion esta bloqueada. Condicion: %s\n", vector_conexiones[i].objeto_necesario);
            }
            return;
        }
    }
}

int mostrar_destinos_posibles(int id_sala_actual, Conexion vector_conexiones[], int total_conexiones) {
    int contador = 0;
    int destinos[MAX_CONEXIONES];

    printf("\n--- SALIDAS DISPONIBLES ---\n");
    for (int i = 0; i < total_conexiones; i++) {
        if (vector_conexiones[i].id_origen == id_sala_actual) {
            contador++;
            printf("%d. Ir a %s [%s]\n", contador, vector_conexiones[i].nombre_destino, vector_conexiones[i].estado);
            destinos[contador - 1] = vector_conexiones[i].id_destino;
        }
    }

    if (contador == 0) {
        printf("No hay salidas desde esta sala.\n");
        return 0;
    }

    int seleccion;
    printf("Selecciona una opcion (1-%d) o 0 para cancelar: ", contador);
    scanf("%d", &seleccion);
    while(getchar() != '\n');

    if (seleccion > 0 && seleccion <= contador) {
        // Buscamos el ID real del destino seleccionado
        int actual = 0;
        for (int i = 0; i < total_conexiones; i++) {
            if (vector_conexiones[i].id_origen == id_sala_actual) {
                actual++;
                if (actual == seleccion) return vector_conexiones[i].id_destino;
            }
        }
    }
    return -1; // No se seleccionó nada válido
}

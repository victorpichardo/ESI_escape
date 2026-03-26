#ifndef USUARIOS_H
#define USUARIOS_H

#include "salas.h"

#define MAX_JUGADORES 50

typedef struct {
    char id[3];
    char nombre_completo[21];
    char login[11];
    char password[9];
    char inventario[100];
} Jugador;

int autenticar_jugador(Jugador *jugador_actual);
void crear_usuario();

#endif

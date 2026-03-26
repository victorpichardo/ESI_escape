#include <stdio.h>
#include <conio.h>
#include "menu.h"
#include "salas.h"
#include "ficheros.h"
#include "usuarios.h"

int main() {
    Jugador jugador_sesion;
    int sesion_iniciada = 0;
    int programa_ejecutando = 1;

    while (!sesion_iniciada) {
        printf("\n1. Iniciar Sesion\n2. Registrarse\n3. Salir\nSeleccione: ");
        int pre = getch() - '0';
        if (pre == 1) {
            if (autenticar_jugador(&jugador_sesion)) sesion_iniciada = 1;
        } else if (pre == 2) {
            crear_usuario();
        } else if (pre == 3) return 0;
    }

    Sala mis_salas[MAX_SALAS];
    Conexion mis_conexiones[MAX_CONEXIONES];
    Objeto mis_objetos[MAX_OBJETOS];

    int total_salas = cargar_salas(mis_salas);
    int total_conexiones = cargar_conexiones(mis_conexiones);
    int total_objetos = cargar_objetos(mis_objetos);

    int id_sala_actual = 1;

    if (total_salas == 0) {
        printf("Error: No se pudieron cargar las salas.\n");
        return 1;
    }

    while (programa_ejecutando) {
        int opP = mostrarMenuPrincipal();
        if (opP == 3) {
            printf("\nSaliendo...\n");
            programa_ejecutando = 0;
        } else {
            int enPartida = 1;
            while (enPartida) {
                int opJ = mostrarMenuPartida(mis_salas[id_sala_actual - 1].nombre);

                if (opJ == 10) {
                    enPartida = 0;
                } else if (opJ == 1) {
                    describir_sala(mis_salas, total_salas, id_sala_actual);
                } else if (opJ == 2) {
                    examinar_sala(id_sala_actual, mis_objetos, total_objetos, mis_conexiones, total_conexiones);
                } else if (opJ == 3) {
                    // NUEVA LÓGICA: Mostrar lista y elegir
                    int destino = mostrar_destinos_posibles(id_sala_actual, mis_conexiones, total_conexiones);
                    if (destino != -1) {
                        entrar_sala(&id_sala_actual, destino, mis_conexiones, total_conexiones);
                    }
                } else {
                    printf("\n[Accion %d ejecutada]\n", opJ);
                }
            }
        }
    }
    return 0;
}

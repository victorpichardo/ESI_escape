#include <stdio.h>
#include <conio.h>
#include "menu.h"
#include "salas.h"

int mostrarMenuPrincipal() {
    int tecla;
    printf("\n---- MENU PRINCIPAL ----\n");
    printf("1. New Game\n2. Load Game\n3. Salir\n");
    printf("Seleccione [1-3]: ");

    while (1) {
        tecla = getch(); // Captura instantanea
        if (tecla >= '1' && tecla <= '3') {
            printf("%c\n", tecla); // Mostramos la tecla pulsada
            return tecla - '0';    // Convertimos de char a int
        }
    }
}

int mostrarMenuPartida(char* nombreSala) {
    int tecla;
    printf("\nSala: %s\n", nombreSala);
    printf("1. Describir sala    2. Examinar         3. Entrar\n");
    printf("4. Coger objeto      5. Soltar objeto    6. Inventario\n");
    printf("7. Usar objeto       8. Puzle / Codigo   9. Guardar\n");
    printf("0. Volver\n");
    printf("Seleccione accion: ");

    while (1) {
        tecla = getch();
        if (tecla >= '0' && tecla <= '9') {
            printf("%c\n", tecla);
            int opcion = tecla - '0';
            // Si pulsa 0, devolvemos 10 para mantener la lógica original del main
            return (opcion == 0) ? 10 : opcion;
        }
    }
}

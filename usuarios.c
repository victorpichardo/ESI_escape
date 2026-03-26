#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "usuarios.h"

// Función interna para limpiar el rastro del Enter tras usar scanf/fgets
void limpiar_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void crear_usuario() {
    Jugador nuevo;
    FILE *f = fopen("Jugadores.txt", "a+");
    if (!f) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("\n--- REGISTRO DE NUEVO USUARIO ---\n");

    printf("ID (2 digitos): ");
    scanf("%2s", nuevo.id);
    limpiar_entrada();

    printf("Nombre Completo (max 20): ");
    fgets(nuevo.nombre_completo, 21, stdin);
    nuevo.nombre_completo[strcspn(nuevo.nombre_completo, "\n")] = 0; // Quitar el salto de línea

    printf("Username (max 10): ");
    scanf("%10s", nuevo.login);
    limpiar_entrada();

    printf("Password (max 8): ");
    scanf("%8s", nuevo.password);
    limpiar_entrada();

    // Guardar en el formato del trabajo
    fprintf(f, "%s-%s-%s-%s-0\n", nuevo.id, nuevo.nombre_completo, nuevo.login, nuevo.password);
    fclose(f);

    printf("\n[OK] Usuario registrado. Pulsa una tecla para continuar...");
    getch();
}

int autenticar_jugador(Jugador *jugador_actual) {
    char user_in[11], pass_in[9];
    FILE *f = fopen("Jugadores.txt", "r");

    if (!f) {
        printf("\nError: No existe el archivo de jugadores.\n");
        return 0;
    }

    printf("\n--- INICIO DE SESION ---\n");
    printf("Usuario: ");
    scanf("%10s", user_in);
    limpiar_entrada();

    printf("Contrasena: ");
    scanf("%8s", pass_in);
    limpiar_entrada();

    char linea[250];
    while (fgets(linea, sizeof(linea), f)) {
        // Parseo según los campos del trabajo: ID-Nombre-User-Pass-Inv
        char *id = strtok(linea, "-");
        char *nom = strtok(NULL, "-");
        char *log = strtok(NULL, "-");
        char *pas = strtok(NULL, "-");
        char *inv = strtok(NULL, "\n");

        if (log && pas && strcmp(user_in, log) == 0 && strcmp(pass_in, pas) == 0) {
            strcpy(jugador_actual->id, id);
            strcpy(jugador_actual->nombre_completo, nom);
            strcpy(jugador_actual->login, log);
            if (inv) strcpy(jugador_actual->inventario, inv);

            fclose(f);
            return 1;
        }
    }

    fclose(f);
    printf("\n[Error] Usuario o contrasena incorrectos. Pulsa una tecla...");
    getch();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definir las estructuras del juego
typedef struct {
    char nombre[50];
    int salud;
    int ataque;
    int defensa;
} Personaje;

typedef struct {
    char nombre[50];
    int daño;
    int tipo; // 1 = arma, 2 = poción
} Objeto;

typedef struct {
    char nombre[50];
    char descripcion[200];
    int enemigo_salud;
    int enemigo_ataque;
    Objeto objeto;
} Habitacion;

// Función de combate entre el jugador y el enemigo
void combate(Personaje *jugador, Habitacion *habitacion) {
    printf("\n¡Un enemigo aparece! Es un monstruo con %d HP y hace %d de daño.\n", habitacion->enemigo_salud, habitacion->enemigo_ataque);

    while (habitacion->enemigo_salud > 0 && jugador->salud > 0) {
        printf("\nTus HP: %d, Enemigo HP: %d\n", jugador->salud, habitacion->enemigo_salud);
        printf("1. Atacar\n");
        printf("2. Defender\n");
        printf("3. Usar objeto\n");
        
        int opcion;
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("¡Atacas al enemigo! Le haces %d de daño.\n", jugador->ataque);
            habitacion->enemigo_salud -= jugador->ataque;
            if (habitacion->enemigo_salud <= 0) {
                printf("¡Has derrotado al enemigo!\n");
                return;
            }
        } else if (opcion == 2) {
            printf("Te defiendes. Reduces el daño recibido a la mitad.\n");
            jugador->salud -= (habitacion->enemigo_ataque / 2);
        } else if (opcion == 3) {
            if (habitacion->objeto.tipo == 2) {
                printf("Usas una poción y recuperas 20 HP.\n");
                jugador->salud += 20;
            } else if (habitacion->objeto.tipo == 1) {
                printf("Equipas un %s, aumentando tu ataque en 10.\n", habitacion->objeto.nombre);
                jugador->ataque += 10;
            }
        } else {
            printf("Opción no válida. Intenta de nuevo.\n");
        }

        // El enemigo ataca
        if (habitacion->enemigo_salud > 0) {
            printf("El enemigo te ataca, causando %d de daño.\n", habitacion->enemigo_ataque);
            jugador->salud -= habitacion->enemigo_ataque;
        }

        if (jugador->salud <= 0) {
            printf("¡Has sido derrotado!\n");
            return;
        }
    }
}

// Función para explorar las habitaciones
void explorar(Habitacion *habitacion, Personaje *jugador) {
    printf("\nEstás en la habitación: %s\n", habitacion->nombre);
    printf("%s\n", habitacion->descripcion);

    // Opción de combate
    if (habitacion->enemigo_salud > 0) {
        combate(jugador, habitacion);
    } else {
        printf("La habitación está vacía. Has ganado un %s.\n", habitacion->objeto.nombre);
        printf("¡Recibes un objeto: %s!\n", habitacion->objeto.nombre);
        // El jugador recibe el objeto
    }
}

int main() {
    srand(time(0));

    // Crear personaje
    Personaje jugador = {"Héroe", 100, 20, 5};

    // Crear objetos
    Objeto espada = {"Espada Mágica", 0, 1}; // Tipo 1 = Arma
    Objeto pocion = {"Poción Curativa", 0, 2}; // Tipo 2 = Poción

    // Crear enemigos
    Habitacion habitacion1 = {"Sala Oscura", "Te encuentras en una sala oscura, un monstruo con garras afiladas aparece.", 50, 10, espada};
    Habitacion habitacion2 = {"Bosque Misterioso", "El bosque está tranquilo, pero te encuentras con una criatura misteriosa.", 30, 5, pocion};

    // Flujo del juego
    explorar(&habitacion1, &jugador);
    if (jugador.salud > 0) {
        explorar(&habitacion2, &jugador);
    }

    // Fin del juego
    if (jugador.salud > 0) {
        printf("\n¡Felicidades! Has sobrevivido a las aventuras.\n");
    }

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define WIDTH 10
#define HEIGHT 10

// Mapa del laberinto ('#' paredes, ' ' camino, 'P' jugador, 'E' salida)
char map[HEIGHT][WIDTH + 1] = {
    "##########",
    "#P     # #",
    "# ### #  #",
    "# #   ## #",
    "# # #### #",
    "# #      #",
    "# ###### #",
    "#      # #",
    "# #### #E#",
    "##########"
};

int playerX = 1, playerY = 1;

void drawMap() {
    system("clear");  // Compatible con Linux/Mac
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", map[i]);
    }
}

char getInput() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void movePlayer(int dx, int dy) {
    int newX = playerX + dx;
    int newY = playerY + dy;
    
    if (map[newY][newX] == ' ' || map[newY][newX] == 'E') {
        // Mover jugador
        map[playerY][playerX] = ' ';
        playerX = newX;
        playerY = newY;
        map[playerY][playerX] = 'P';

        // Verificar si llegó a la salida
        if (map[newY][newX] == 'E') {
            drawMap();
            printf("\n\n¡Has llegado a la salida!\n");
            exit(0);
        }
    }
}

int main() {
    char input;
    while (1) {
        drawMap();
        input = getInput();  // Lee una tecla sin presionar Enter

        switch (input) {
            case 'w': movePlayer(0, -1); break;  // Arriba
            case 's': movePlayer(0, 1);  break;  // Abajo
            case 'a': movePlayer(-1, 0); break;  // Izquierda
            case 'd': movePlayer(1, 0);  break;  // Derecha
            case 'q': exit(0);  // Salir del juego
        }
    }
    return 0;
}

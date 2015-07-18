#include <stdbool.h>
#include <windows.h>
#include <time.h>

#define X 10
#define Y 10

// Variables
int tablero[X][Y];
bool creado = false;
bool subTablero[X][Y];
bool lop = true;
int contador = 0;

// Funciones
void iniciaTablero();
void actualizaTablero();
void menuJuego();
void loop();

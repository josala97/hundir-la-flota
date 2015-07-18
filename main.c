#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    menuJuego();
    actualizaTablero();
    for(;;){
        while(lop){
            loop();
        }
        break;
    }
    printf("Fin del juego, ganaste, pulsa una tecla para volver al menu");
    fflush(stdin);
    getchar();
    menuJuego();
    return 0;
}


void iniciaTablero(){
    int x,y,a,b,ra,rb;
    ra = (rand() % 5);
    rb = (rand() % 2);
    for(y = 0; y < Y; y++){
        for(x = 0; x < X; x++){
            tablero[x][y] = 0;
        }
    }
    for(a = 0; a < Y; a++){
        for(b = 0; b < X; b++){
            subTablero[x][y] = false;
        }
    }
    if(rb == 0){
        int e,d;
        // Creando barco de una pieza
        e = ra; d = ra;
        subTablero[e][d] = true;
        ra = (rand() % 5);
        e = ra; d = ra;
        // creando barco de 2
        while(subTablero[e][d]){
            ra = (rand() % 5);
            e = ra; d = ra;
        }
        subTablero[e][d] = true;
        subTablero[e][d+1] = true;
        ra = (rand() % 5);
        e = ra; d = ra;
        // creando barco de 3
        while(subTablero[e][d]){
            ra = (rand() % 5);
            e = ra; d = ra;
        }
        subTablero[e][d] = true;
        subTablero[e][d+1] = true;
        subTablero[e][d+2] = true;
        ra = (rand() % 5);
        e = ra; d = ra;
        // creando barco de 4
        while(subTablero[e][d]){
            ra = (rand() % 5);
            e = ra; d = ra;
        }
        subTablero[e][d] = true;
        subTablero[e][d+1] = true;
        subTablero[e][d+2] = true;
        subTablero[e][d+3] = true;
        ra = (rand() % 5);
        e = ra; d = ra;
        // creando barco de 5
        while(subTablero[e][d]){
            ra = (rand() % 5);
            e = ra; d = ra;
        }
        subTablero[e][d] = true;
        subTablero[e][d+1] = true;
        subTablero[e][d+2] = true;
        subTablero[e][d+3] = true;
        subTablero[e][d+4] = true;
    }
    if(rb == 1){
        int e,d;
        // Creando barco de una pieza
        e = ra; d = ra;
        subTablero[e][d] = true;
        ra = (rand() % 5);
        e = ra; d = ra;
        // creando barco de 2
        while(subTablero[e][d]){
            ra = (rand() % 5);
            e = ra; d = ra;
        }
        subTablero[e][d] = true;
        subTablero[e+1][d] = true;
        ra = (rand() % 5);
        e = ra; d = ra;
        // creando barco de 3
        while(subTablero[e][d]){
            ra = (rand() % 5);
            e = ra; d = ra;
        }
        subTablero[e][d] = true;
        subTablero[e+1][d] = true;
        subTablero[e+2][d] = true;
        ra = (rand() % 5);
        e = ra; d = ra;
        // creando barco de 4
        while(subTablero[e][d]){
            ra = (rand() % 5);
            e = ra; d = ra;
        }
        subTablero[e][d] = true;
        subTablero[e+1][d] = true;
        subTablero[e+2][d] = true;
        subTablero[e+3][d] = true;
        ra = (rand() % 5);
        e = ra; d = ra;
        // creando barco de 5
        while(subTablero[e][d]){
            ra = (rand() % 5);
            e = ra; d = ra;
        }
        subTablero[e][d] = true;
        subTablero[e+1][d] = true;
        subTablero[e+2][d] = true;
        subTablero[e+3][d] = true;
        subTablero[e+4][d] = true;
    }
    creado = true;
}

void actualizaTablero(){
    int x,y;
    for(y = 0; y < Y; y++){
        for(x = 0; x < X; x++){
            if(x == 9){
                printf("%i\n", tablero[x][y]);
            } else printf("%i ", tablero[x][y]);
        }
    }
}

void menuJuego(){
    int flag;
    lop = true;
    printf("Bienvenido a hundir la flota: \n");
    printf("Elija una opcion: \n");
    printf("1. Asignar barcos \n");
    printf("2. Jugar \n");
    printf("3. Salir \n");
    scanf("%i", &flag);
    switch(flag){
        case 1:
            printf("Tablero creado. Pulse una tecla para volver al menu. \n");
            fflush(stdin);
            getchar();
            iniciaTablero();
            system("cls");
            menuJuego();
            break;
        case 2:
            if(creado){
                break;
            } else {
                printf("Necesario crear tablero\n");
                menuJuego();
                break;
            }
        case 3:
            exit(0);
        default:
            printf("Error, comando incorrecto, pulse una tecla para volver al menu");
            fflush(stdin);
            getchar();
            system("cls");
            menuJuego();
    }
}

void loop(){
    int x,y;
    if(contador == 15){
        lop = false;
        return;
    }
    printf("Indica una columna(Rango de 1 a 10)\n");
    fflush(stdin);
    scanf("%i", &x);
    x--;
    while(x < 0 || x > 9){
        printf("Valor incorrecto, Indica una fila(Rango de 1 a 10)\n");
        fflush(stdin);
        scanf("%i", &x);
        x--;
    }
    printf("Indica una fila(Rango de 1 a 10)\n");
    fflush(stdin);
    scanf("%i", &y);
    y--;
    while(y < 0 || y > 9){
        printf("Valor incorrecto, Indica una fila(Rango de 1 a 10)\n");
        fflush(stdin);
        scanf("%i", &y);
        y--;
    }

    if(tablero[x][y] == 0){
        if(subTablero[x][y]){
            subTablero[x][y] = false;
            tablero[x][y] = 2;
            contador++;
        } else tablero[x][y] = 1;
    }
    system("cls");
    actualizaTablero();
}

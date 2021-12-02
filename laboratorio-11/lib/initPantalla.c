#include "lib1122021.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
static struct termios old, current;

void initPantalla(int modo, char* rutaArchivo){
    int longitud = 0;
    clear();
    printf("╔════════════════════════════════════════════════════════════╗ ");
    printf("\n║                                                            ║");
    printf("\n╠════════════════════════════════════════════════════════════╣");
    for (int i = 0; i < 18; i++) {
        printf("\n║                                                            ║");
    };
    printf("\n╠════════════════════════════════════════════════════════════╣");
    for (int i = 0; i < 3; i++) {
        printf("\n║                                                            ║");
    };
    printf("\n╚════════════════════════════════════════════════════════════╝\n");
    gotoxy(3, 23);
    printf("Controles");
    switch(modo){
        case  0 : gotoxy(26, 1);
                  printf(" Agenda ");
                  gotoxy(3, 2);
                  printf("Archivo\t\tAyuda");
                  gotoxy(3, 24);
                  printf("\033[0;30;47mM:\033[0;0m Abrir Menú");
                  gotoxy(3, 25);
                  printf("\033[0;30;47mX:\033[0;0m Cerrar");
                  break;
        case  1 : longitud = strlen(rutaArchivo);
                  gotoxy(30 - (longitud >> 1) - 1, 1);
                  printf(" %s ", rutaArchivo);
                  gotoxy(3, 2);
                  printf("Archivo\tEdición\tAyuda");
                  gotoxy(3, 24);
                  printf("\033[0;30;47mM:\033[0;0m Abrir Menú\t\033[0;30;47mUp:\033[0;0m Arriba\t\033[0;30;47mEn:\033[0;0m Seleccionar");
                  gotoxy(3, 25);
                  printf("\033[0;30;47mX:\033[0;0m Cerrar\t\033[0;30;47mDn:\033[0;0m Arriba\t\033[0;30;47mSu:\033[0;0m Eliminar");
                  break;
        case  2 :
                  break;
        case  3 :
                  break;
        default :
                  break;
    };

    gotoxy(1, 30);
}

#include "lib1122021.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define gotoxy(__x,__y) printf("\033[%d;%dH", (__y), (__x))

  void marco(int x, int y, char* texto, int alto, int longitud);

void dibujarCuadrado(int modo, char* texto, int alto){
    int longitud = strlen(texto);
    longitud += 4;
    int x = 30 - (longitud >> 1);
    int y = 9;
    marco(x, y, texto, alto, longitud);
    switch(modo){
        case  0     :
                      break;
        case  1     : gotoxy(x + 2, y + alto +1);
                      for (int i = 0; i < longitud; i++) {
                        printf("\033[0;30;47m ");
                      };
                      gotoxy(x + 2, y + alto + 1);
                      //gotoxy(1, 30);
                      break;
        case  2     : gotoxy(x + 2, y + 4);
                      printf("Contacto Número ");
                      gotoxy(x + 2, y + 5);
                      printf("Nombre  :");
                      gotoxy(x + 2, y + 6);
                      printf("Apellido:");
                      gotoxy(x + 2, y + 7);
                      printf("Teléfono:");
                      break;
        case  3     : gotoxy(x + 2, y + 4);
                      printf("Copiar dese :");
                      gotoxy(x + 2, y + 5);
                      printf("A           :");
                      gotoxy(x + 7, y + 7);
                      printf("¿Desea proceder?");
                      gotoxy(x + 11, y + 9);
                      printf("Sí\tNo");
                      break;
        case  4     : gotoxy(x + 2, y + 4);
                      printf("¿Está seguro de realizar esta acción?");
                      gotoxy(x + 11, y + 6);
                      printf("Sí\t\t\tNo");
                      break;
        case  5     : gotoxy(x + 2, y + 4);
                      printf("Ingrese el nombre del propietario");
                      gotoxy(x + 2, y + 6);
                      for (int i = 0; i < longitud; i++) {
                        printf("\033[0;30;47m ");
                      };
                      break;
        case  0x7E  :
                      break;
    };
}






void marco(int x, int y, char* texto, int alto, int longitud){
    gotoxy(x, y);
    printf("┌");
    for (int i = 0; i < longitud + 2; i++) {
      printf("─");
    };
    printf("┐");
    for (int i = 0; i < 1; i++) {
      gotoxy(x, (y+i+1));
      printf("│");
      for (int j = 0; j < longitud + 2; j++) {
        printf(" ");
      };
      printf("│");
    };

    gotoxy(x, y + 2);
    printf("│   %s   │", texto);

    for (int i = 0; i < alto ; i++) {
      gotoxy(x, y + i + 3);
      printf("│");
      for (int j = 0; j < longitud + 2; j++) {
        printf(" ");
      };
      printf("│");
    };
    gotoxy(x, y + alto + 3);
    printf("└");
    for (int i = 0; i < longitud + 2; i++) {
      printf("─");
    };
    printf("┘");
}

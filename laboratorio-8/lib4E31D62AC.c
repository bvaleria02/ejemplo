#include <stdio.h>
#include <stdlib.h>
#include "lib4E31D62AC.h"
#define clear() printf("\033[H\033[J")
#define HL_RED  "\33[38;5;0;48;5;160m"
#define HL_NO     "\33[m"

void gatoDibujarPantalla(char memoria[3][3], int turno){
    char a = 'A';
    char jugador;
    jugador = turno & 0x1;
    switch (jugador){
        case  0 : jugador = 'X';
                  break;
        case  1 : jugador = 'O';
                  break;
    };
    printf("\033[0;32mLaboratorio 8:        \033[0;31mActividad 1\n\033[0;0m");
    printf("------------------------------------\n\n");
    printf("\033[0;33m    1   2   3\033[0;0m\n");
    for (char i = 0; i < 3; i++) {
      printf("\033[0;34m%c: \033[0;0m", (a + i));
      for (size_t j = 0; j < 3; j++) {
        switch (memoria[i][j]){
            case  0 : printf(" - ");
                      break;

            case  1 : printf(" X ");
                      break;

            case  2 : printf(" O ");
                      break;

            case  3 : printf(" ");
                      printf(HL_RED"X");
                      printf(HL_NO" ");
                      break;

            case  4 : printf(" ");
                      printf(HL_RED"O");
                      printf(HL_NO" ");
                      break;

            default :
                      break;
        };
        if (j < 2){
          printf("│");
        };
      };
    if (i < 2){
    printf("\n   ───┼───┼───\n");
      };
    };
    if ((turno & 0x2) == 0x2){
      printf("\n\n\033[0;96mAtención: \033[0;91m¡Jugada Inválida!\033[0;0m");
    } else {
      printf("\n");
    };
    if ((turno & 0x4) == 4){
        printf("\n¡Juego Terminado!\n");
        printf("\033[0;96mHa ganado: ");
          if ((turno & 0x1) == 1){
            printf("\033[0;92mX\n\033[0;0m");
          } else {
            printf("\033[0;92mO\n\033[0;0m");
          };
      } else {
    printf("\nTurno: \033[0;94m%d\033[0;0m - Juega: \033[0;95m%c\033[0;0m", (turno >> 6) + 1, jugador);
    printf("\nIngrese de la forma \033[0;93mfila \033[0;94mcolumna");
      };
  }

int gatoTeclado (char memoria[3][3]){
    char posicion[3] = {0, 0, 0};
    char b = 0;
    int jugada = 0;
    int a = 0;
    do {
      a = 0;
      posicion[0] = 0;
      posicion[1] = 0;
      printf("\n\033[0;96mJugada: \033[0;0m");
      scanf("%2s", posicion);
      //printf("%c %c %d %d\n", posicion[0], posicion[1], posicion[0], posicion[1]);
      if (posicion[0] > 0x40){
        b = posicion[1];
        posicion[1] = posicion[0];
        posicion[0] = b;
      };
      posicion[1] = posicion[1] & 0xDF;
      switch (posicion[0]){
        case '1'  : a = a | 0x0;
                    break;
        case '2'  : a = a | 0x0;
                    break;
        case '3'  : a = a | 0x0;
                    break;
        default   : a = a | 0x1;
        };
      switch (posicion[1]){
        case 'A'  : a = a | 0x0;
                    break;
        case 'B'  : a = a | 0x0;
                    break;
        case 'C'  : a = a | 0x0;
                    break;
        default   : a = a | 0x1;
        };
      //printf("%c %c %d %d %d\n", posicion[0], posicion[1], posicion[0], posicion[1], a);
    } while (a != 0);
    posicion[0] = posicion[0] - 49;
    posicion[1] = posicion[1] - 65;
    jugada = posicion[0] + (posicion[1] << 2);
    return (jugada);
  }

int gatoLogica (char memoria[3][3], int turno, int posicion){
    int jugada[2] = {0, 0};
    int condicion = 0;
    int finalizar = 0;
    jugada[0] = posicion >> 2;
    jugada[1] = posicion & 0x3;
    //printf("\n%x %d %d", posicion, jugada[0], jugada[1]);
    if (memoria[jugada[0]][jugada[1]] != 0){
      turno = turno | 0x2;
    } else {
      memoria[jugada[0]][jugada[1]] = 1 + (turno & 0x1);
      turno = turno ^ 0x1;
      turno = turno + 64;
      turno = turno & 0xFFFD;
    };
      if ((turno & 0x2) != 0x2){
        //printf("X=%d Y=%d Value=%d\n", jugada[0]+1, jugada[1]+1, memoria[jugada[0]][jugada[1]]);
        for (size_t i = 0; i < 8; i++) {
          switch (i){
              case  0 :   // Comprobar arriba-izquierda
                          if (memoria[0][0] == memoria [1][0]){
                              if (memoria[1][0] == memoria[2][0]){
                                  if (memoria[2][0] != 0){
                                    i = 8;
                                    condicion = 0;
                                    finalizar = 1;
                                  };
                              };
                          };
                        break;
              case  1 :   // Comprobar arriba-izquierda
                          if (memoria[0][1] == memoria [1][1]){
                              if (memoria[1][1] == memoria[2][1]){
                                  if (memoria[2][1] != 0){
                                    i = 8;
                                    condicion = 1;
                                    finalizar = 1;
                                  };
                              };
                          };
                        break;
              case  2 :    // Comprobar arriba-izquierda
                          if (memoria[0][2] == memoria [1][2]){
                              if (memoria[1][2] == memoria[2][2]){
                                  if (memoria[2][2] != 0){
                                    i = 8;
                                    condicion = 2;
                                    finalizar = 1;
                                  };
                              };
                          };
                        break;
              case  3 :  // Comprobar arriba-izquierda
                          if (memoria[0][0] == memoria [0][1]){
                              if (memoria[0][1] == memoria[0][2]){
                                  if (memoria[0][2] != 0){
                                    i = 8;
                                    condicion = 3;
                                    finalizar = 1;
                                  };
                              };
                          };
                        break;
              case  4 : // Comprobar arriba-izquierda
                          if (memoria[1][0] == memoria [1][1]){
                              if (memoria[1][1] == memoria[1][2]){
                                  if (memoria[1][2] != 0){
                                    i = 8;
                                    condicion = 4;
                                    finalizar = 1;
                                  };
                              };
                          };
                        break;
              case  5 : // Comprobar arriba-izquierda
                          if (memoria[2][0] == memoria [2][1]){
                              if (memoria[2][1] == memoria[2][2]){
                                  if (memoria[2][2] != 0){
                                    i = 8;
                                    condicion = 5;
                                    finalizar = 1;
                                  };
                              };
                          };
                        break;
              case  6 :   // Comprobar arriba-izquierda
                          if (memoria[0][0] == memoria [1][1]){
                              if (memoria[1][1] == memoria[2][2]){
                                  if (memoria[0][0] != 0){
                                    i = 8;
                                    condicion = 6;
                                    finalizar = 1;
                                  };
                              };
                          };
                        break;
              case  7 :    // Comprobar arriba-izquierda
                          if (memoria[2][0] == memoria [1][1]){
                              if (memoria[1][1] == memoria[0][2]){
                                  if (memoria[2][0] != 0){
                                    i = 8;
                                    condicion = 7;
                                    finalizar = 1;
                                  };
                              };
                          };
                        break;
          };
        };
        turno = turno & 0xFFC5; // limpia todos los bits excepto el 2, 3, 4, 5
        turno = turno + (condicion << 3);
        turno = turno + (finalizar << 2);
        printf("%x", turno);
      };
    return (turno);
  }

void gatoFinal (char memoria[3][3], int turno){
    int metodo = 0;
    metodo = turno >> 3;
    metodo = metodo & 0x7;
    switch(metodo){
        case  0 : memoria[0][0] = 4 - (turno & 0x1);
                  memoria[1][0] = 4 - (turno & 0x1);
                  memoria[2][0] = 4 - (turno & 0x1);
                  break;

        case  1 : memoria[0][1] = 4 - (turno & 0x1);
                  memoria[1][1] = 4 - (turno & 0x1);
                  memoria[2][1] = 4 - (turno & 0x1);
                  break;

        case  2 : memoria[0][2] = 4 - (turno & 0x1);
                  memoria[1][2] = 4 - (turno & 0x1);
                  memoria[2][2] = 4 - (turno & 0x1);
                  break;

        case  3 : memoria[0][0] = 4 - (turno & 0x1);
                  memoria[0][1] = 4 - (turno & 0x1);
                  memoria[0][2] = 4 - (turno & 0x1);
                  break;

        case  4 : memoria[1][0] = 4 - (turno & 0x1);
                  memoria[1][1] = 4 - (turno & 0x1);
                  memoria[1][2] = 4 - (turno & 0x1);
                  break;

        case  5 : memoria[2][0] = 4 - (turno & 0x1);
                  memoria[2][1] = 4 - (turno & 0x1);
                  memoria[2][2] = 4 - (turno & 0x1);
                  break;

        case  6 : memoria[0][0] = 4 - (turno & 0x1);
                  memoria[1][1] = 4 - (turno & 0x1);
                  memoria[2][2] = 4 - (turno & 0x1);
                  break;
        case  7 : memoria[0][2] = 4 - (turno & 0x1);
                  memoria[1][1] = 4 - (turno & 0x1);
                  memoria[2][0] = 4 - (turno & 0x1);
                  break;
    };
  };

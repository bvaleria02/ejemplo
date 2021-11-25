#include <stdio.h>
#include "lib4E31D62AC.h"
#define clear() printf("\033[H\033[J")

int main () {
    char memoria[3][3] = {{0, 0 ,0},
                        {0, 0, 0},
                        {0, 0, 0}};
    int jugada = 0;
    int turno = 0;
    int l = 0;
    while (l == 0){
      clear();
      gatoDibujarPantalla(memoria, turno);
      jugada = gatoTeclado(memoria);
      turno = gatoLogica(memoria, turno, jugada);
      if ((turno & 0x4) >> 2){
        l = 1;
      };
    };
    clear();
    gatoFinal(memoria, turno);
    gatoDibujarPantalla(memoria, turno);
    return 0;
  }

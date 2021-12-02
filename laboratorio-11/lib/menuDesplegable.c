#include "lib1122021.h"

#include <stdio.h>
#include <stdlib.h>
#define gotoxy(__x,__y) printf("\033[%d;%dH", (__y), (__x))

static char* menu_0[] = {"Abrir       ", "Cerrar      ", "Ayuda       ", "Contacto    ", "Añadir      ", "Modificar   ", "Copiar      ", "Eliminar    ", "Borrar todo ", "Propietario "};

void dibujarCaja();
void destacarOpcion();

void menuDesplegable(int seleccion, int submenu_seleccion){
    switch(seleccion){
        case 0  : dibujarCaja(2, 3, 2, 0);
                  destacarOpcion(seleccion, submenu_seleccion);
                  break;
        case 1  : dibujarCaja(16, 3, 6, 1);
                  destacarOpcion(seleccion, submenu_seleccion);
                  break;
        case 2  : dibujarCaja(25, 3, 2, 2);
                  destacarOpcion(seleccion, submenu_seleccion);
                  break;
    };
}

void dibujarCaja(int x, int y, int longitud, int seleccion){
  gotoxy(x, y);
  int desfase = 0;
  switch(seleccion){
      case 0  : desfase = 0;
                break;
      case 1  : desfase = 4;
                break;
      case 2  : desfase = 2;
                break;
  };
  printf("┌────────────┐");
  for (int i = 0; i < longitud; i++) {
    gotoxy(x, y+i+1);
    printf("│%s│", menu_0[i + desfase]);
  };
  gotoxy(x, y+longitud+1);
  printf("└────────────┘");
}

void destacarOpcion(int seleccion, int submenu_seleccion){
    int x = 3;
    int y = 4;
    int desfase = 0;
    y = y + submenu_seleccion;
    switch(seleccion){
        case 0  : x = 3;
                  desfase = 0 + submenu_seleccion;
                  break;
        case 1  : x = 17;
                  desfase = 4 + submenu_seleccion;
                  break;
        case 2  : x = 26;
                  desfase = 2 + submenu_seleccion;
                  break;
    }
    gotoxy(x, y);
    printf("\033[0;30;47m%s\033[0;0m", menu_0[desfase]);
}

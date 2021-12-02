#include <stdio.h>

void  initPantalla(int modo, char* texto);
int   entradaTeclado();
void  menuDesplegable(int seleccion, int submenu_seleccion);
void  dibujarCuadrado(int modo, char *texto, int alto);
void  mostrarContenido(FILE *archivo, int desplazamiento, int seleccion);

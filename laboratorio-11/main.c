#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/lib1122021.h"

#define gotoxy(__x,__y) printf("\033[%d;%dH", (__y), (__x))

  int tecla = 0;
  int main_loop = 1;
  int menu_seleccion = 0;
  int submenu_seleccion[3];
  char rutaArchivo[128] = " ";
  int estado = 0;
  int desplazamiento = 0;
  int seleccion = 0;
  int entradas = 0;
  FILE *archivo;
  int a = 0;

  int  numero        = 0;
  char nombre[24]    = "";
  char apellido[24]  = "";
  long int telefono  = 0;
  char propietario[24]  = "";

  int   __estadoInicial ();
  int   __entradaSeleccion ();
  void  __validacionArchivo ();
  int   __estadoArchivo();
  int   __submenu();

  static char __termtxt[] = ".txt";

int main() {
  while(main_loop){
    main_loop = __estadoInicial();
    switch(main_loop){
      case 2 :  main_loop = 1;
                break;
      case 3 :  estado = __entradaSeleccion();
                main_loop = 0;
                break;
    };
  };
  __validacionArchivo();
  __estadoArchivo();
  return 0;
}

int __estadoInicial (){
  int conditional = 0;
  initPantalla(0, " ");
  while(main_loop){
    tecla = entradaTeclado();
    switch(tecla){
        case 1  : main_loop = 0;
                  break;
        case 2  : main_loop = 0;
                  exit(0);
                  break;
      };
    };
  main_loop = 1;
  while(conditional == 0){
    initPantalla(0, " ");
    conditional = __submenu(0);
  };
  return conditional;
}

int __entradaSeleccion(){
  int estado = 0;
  int globalSeleccion = 0;
  globalSeleccion = (menu_seleccion << 1) + submenu_seleccion[menu_seleccion];
  if (menu_seleccion == 2) globalSeleccion -= 2;
  if (menu_seleccion == 1) globalSeleccion += 2;
  gotoxy(1, 37);
  /*for (int i = 0; i < 200000000; i++) {
    i--;
    i++;
  };*/
  switch(globalSeleccion){
      case 0  : dibujarCuadrado(1, "Ingrese la ruta del archivo", 4);
                scanf("%128s", rutaArchivo);
                printf("\033[0;0m");
                estado = 1;
                break;
      case 1  : gotoxy(1, 30);
                exit(0);
                break;
      case 2  : dibujarCuadrado(0x7E, "      Ayuda      ", 5);
                tecla = entradaTeclado();
                break;
      case 3  : dibujarCuadrado(0x7F, "     Contacto     ", 5);
                tecla = entradaTeclado();
                break;
      case 4  : dibujarCuadrado(2, "         Nuevo Contacto         ", 6);
                gotoxy(30, 13);
                    fseek(archivo, 0, SEEK_SET);
                    fscanf(archivo, "Número de entradas: %i", &numero);
                    printf("%i", numero+1);
                gotoxy(24, 14);
                    scanf("%24s", nombre);
                gotoxy(24, 15);
                    scanf("%24s", apellido);
                gotoxy(24, 16);
                    scanf("%li", &telefono);
                fseek(archivo, 0, SEEK_END);
                fprintf(archivo, "\nID: %i\nNombre: %s\nApellido: %s\nTeléfono: %li\n", numero+1, nombre, apellido, telefono);
                fseek(archivo, 0, SEEK_SET);
                numero++;
                fprintf(archivo, "Número de entradas: %i", numero);
                desplazamiento = 0;
                seleccion = 0;
                break;
      case 5  : dibujarCuadrado(2, "       Modificar Contacto       ", 6);
                fseek(archivo, 0, SEEK_SET);
                fscanf(archivo, "Número de entradas: %i\nPropietario: %s\n ", &numero, propietario);
                a = ftell(archivo);
                for (int i = 0; i < desplazamiento + seleccion; i++) {
                  fseek(archivo, a, SEEK_SET);
                  fscanf(archivo, "ID: %i\nNombre: %s\nApellido: %s\nTeléfono: %li\n\n", &numero, nombre, apellido, &telefono);
                  a = ftell(archivo);
                  if (numero == 0) i--;
                };
                gotoxy(30, 13);
                    printf("%i", desplazamiento + seleccion + 1);
                gotoxy(24, 14);
                    scanf("%24s", nombre);
                gotoxy(24, 15);
                    scanf("%24s", apellido);
                gotoxy(24, 16);
                    scanf("%li", &telefono);
                fprintf(archivo, "ID: %i\nNombre: %s\nApellido: %s\nTeléfono: %li\n", desplazamiento + seleccion + 1, nombre, apellido, telefono);
                fscanf(archivo, "%s", nombre);
                gotoxy(1, 32);
                printf("%s", nombre);
                fseek(archivo, -strlen(nombre) + 1, SEEK_CUR);
                fprintf(archivo, "a");
                tecla = entradaTeclado();
                desplazamiento = 0;
                seleccion = 0;
                break;
      case 6  : dibujarCuadrado(3, "     Copiar Contacto     ", 8);
                gotoxy(32, 13);
                    printf("%i", desplazamiento + seleccion + 1);
                gotoxy(32, 14);
                fseek(archivo, 0, SEEK_SET);
                fscanf(archivo, "Número de entradas: %i\nPropietario: %s\n ", &numero, propietario);
                a = ftell(archivo);
                for (int i = 0; i <= desplazamiento + seleccion; i++) {
                  fseek(archivo, a, SEEK_SET);
                  fscanf(archivo, "ID: %i\nNombre: %s\nApellido: %s\nTeléfono: %li\n\n", &numero, nombre, apellido, &telefono);
                  a = ftell(archivo);
                  if (numero == 0) i--;
                };
                    fseek(archivo, 0, SEEK_SET);
                    fscanf(archivo, "Número de entradas: %i", &numero);
                    printf("%i", numero+1);
                fseek(archivo, 0, SEEK_END);
                fprintf(archivo, "\nID: %i\nNombre: %s\nApellido: %s\nTeléfono: %li\n", numero + 1, nombre, apellido, telefono);
                fseek(archivo, 0, SEEK_SET);
                fprintf(archivo, "Número de entradas: %i", numero+1);
                tecla = entradaTeclado();
                desplazamiento = 0;
                seleccion = 0;
                break;
      case 7  : dibujarCuadrado(4, "         Eliminar Contacto         ", 4);
                fseek(archivo, 0, SEEK_SET);
                fscanf(archivo, "Número de entradas: %i\nPropietario: %s\n ", &numero, propietario);
                a = ftell(archivo);
                for (int i = 0; i < desplazamiento + seleccion +1; i++) {
                  a = ftell(archivo);
                  fscanf(archivo, "ID: %i\nNombre: %s\nApellido: %s\nTeléfono: %li\n\n", &numero, nombre, apellido, &telefono);
                  if (numero == 0) i--;
                };
                fseek(archivo, a, SEEK_SET);
                fprintf(archivo, "ID: 0\nNombre: %s\nApellido: %s\nTeléfono: %li\n", nombre, apellido, telefono);
                fseek(archivo, 0, SEEK_SET);
                fscanf(archivo, "Número de entradas: %i", &numero);
                fseek(archivo, 0, SEEK_SET);
                fprintf(archivo, "Número de entradas: %i", numero -1);
                tecla = entradaTeclado();
                desplazamiento = 0;
                seleccion = 0;
                break;
      case 8  : dibujarCuadrado(4, "           Eliminar Todo           ", 4);
                tecla = entradaTeclado();
                fclose(archivo);
                archivo = fopen(rutaArchivo, "w+");
                fprintf(archivo, "Número de entradas: 0\nPropietario: sin-nombre\n");
                desplazamiento = 0;
                seleccion = 0;
                break;
      case 9  : dibujarCuadrado(5, "         Propietario         ", 4);
                scanf("%24[^\n]s", propietario);
                fseek(archivo, 0, SEEK_SET);
                fscanf(archivo, "Número de entradas: %i\nPropietario: ", &numero);
                fprintf(archivo, "%s", propietario);
                tecla = entradaTeclado();
                break;
  };
  return estado;
}

void __validacionArchivo (){
    int terminacion = 0;
    int longitudNombre = strlen(rutaArchivo);
    for (int i = 0; i < 5; i++) {
      if(rutaArchivo[longitudNombre - 4 + i] != __termtxt[i]) terminacion = terminacion | 0x1;
    };
    if (terminacion == 1){
        for (int i = 0; i < 5; i++) {
          rutaArchivo[longitudNombre + i] = __termtxt[i];
        };
    };
    archivo = fopen(rutaArchivo, "r+");
    if (archivo == NULL) {
      archivo = fopen(rutaArchivo, "w+");
      fprintf(archivo, "Número de entradas: 0\nPropietario: sin-nombre");
    };
}

int __estadoArchivo(){
  int estado = 0;
  main_loop = 1;
  fscanf(archivo, "Número de entradas: %i", &entradas);
  initPantalla(1, rutaArchivo);
  mostrarContenido(archivo, 0, 0);
  while(main_loop){
    fseek(archivo, 0, SEEK_SET);
    fscanf(archivo, "Número de entradas: %i", &entradas);
    entradas--;
    gotoxy(1, 30);
    tecla = entradaTeclado();
    switch(tecla){
        case  1 : while(main_loop){
                      initPantalla(1, rutaArchivo);
                      mostrarContenido(archivo, desplazamiento, seleccion);
                      estado = __submenu(1);
                      if (estado == 3) main_loop = 0;
                  };
                  estado = __entradaSeleccion();
                  main_loop = 1;
                  break;
        case  2 : exit(0);
                  break;
        case  3 : if ((desplazamiento + seleccion) >= 5 && entradas > 5) desplazamiento -= 6;
                  if ((desplazamiento + seleccion) < 5) desplazamiento = 0;
                  break;
        case  4 : if ((desplazamiento + seleccion) < (entradas - 6) && entradas > 5) desplazamiento += 6;
                  break;
        case  5 : if ((desplazamiento + seleccion) > 0        && seleccion == 0) desplazamiento--;
                  if ((desplazamiento + seleccion) > 0  && seleccion > 0 ) seleccion--;
                  break;
        case  6 : if ((desplazamiento + seleccion) < entradas - 3  && seleccion > 2 && entradas > 5 && (desplazamiento + 7) <= entradas) desplazamiento++;
                  if ((desplazamiento + seleccion) >= entradas -3 && seleccion < 5 && (desplazamiento + seleccion) < entradas - 1 && entradas > 3) seleccion++;
                  if ((desplazamiento + seleccion) < entradas - 3 && seleccion <= 2 && entradas > 3) seleccion++;
                  if ((desplazamiento + seleccion) < entradas    && seleccion <= 2 && entradas < 3) seleccion++;
                  break;
        };
        initPantalla(1, rutaArchivo);
        mostrarContenido(archivo, desplazamiento, seleccion);
  };
  return estado;
}

int __submenu(int modo){
  int conditional = 0;
    menuDesplegable(menu_seleccion, submenu_seleccion[menu_seleccion]);
    tecla = entradaTeclado();
    switch(modo){
        case 0  : switch(tecla){
                      case 1  : main_loop = 0;
                                conditional = 2;
                                break;
                      case 2  : main_loop = 0;
                                exit(0);
                                break;
                      case 3  : if (menu_seleccion != 0) menu_seleccion = 0;
                                break;
                      case 4  : if (menu_seleccion != 1) menu_seleccion = 2;
                                break;
                      case 5  : if (submenu_seleccion[menu_seleccion] != 0) submenu_seleccion[menu_seleccion]--;
                                break;
                      case 6  : if (submenu_seleccion[menu_seleccion] != 2) submenu_seleccion[menu_seleccion]++;
                                break;
                      case 7  : main_loop = 0;
                                conditional = 3;
                              };
                      break;
        case 1  : switch(tecla){
                      case 1  : main_loop = 0;
                                conditional = 2;
                                break;
                      case 2  : main_loop = 0;
                                exit(0);
                                break;
                      case 3  : if (menu_seleccion != 0) menu_seleccion--;
                                break;
                      case 4  : if (menu_seleccion != 2) menu_seleccion++;
                                break;
                      case 5  : if (submenu_seleccion[menu_seleccion] != 0) submenu_seleccion[menu_seleccion]--;
                                break;
                      case 6  : if (submenu_seleccion[menu_seleccion] != 1 && menu_seleccion != 1) submenu_seleccion[menu_seleccion]++;
                                if (submenu_seleccion[menu_seleccion] < 5 && menu_seleccion == 1) submenu_seleccion[menu_seleccion]++;
                                break;
                      case 7  : main_loop = 0;
                                conditional = 3;
                              };
                      break;
    };

  return conditional;
}

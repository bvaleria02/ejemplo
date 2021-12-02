#include "lib1122021.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define gotoxy(__x,__y) printf("\033[%d;%dH", (__y), (__x))

void mostrarContenido(FILE *archivo, int desplazamiento, int seleccion){
    int  numero        = 0;
    char nombre[24]    = "";
    char apellido[24]  = "";
    long int telefono  = 0;

    int  entradas       = 0;
    char propietario[24]= "";
    int  a = 0;

  fseek(archivo, 0, SEEK_SET);
  fscanf(archivo, "Número de entradas: %i\nPropietario: %s\n ", &entradas, propietario);
  if (entradas == 0) return;
  a = ftell(archivo);
  for (int i = 0; i < desplazamiento; i++) {
    fseek(archivo, a, SEEK_SET);
    fscanf(archivo, "ID: %i\nNombre: %s\nApellido: %s\nTeléfono: %li\n", &numero, nombre, apellido, &telefono);
    a = ftell(archivo);
    if (numero == 0) i--;
  };
  for (int i = 0; i < 6; i++) {
    numero = 0;
    while(numero==0){
      fscanf(archivo, "ID: %i\nNombre: %s\nApellido: %s\nTeléfono: %li\n", &numero, nombre, apellido, &telefono);
    };
    gotoxy(3, 4+(i * 3));
    printf("\t%d\t%s %s", numero, nombre, apellido);
    gotoxy(7, 5+(i * 3));
    printf("+%li", telefono);
    a = ftell(archivo);
    if (feof(archivo)) i = 20;
    };
  gotoxy(3, 4+(seleccion * 3));
  printf(">");
}

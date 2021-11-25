#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
    int valor_a = 0;
    int valor_b = 0;
    if (argc < 3){
      printf("la función espera 2 parámetros y ha ingresado %d.\n", argc - 1);
    } else {
      valor_a = atoi(argv[1]);
      valor_b = atoi(argv[2]);
      int resultado = valor_a + valor_b;
      printf("La suma de %d y %d es %d.\n", valor_a, valor_b, resultado);
    };
    return 0;
}

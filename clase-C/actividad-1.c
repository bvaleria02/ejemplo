#include <stdio.h>

static int numeros[] = {13, 69, 420, 666, 1337, 2550, 7777, 10000, 123412, 1235412345, 12342, 23123, 12312, 0xFFFFFFFF};

int sumaArreglo(int *numeros);

int main() {
    int resultado = 0;
    resultado = sumaArreglo(numeros);
    printf("La suma de los números es :%i\n", resultado);
    return 0;
}

int sumaArreglo (int *numeros){
  int longitud = 0;
  int resultado = 0;
  int i = 1;
  while (i != 0){
    if (numeros[i - 1] == 0xFFFFFFFF){
      i = 0;
    } else {
      resultado = resultado + numeros[i - 1];
      i++;
    };
  };
  return resultado;
}

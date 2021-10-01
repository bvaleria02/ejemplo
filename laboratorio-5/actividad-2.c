#include <stdio.h>

int main(){
      char Caracter = 0;
      printf("\033[0;32mLaboratorio 5:        \033[0;31mActividad 2\n\033[0;0m");
      printf("------------------------------------\n\n");
      printf("Ingrese el caracter que desea visualizar su valor:\n\033[0;36mCaracter = \033[0;0m");
      scanf("%c", &Caracter);
      printf("\nEl caracter escogido es \033[0;36m%c\033[0m, cual...\n", Caracter);
      printf("\tSegún la tabla ASCII corresponde al número \033[0;34m%d\033[0;0m.\n", Caracter);
      printf("\tCual a su vez equivale en hexadecimal a \033[0;35m0x%X\033[0;0m.\n", Caracter);
      return 0;
}

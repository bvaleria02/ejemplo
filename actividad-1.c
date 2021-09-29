#include <stdio.h>

int main(){
      int Numero_1 = 0;
      int Numero_2 = 0;
      int Suma = 0;
      printf("\033[0;32mLaboratorio 5:        \033[0;31mActividad 1\n\033[0;0m");
      printf("------------------------------------\n\n");
      printf("Ingrese el valor del primer número:\n\033[0;36mA = \033[0;0m");
      scanf("%d", &Numero_1);
      printf("\nIngrese el valor del segundo número:\n\033[0;36mB = \033[0;0m");
      scanf("%d", &Numero_2);
      Suma = Numero_1 + Numero_2;
      printf("\nEl resultado de la suma entre \033[0;36m%d\033[0;0m y \033[0;36m%d\033[0;0m es: \033[0;32m%d\033[0;0m\n", Numero_1, Numero_2, Suma);
      return 0;
}

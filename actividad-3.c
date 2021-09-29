#include <stdio.h>

int main(){
      float Numero_1 = 0;
      float Numero_2 = 0;
      float Resultado = 0;
      printf("\033[0;32mLaboratorio 5:        \033[0;31mActividad 3\n\033[0;0m");
      printf("------------------------------------\n\n");
      printf("Ingrese el valor de ambos números, \033[0;31mseparados por un espacio:\033[0;36m\nA, B = \033[0;0m");
      scanf("%f %f", &Numero_1 &Numero_2);
      Resultado = Numero_1 * Numero_2;
      printf("\nEl valor de la multiplicación de \033[0;36m%.2f\033[0;0m y \033[0;36m%.2f\033[0;0m es \033[0;32m%.2f\033[0;0m" Numero_1, Numero_2, Resultado);
      return 0;
}

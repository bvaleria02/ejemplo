#include <stdio.h>

int main(){
      float Radio = 0;
      float Pi = 3.14159265;
      float Resultado = 0;
      printf("\033[0;32mLaboratorio 5:        \033[0;31mActividad 4\n\033[0;0m");
      printf("------------------------------------\n\n");
      printf("Ingrese el valor del radio de la circunferencia\n\033[0;36mA = \033[0;0m");
      scanf("%f", &Radio);
      Resultado = Radio * Radio * Pi;
      printf("\nEl perímetro de la circunferencia de radio \033[0;36m%.2f\033[0;0m es: \033[0;32m%.6f\033[0;0m\n", Radio, Resultado);
      return 0;
}

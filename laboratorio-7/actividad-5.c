#include <stdio.h>

int main (){
  int A = 0;
  int sumatoria = 0;
  int i = 0;
  printf("\033[0;32mLaboratorio 7:        \033[0;31mActividad 5\n\033[0;0m");
  printf("------------------------------------\n\n");
  do {
    printf("Ingrese un \033[0;34mnúmero\033[0;0m para añadir a la sumatoria\n\033[0;36mA = \033[0;0m");
    scanf("%d", &A);
    printf("\n");
    if (A < 0){
      i = 1;
      sumatoria += A;
    } else {
      sumatoria += A;
    };
  } while(i == 0);
  printf("La sumatoria es \033[0;32m%d\033[0;0m", sumatoria);
  return (0);
}

#include <stdio.h>

int main (){
  long a = 1;
  long b = 0;
  int c = 0;
  long d = 0;
  printf("\033[0;32mLaboratorio 7:        \033[0;31mActividad 6\n\033[0;0m");
  printf("------------------------------------\n\n");
  printf("Ingrese la cantidad de \033[0;34melementos\033[0;0m para obtener la suceción\n\033[0;36mIteraciones = \033[0;0m");
  scanf("%d", &c);
  printf("\n\033[0;33mFibonacci:\033[0;0m\n");
  for (int i = 0; i < c; i++) {
    d = b + a;
    b = a;
    a = d;
    printf("\t\033[0;32m%d-\t\033[0;34m|\033[0;0m\t%ld\n", i+1, d);
  };
  return(0);
}

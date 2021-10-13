#include <stdio.h>

int main(){
      int Numero = 0;
      printf("\033[0;32mLaboratorio 7:        \033[0;31mActividad 1\n\033[0;0m");
      printf("------------------------------------\n\n");
      for (int i = 0; i < 10; i++) {
        printf("\033[0;33m%d\t|\033[0;0m\t", Numero << 1);
        for (int j = 0; j < 5; j++) {
        printf("%d\t", Numero << 1);
        Numero++;
      };
      printf("\n");
      };
      printf("\033[0;33m100\t|\033[0;0m\t100\n");
      return 0;
}

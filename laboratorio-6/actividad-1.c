#include <stdio.h>

int main(){
      int Numero = 0;
      int Impar = 0;
      printf("\033[0;32mLaboratorio 6:        \033[0;31mActividad 1\n\033[0;0m");
      printf("------------------------------------\n\n");
      printf("Ingrese un número entero:\n\033[0;36mNúmero = \033[0;0m");
      scanf("%d", &Numero);
      Impar = Numero & 0x01;
      switch (Impar) {
        case 0:   printf("\nEl número \033[0;36m%d\033[0;0m es \033[0;32mpar\033[0;0m.", Numero);
                  break;
        case 1:   printf("\nEl número \033[0;36m%d\033[0;0m es \033[0;34mimpar\033[0;0m.", Numero);
                  break;
        default:  printf("\n\033[0;31mComportamiendo imprevisto\033[0;0m.\nPor favor \033[0;33mreportar este fallo\033[0;0m.");
      }
      return 0;
}

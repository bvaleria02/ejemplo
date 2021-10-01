#include <stdio.h>

int main(){
      int Numero_1 = 0;
      int Numero_2 = 0;
      int Suma = 0;
      printf("Ingrese ambos números \033[0;31muno detrás del otro:\n\033[0;36mA = \033[0;0m");
      scanf("%d", &Numero_1);
      printf("\033[0;36mB = \033[0;0m");
      scanf("%d", &Numero_2);
      if (Numero_2 == 1) {
        Suma = Numero_1 + 1;
        printf("La suma de \033[0;36m%d\033[0;0m y \033[0;36m%d\033[0;0m es: \033[0;32m%d\033[0;0m", Numero_1, Numero_2, Suma);
      } else {
      printf("El segundo número \033[0;31mno es 1\033[0;0m\nEl valor de la suma es \033[0;32m%d\033[0;0m", Numero_1);
      };
      return 0;
}

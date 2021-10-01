#include <stdio.h>

int main(){
      int Numero_1 = 0;
      int Numero_2 = 0;
      printf("Ingrese ambos números \033[0;31muno detrás del otro:\n\033[0;36mA = \033[0;0m");
      scanf("%d", &Numero_1);
      printf("\033[0;36mB = \033[0;0m");
      scanf("%d", &Numero_2);
      if (Numero_2 > Numero_1) {
        printf("\033[0;36m%d\033[0;0m es mayor que \033[0;36m%d\033[0;0m", Numero_2, Numero_1);
      } else  if (Numero_2 == Numero_1){
        printf("\033[0;36m%d\033[0;0m es igual a \033[0;36m%d\033[0;0m", Numero_1, Numero_2);
      } else {
        printf("\033[0;36m%d\033[0;0m es mayor que \033[0;36m%d\033[0;0m", Numero_1, Numero_2);
    };
      return 0;
}

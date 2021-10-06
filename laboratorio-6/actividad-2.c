#include <stdio.h>

int main(){
      int Numero_1 = 0;
      int Numero_2 = 0;
      int Numero_3 = 0;
      int Acumulador_1 = 0;
      int Acumulador_2 = 0;
      int Resultado = 0;
      printf("\033[0;32mLaboratorio 6:        \033[0;31mActividad 2\n\033[0;0m");
      printf("------------------------------------\n\n");
      printf("Comparador de \033[0;34mtres\033[0;0m números\n");
      printf("Ingrese el \033[0;36mprimer número:\033[0;0m ");
      scanf("%d", &Numero_1);
      printf("Ingrese el \033[0;36msegundo número:\033[0;0m ");
      scanf("%d", &Numero_2);
      printf("Ingrese el \033[0;36mtercer número:\033[0;0m ");
      scanf("%d", &Numero_3);
      printf("\n");
      Acumulador_1 = Numero_1 - Numero_2 + Numero_3;
      if (Acumulador_1 < 0) {
        Resultado = 2;
      };
      Acumulador_1= Numero_1 - Numero_3;
      if (Acumulador_1 < 0){
        Resultado = 3;
      } else if (Numero_1 == Numero_3) {
        Resultado = 4;
      };
      switch (Resultado) {
        case 0: printf("Número \033[0;32m1 es mayor\033[0;0m");
                break;
        case 2: printf("Número \033[0;32m2 es mayor\033[0;0m");
                break;
        case 3: printf("Número \033[0;32m3 es mayor\033[0;0m");
                break;
        case 4: printf("Los \033[0;34mtres son iguales\033[0;0m");
                break;
      }
      return 0;
}

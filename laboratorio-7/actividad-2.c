#include <stdio.h>

int main(){
      int x = 0;
      int y = 0;
      int resultado = 0;
      int a = 0;
      int i = 0;
      const int bits = 32;
      printf("\033[0;32mLaboratorio 7:        \033[0;31mActividad 2\n\033[0;0m");
      printf("------------------------------------\n\n");
      printf("Ingrese dos números para multiplicar de la forma \033[0;31mX Y:\033[0;0m\n\033[0;36mFactores = \033[0;0m");
      scanf("%d %d", &x, &y);
      printf("\nSeleccione el \033[0;34malgoritmo\033[0;0m a utilizar:\n");
      printf("\033[0;33m\t1- Multiplicación por operador.\n\t2- Suma iterada.\n\t3- Manipulación de bits.\n\n\033[0;36mAlgoritmo: \033[0;0m");
      while (i == 0){
          scanf("%d", &a);
          switch (a) {
              case 1  : i = 1;
                        break;
              case 2  : i = 1;
                        break;
              case 3  : i = 1;
                        break;
              default : i = 0;
                        printf("\n\033[0;31m¡Valor Incorrecto!\033[0;0m\nSeleccione el \033[0;34malgoritmo\033[0;0m a utilizar:\n\033[0;36mAlgoritmo = \033[0;0m");
              };
      };
      switch (a) {
          case  1 : resultado = x * y;
                    break;
          case  2 : for (int i = 0; i < y; i++) {
                      resultado += x;
                    };
                    break;
          case  3 : for (int i = 0; i < bits; i++) {
                        a = y >> i;
                        a = a & 0x1;
                        switch (a){
                            case  0 : break;
                            case  1 : a = x << i;
                                      resultado = resultado + a;
                                      break;
                    };};
                    break;
      };
      printf("\nEl resultado de multiplicar \033[0;36m%d\033[0;0m con \033[0;36m%d\033[0;0m es: \033[0;32m%d\033[0;0m", x, y,resultado);
      return 0;
}

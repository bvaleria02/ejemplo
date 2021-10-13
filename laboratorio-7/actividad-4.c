#include <stdio.h>

int main(){
    int a = 0;
    int b = 2;
    int c = 2;
    int d = 0;
    int i = 2;
    printf("\033[0;32mLaboratorio 7:        \033[0;31mActividad 4\n\033[0;0m");
    printf("------------------------------------\n\n");
    printf("Ingrese un \033[0;34mnúmero\033[0;0m para mostrar los primos antes de este:\n\033[0;36mNúmero = \033[0;0m");
    scanf("%d", &a);
    printf("Los números primos antes de \033[0;36m%d\033[0;0m son:\n", a);
    while (b < a){
      while (c < b){
        d = b / c;
        d = d * c;
        if (d == b) {
          c = b + 1;
        };
        c++;
      };
      if (c == b){
        printf("%d\t", b);
      };
      c = 2;
      b++;
    };
}

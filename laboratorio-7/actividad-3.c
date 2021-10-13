#include <stdio.h>

int main(){
    int a = 0;
    //int b = 0;
    int c = 0;
    int d = 0;
    int i = 2;
    printf("\033[0;32mLaboratorio 7:        \033[0;31mActividad 3\n\033[0;0m");
    printf("------------------------------------\n\n");
    printf("Ingrese un \033[0;34mnúmero\033[0;0m para mostrar sus \033[0;0mdivisores\033[0;36m\nNúmero = \033[0;0m");
    scanf("%d", &a);
    // b = a/2 + 1;
    switch(a){
        case  0 : printf("\033[0;31mNo se puede dividir por 0\033[0;0m");
                  break;
        default : printf("Los divisores de \033[0;36m%d\033[0;0m son:\n", a);
                  //while (i < b){
                  while (i <= a){
                  c = a/i;
                  d = c*i;
                  if (d == a){
                      printf("%d\t", i);
                      i++;
                     } else {
                      i++;
                      };
    };};
    return 0;
}

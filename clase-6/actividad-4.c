#include <stdio.h>

int main(){
      int Numero = 0;
      printf("Texto de ejemplo\n\033[0;36mNota = \033[0;0m");
      scanf("%d", &Numero);
      switch (Numero){
        case 1: printf("lol");
                break;
        case 2: printf("xd");
                break;
        case 3: printf("jaja");
                break;
        default: printf("Sí");
      }
      return 0;
}

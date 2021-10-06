#include <stdio.h>

int main(){
      long variable_rut = 0;
      long rut_predefinido = 20990223;
      int Acumulador = 0;
      int Contador = 3;
      printf("\033[0;32mLaboratorio 6:        \033[0;31mActividad 3\n\033[0;0m");
      printf("------------------------------------\n\n");
      while (Contador > 0){
          printf("------------------------------------\n");
          printf("Ingrese su \033[0;33mclave\033[0;0m\nIntentos restantes: \033[0;32m%d\033[0;0m\n\033[0;36mclave = \033[0;0m", Contador);
          scanf("%ld", &variable_rut);
          if (variable_rut == rut_predefinido){
              Contador = 0;
              Acumulador = 1;
              } else {
                  Contador -= 1;
                  printf("\n\033[0;31mClave incorrecta\033[0;0m\n");
                  };
            }
      printf("------------------------------------\n");
      switch (Acumulador){
          case 0: printf("\033[0;31mSe le ha bloqueado el acceso\033[0;0m");
                  break;
          case 1: printf("\033[0;32mAcceso autorizado\033[0;0m\n¡Bienvenido!\n");
                  break;

      };
      return 0;
}
